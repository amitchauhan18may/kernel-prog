/*
 *
switch: amit-gpio {
	status = "okay";
	compatible = "amit-gpio-keys";
	button1-gpio = <&gpio_a 30 0>;
	led1-gpio = <&gpio_a 28 0>;
	button2-gpio = <&gpio_b 0 0>;
	led2-gpio = <&gpio_b 6 0>;
};

 * */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/input.h>
#include <linux/version.h>
#include <linux/reboot.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/delay.h>        /* for msleep() */
#include <linux/timer.h>        /* for timers apis */
#include <linux/of_gpio.h>
#include <linux/kthread.h>
#include <linux/wait.h>

DECLARE_WAIT_QUEUE_HEAD(input_event_wq);
int evq_flag = 0;

static struct task_struct *ewq_thread;

enum events {
	BTN1_PRESS = 0x04,
	BTN2_PRESS = 0x05,
	BTN1_LONG_PRESS = 0x06,
	BTN2_LONG_PRESS = 0x07,
	BTN1_2_LONG_PRESS = 0x08
};

static unsigned int irqNumber1;
static bool ledOn1;
static bool reset_flag1;

static unsigned int irqNumber2;
static bool ledOn2;
static bool reset_flag2;
static bool bt1_long, bt2_long;
struct artik_switch {
	int gpioButton1, gpioLED1, gpioButton2, gpioLED2;
};

/* For DT*/
/* For platform devices */
/* For GPIO Descriptor interface */
struct btn_data {
        struct input_dev *i_dev;
        struct platform_device *pdev;
	struct artik_switch *artik_switch;
};

static unsigned long flags;
unsigned long IRQflags = IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING;

static struct timer_list long_press_timer1;
static struct timer_list long_press_timer2;

static DEFINE_SPINLOCK(data_lock);

static int evq_thread_function (void *dev) {

	struct btn_data *priv = dev_get_drvdata(dev);

	while (1) {
		pr_info("AMIT: Waiting for event\n");
		wait_event_interruptible(input_event_wq, evq_flag != 0);
		pr_info("AMIT: Event came from exit function\n");
		if (evq_flag) {
			input_event(priv->i_dev, EV_KEY, BTN_3, BTN1_2_LONG_PRESS);
			input_sync(priv->i_dev);
			input_event(priv->i_dev, EV_KEY, BTN_3, 0 & BTN1_LONG_PRESS);
			input_sync(priv->i_dev);
			pr_info("AMIT: Inside IF Event came from exit function\n");
#if 0
			if (bt1_long) {
				input_event(priv->i_dev, EV_KEY, BTN_1, 0 & BTN1_LONG_PRESS);
				input_sync(priv->i_dev);
				pr_info("AMIT: Inside IF Button1 long press\n");
				input_event(priv->i_dev, EV_KEY, BTN_1, BTN1_LONG_PRESS);
				input_sync(priv->i_dev);
				bt1_long = false;
			}
			
			if (bt2_long) {
				input_event(priv->i_dev, EV_KEY, BTN_2, 0 & BTN2_LONG_PRESS);
				input_sync(priv->i_dev);
				pr_info("AMIT: Inside IF Button2 long press\n");
				input_event(priv->i_dev, EV_KEY, BTN_2, BTN2_LONG_PRESS);
				input_sync(priv->i_dev);
				bt2_long = false;
			}
#endif
			pr_info("AMIT: Inside IF\n");
			
		}

		evq_flag = 0;
		pr_info("AMIT: Setting evq_flag %d\n", evq_flag);
	}

        do_exit(0);
        return 0;

}

void long_press_timer_callback2(unsigned long data)
{

	spin_lock(&data_lock);
	if (reset_flag1 && reset_flag2) {
		pr_info("AMIT: LONGPRESS callback2 detected\n");
		evq_flag = 1;
		bt2_long = true;
		wake_up_interruptible(&input_event_wq);
	}
	spin_unlock(&data_lock);
}

