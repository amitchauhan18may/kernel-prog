#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#define IRQ_NO 11

static dev_t dev;
static struct class *my_class;
static struct cdev my_cdev;

static int my_open (struct inode *inode, struct file *file)
{
	pr_info("Opening device\n");
	return 0;
}

static int my_release (struct inode *inode, struct file *file)
{
	pr_info("Closing device\n");
	return 0;
}

ssize_t my_read (struct file *file, char __user *buf, size_t len, loff_t *offset)
{
	pr_info("Reading device\n");

	return len;
}

ssize_t my_write (struct file *file, const char __user *buf, size_t len, loff_t *offset)
{
	pr_info("Writing device\n");

	return len;
}

static struct file_operations my_fops =
{
	owner: THIS_MODULE,
	open: my_open,
	read: my_read,
	write: my_write,
	release: my_release
};

static int __init my_interrupt_init (void)
{
	if (alloc_chrdev_region(&dev, 0, 1, "amit-dev") < 0) {
		pr_err("failed to allocate major number\n");
		return -1;
	}

	pr_info("Major No: %d Minor No: %d\n", MAJOR(dev), MINOR(dev));

	cdev_init(&my_cdev, &my_fops);
	my_cdev.owner = THIS_MODULE;

	if (cdev_add(&my_cdev, dev, 1) < 0)
       	{
		pr_err("Failed to add device\n");
		goto r_device;
	}

	if ((my_class = class_create(THIS_MODULE, "amit-class")) == NULL)
	{
		pr_err("Failed to create class\n");
		goto r_class;
	}

	if (device_create(my_class, NULL, dev, NULL, "amit-device") == NULL)
	{
		pr_err("Failed to create device\n");
		goto r_class;
	}

	if ()
	{
		pr_err("Failed register Interrupt\n");
		goto r_intr;
	}

	pr_info("Interrrupt module loaded successfully\n");

	return 0;
r_intr:


r_class:
	class_destroy(my_class);

r_device:
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev, 1);

	return -1;
}


static void __exit my_interrupt_exit (void)
{
	device_destroy(my_class, dev);
	class_destroy(my_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev, 1);

	pr_info("Interrrupt module un-loaded successfully\n");
	return;
}

module_init(my_interrupt_init);
module_exit(my_interrupt_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Cahuhan");
MODULE_DESCRIPTION("Test interrupt module for X86");