static irqreturn_t button2_irq_handler(int irq, void *dev_id)
{
	uint8_t value;
	struct btn_data *priv = dev_id;

	local_irq_save(flags);
	value = gpio_get_value(priv->artik_switch->gpioButton2);
	if (value == 0) {
		pr_info("AMIT: Button2 pressed\n");
		reset_flag2 = true;
		/* Invert the LED state on each button press */
		ledOn2 = !ledOn2;
		gpio_set_value(priv->artik_switch->gpioLED2, ledOn2);

		input_event(priv->i_dev, EV_KEY, BTN_2, BTN2_PRESS);
		input_sync(priv->i_dev);

		/* Timer Started on BUtton press for time 4 seconds */
		mod_timer(&long_press_timer2, jiffies + msecs_to_jiffies(2000));
	} else if (value) {
		input_event(priv->i_dev, EV_KEY, BTN_2, 0 & BTN2_PRESS);
		input_sync(priv->i_dev);
		reset_flag2 = false;
		if (timer_pending(&long_press_timer2))
			del_timer(&long_press_timer2);
	}
	local_irq_restore(flags);

	return IRQ_HANDLED;
}

static int gpioled2_setup(struct device *dev)
{
	int ret = 0;
	struct platform_device *pdev = to_platform_device(dev);
	struct btn_data *priv = dev_get_drvdata(dev);
	
	/* Is the GPIO a valid GPIO number */
	if (!gpio_is_valid(priv->artik_switch->gpioLED2)) {
		dev_err(&pdev->dev, "gpio is invalid for led2\n");
		return -ENODEV;
	}

	/* Going to set up the LED */
	ledOn2 = true;

	/* GPIOs must be allocated before use */
	ret = gpio_request(priv->artik_switch->gpioLED2, "sysfs");
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d request failed with error : %d\n",
				priv->artik_switch->gpioLED2, ret);
		return ret;
	}

	ret = gpio_direction_output(priv->artik_switch->gpioLED2, ledOn2);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d failed to set in output mode with error : %d\n", priv->artik_switch->gpioLED2, ret);
		goto gpioLED2_free;
	}

	/* GPIO subsystem create a sysfs entry under /sys/class/gpio */
	ret = gpio_export(priv->artik_switch->gpioLED2, false);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d export failed with error : %d\n",
				priv->artik_switch->gpioLED2, ret);
		goto gpioLED2_free;
	}
	
	return ret;

gpioLED2_free:
	gpio_free(priv->artik_switch->gpioLED2);
	return ret;

}

static int  button2_interrupt_config(struct device *dev)
{
	int ret = 0;
	struct platform_device *pdev = to_platform_device(dev);
	struct btn_data *priv = dev_get_drvdata(dev);

	/* the bool argument prevents the direction from being changed */
	ret = gpio_request(priv->artik_switch->gpioButton2, "sysfs");
	if (ret < 0) {
		dev_err(&pdev->dev, "gpiobutton %d request failed with error : %d\n",
				priv->artik_switch->gpioButton2, ret);
		gpio_free(priv->artik_switch->gpioLED2);
		return ret;
	}

	ret = gpio_direction_input(priv->artik_switch->gpioButton2);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioButton1 %d failed to set in input mode : %d\n",
				priv->artik_switch->gpioButton2, ret);
		goto gpioButton2_free;
	}
	ret = gpio_export(priv->artik_switch->gpioButton2, false);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioButton1 %d failed to export with error : %d\n",
				priv->artik_switch->gpioButton2, ret);
		goto gpioButton2_free;
	}

	/* Debounce the button with a delay of 200ms */
	gpio_set_debounce(priv->artik_switch->gpioButton2, 200);

	irqNumber2 = gpio_to_irq(priv->artik_switch->gpioButton2);
	ret = request_irq(irqNumber2, (irq_handler_t) button2_irq_handler,
			IRQflags, "button2_handler", priv);
	if (ret != 0) {
		dev_err(&pdev->dev, "Irq Request failure : %d\n", ret);
		goto gpioButton2_free;
	}
	
	return ret;

gpioButton2_free:
	gpio_unexport(priv->artik_switch->gpioLED2);
	gpio_free(priv->artik_switch->gpioLED2);
	gpio_free(priv->artik_switch->gpioButton2);
	return ret;

}

void long_press_timer_callback1(unsigned long data)
{
	spin_lock(&data_lock);
	if (reset_flag1 && reset_flag2) {
		pr_info("AMIT: LONGPRESS detected callback 1\n");
		evq_flag = 1;
		bt1_long = true;
		wake_up_interruptible(&input_event_wq);
	}
	spin_unlock(&data_lock);
}

static irqreturn_t button1_irq_handler(int irq, void *dev_id)
{
	uint8_t value;
	struct btn_data *priv = dev_id;

	local_irq_save(flags);
	value = gpio_get_value(priv->artik_switch->gpioButton1);
	if (value == 0) {
		pr_info("AMIT: Button1 pressed\n");
		reset_flag1 = true;
		ledOn1 = !ledOn1;
		input_event(priv->i_dev, EV_KEY, BTN_1, BTN1_PRESS);
		input_sync(priv->i_dev);
		gpio_set_value(priv->artik_switch->gpioLED1, ledOn1);
		mod_timer(&long_press_timer1, jiffies + msecs_to_jiffies(2000));
	} else if (value) {
		input_event(priv->i_dev, EV_KEY, BTN_1, 0 & BTN1_PRESS);
		input_sync(priv->i_dev);
		reset_flag1 = false;
		if (timer_pending(&long_press_timer1))
			del_timer(&long_press_timer1);
	}
	local_irq_restore(flags);
	
	return IRQ_HANDLED;
}

static int gpioled1_setup(struct device *dev)
{

	int ret = 0;
	struct platform_device *pdev = to_platform_device(dev);
	struct btn_data *priv = dev_get_drvdata(dev);
	
	/* Is the GPIO a valid GPIO number */
	if (!gpio_is_valid(priv->artik_switch->gpioLED1)) {
		dev_err(&pdev->dev, "gpio is invalid for led1\n");
		return -ENODEV;
	}

	/* Going to set up the LED */
	ledOn1 = true;

	/* GPIOs must be allocated before use */
	ret = gpio_request(priv->artik_switch->gpioLED1, "sysfs");
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d request failed with error : %d\n",
				priv->artik_switch->gpioLED1, ret);
		return ret;
	}

	ret = gpio_direction_output(priv->artik_switch->gpioLED1, ledOn1);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d failed to set in output mode with error : %d\n", priv->artik_switch->gpioLED1, ret);
		goto gpioLED1_free;
	}

	/* GPIO subsystem create a sysfs entry under /sys/class/gpio */
	ret = gpio_export(priv->artik_switch->gpioLED1, false);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioLED1 %d export failed with error : %d\n",
				priv->artik_switch->gpioLED1, ret);
		goto gpioLED1_free;
	}
	
	return ret;

gpioLED1_free:
	gpio_free(priv->artik_switch->gpioLED1);
	return ret;

}

static int  button1_interrupt_config(struct device *dev)
{

	int ret = 0;
	struct platform_device *pdev = to_platform_device(dev);
	struct btn_data *priv = dev_get_drvdata(dev);

	ret = gpio_request(priv->artik_switch->gpioButton1, "sysfs");
	if (ret < 0) {
		dev_err(&pdev->dev, "gpiobutton %d request failed with error : %d\n",
				priv->artik_switch->gpioButton1, ret);
		gpio_free(priv->artik_switch->gpioLED1);
		return ret;
	}
	ret = gpio_direction_input(priv->artik_switch->gpioButton1);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioButton1 %d failed to set in input mode : %d\n",
				priv->artik_switch->gpioButton1, ret);
		goto gpioButton1_free;
	}

	ret = gpio_export(priv->artik_switch->gpioButton1, false);
	if (ret < 0) {
		dev_err(&pdev->dev, "gpioButton1 %d failed to export with error : %d\n",
				priv->artik_switch->gpioButton1, ret);
		goto gpioButton1_free;
	}

	/* Debounce the button with a delay of 200ms */
	gpio_set_debounce(priv->artik_switch->gpioButton1, 200);

	/* get the interrupt number of this button */
	irqNumber1 = gpio_to_irq(priv->artik_switch->gpioButton1);
	ret = request_irq(irqNumber1, (irq_handler_t) button1_irq_handler,
			IRQflags, "button1_handler", priv);
	if (ret != 0) {
		dev_err(&pdev->dev, "irq Request failure : %d\n", ret);
		goto gpioButton1_free;
	}
	
	return ret;

gpioButton1_free:
	gpio_unexport(priv->artik_switch->gpioLED1);
	gpio_free(priv->artik_switch->gpioLED1);
	gpio_free(priv->artik_switch->gpioButton1);
	return ret;

}

static int btn_open(struct input_dev *i_dev)
{
        pr_info("AMIT: input device opened()\n");
        return 0;
}

static void btn_close(struct input_dev *i_dev)
{
        pr_info("AMIT: input device closed()\n");
}


static int gpio_shortlong_gpio_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct artik_switch *artik_switch;
	struct btn_data *priv;
	struct input_dev *i_dev;
	struct device_node *np = pdev->dev.of_node;
	pr_info("AMIT..................is here\n");
	if (!np)
		return -ENODEV;

	dev_info(&pdev->dev, "probed\n");

	artik_switch = devm_kzalloc(&pdev->dev,
				sizeof(*artik_switch), GFP_KERNEL);
	if (!artik_switch)
		return -ENOMEM;

	priv = devm_kzalloc(&pdev->dev,
				sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

/*Allocating input device*/
        i_dev = input_allocate_device();
        if (!i_dev)
                return -ENOMEM;

	artik_switch->gpioButton1 = of_get_named_gpio(np, "button1-gpio", 0);
	if (!gpio_is_valid(artik_switch->gpioButton1)) {
		dev_err(&pdev->dev, "invalid gpio (data): %d\n",
				artik_switch->gpioButton1);
		return -ENODEV;
	}

	artik_switch->gpioLED1 = of_get_named_gpio(np, "led1-gpio", 0);
	if (!gpio_is_valid(artik_switch->gpioLED1)) {
		dev_err(&pdev->dev, "invalid gpio (data): %d\n",
				artik_switch->gpioLED1);
		return -ENODEV;
	}

	artik_switch->gpioButton2 = of_get_named_gpio(np, "button2-gpio", 0);
	if (!gpio_is_valid(artik_switch->gpioButton2)) {
		dev_err(&pdev->dev, "invalid gpio (data): %d\n",
				artik_switch->gpioButton2);
		return -ENODEV;
	}

	artik_switch->gpioLED2 = of_get_named_gpio(np, "led2-gpio", 0);
	if (!gpio_is_valid(artik_switch->gpioLED2)) {
		dev_err(&pdev->dev, "invalid gpio (data): %d\n",
				artik_switch->gpioLED2);
		return -ENODEV;
	}
	dev_info(&pdev->dev," gpioButton1:%d gpioLED1:%d gpioButton2:%d gpioLED2:%d\n",
			artik_switch->gpioButton1, artik_switch->gpioLED1,
			artik_switch->gpioButton2, artik_switch->gpioLED2);

        i_dev->open = btn_open;
        i_dev->close = btn_close;
        i_dev->name = "amit-PacktBtn";
        i_dev->dev.parent = &pdev->dev;

        priv->i_dev = i_dev;
	priv->artik_switch = artik_switch;
        priv->pdev = pdev;

/*Declare the event corrospond to button */
        set_bit(EV_KEY, i_dev->evbit); /*Event*/
        set_bit(BTN_1, i_dev->keybit); /*button*/
        set_bit(BTN_2, i_dev->keybit); /*button*/
        set_bit(BTN_3, i_dev->keybit); /*button*/
        //set_bit(BTN_3, i_dev->keybit); /*button*/
	//input_set_capability(priv->i_dev, EV_KEY, BTN_1);
/*Registering input device*/
        ret = input_register_device(priv->i_dev);
        if (ret) {
                pr_err("Failed to register input device\n");
                goto err_input;
        }

/*Setting Private-data into platform-data*/	
	platform_set_drvdata(pdev, priv);

	ret = gpioled1_setup(&pdev->dev);
	if (ret < 0) {
		dev_err(&pdev->dev,"gpioled_setup failed: %d\n", ret);
		return ret;
	}

	ret = button1_interrupt_config(&pdev->dev);
	if (ret != 0) {
		dev_err(&pdev->dev,"button interrupt configuration failed : %d\n", ret);
		return ret;
	}

	setup_timer(&long_press_timer1, long_press_timer_callback1, 0);

	ret = gpioled2_setup(&pdev->dev);
	if (ret < 0) {
		dev_err(&pdev->dev,"gpioled_setup failed: %d\n", ret);
		return ret;
	}

	ret = button2_interrupt_config(&pdev->dev);
	if (ret != 0) {
		dev_err(&pdev->dev,"button interrupt configuration failed : %d\n", ret);
		return ret;
	}

	setup_timer(&long_press_timer2, long_press_timer_callback2, 0);
/*Setup event wait-queue*/
	init_waitqueue_head(&input_event_wq);

	ewq_thread = kthread_create(evq_thread_function, &pdev->dev, "evq_thread");
	if(ewq_thread) {
                pr_info("AMIT: Wait queue thread creation successful\n");
                wake_up_process(ewq_thread);
        } else
                pr_info("AMIT: Wait queue thread creation failed\n");


	return ret;
err_input:
	input_free_device(priv->i_dev);
	return ret;

}

static int gpio_shortlong_gpio_remove(struct platform_device *pdev)
{

	struct btn_data *priv = platform_get_drvdata(pdev);

	free_irq(irqNumber2, NULL);

	/* Turn the LED off, makes it clear the device was unloaded */
	gpio_set_value(priv->artik_switch->gpioLED2, 0);
	gpio_unexport(priv->artik_switch->gpioLED2);
	gpio_free(priv->artik_switch->gpioLED2);
	gpio_unexport(priv->artik_switch->gpioButton2);
	gpio_free(priv->artik_switch->gpioButton2);

	free_irq(irqNumber1, NULL);
	gpio_set_value(priv->artik_switch->gpioLED1, 0);
	gpio_unexport(priv->artik_switch->gpioLED1);
	gpio_free(priv->artik_switch->gpioLED1);

	gpio_unexport(priv->artik_switch->gpioButton1);
	gpio_free(priv->artik_switch->gpioButton1);

	dev_info(&pdev->dev,"removed\n");
	return 0;
}

static const struct of_device_id gpio_of_ids[] = {
	{ .compatible = "amit-gpio-keys" },
	{ }
};
MODULE_DEVICE_TABLE(of, gpio_of_ids);

static struct platform_driver gpio_shortlong_gpio_driver = {
	.driver = {
		.name = "gpio-button-manager",
		.of_match_table = gpio_of_ids,
	},
	.probe  = gpio_shortlong_gpio_probe,
	.remove = gpio_shortlong_gpio_remove,
};

static int __init gpio_init(void)
{
	return platform_driver_register(&gpio_shortlong_gpio_driver);
}

static void __exit gpio_exit(void)
{
	platform_driver_unregister(&gpio_shortlong_gpio_driver);
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Amit Chauhan");
MODULE_DESCRIPTION("test-input-device");
MODULE_VERSION("1.0");
