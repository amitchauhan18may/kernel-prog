#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/wait.h>

DECLARE_WAIT_QUEUE_HEAD(my_wait_q);
int wait_q_flag = 0;

static struct task_struct *wq_thread;
uint32_t read_count = 0;

static dev_t dev;
static struct class *my_cls;
static struct cdev my_cdev;

static int wait_q_function (void *data) {
        while (1) {
                pr_info("AMIT: Waiting for event\n");
                wait_event_interruptible(my_wait_q, wait_q_flag != 0);
                if (wait_q_flag == 2) {
                        pr_info("AMIT: Event came from exit function\n");
                        return 0;
                }

                pr_info("AMIT: Event came from read function: Count: %d\n", ++read_count);
		wait_q_flag = 0;
        }
                
	do_exit(0); 
	return 0;
}

static int my_open (struct inode *inode, struct file *file) {
        pr_info("AMIT: Opening device file\n");

        return 0;
}

static int my_release (struct inode *inode, struct file *file) {
        pr_info("AMIT: Closing device file\n");

        return 0;
}

ssize_t my_read (struct file *file, char __user *buff, size_t len, loff_t *off)
{
        pr_info("AMIT: Reading device file\n");
        wait_q_flag = 1;
        wake_up_interruptible(&my_wait_q);

        return 0;

}

ssize_t my_write (struct file *file, const char __user *buff, size_t len, loff_t *off)
{
        pr_info("AMIT: Writing device file\n");

        return 0;
}
        
struct file_operations my_fops = {
        owner:          THIS_MODULE,
        open:           my_open,
        read:           my_read,
        write:          my_write,
        release:        my_release
};

static int __init my_init(void)
{
        if (alloc_chrdev_region(&dev, 0, 1, "amit-dev") < 0) {
                pr_err("AMIT: Failed to allocate Major number\n");
                return -1;
        }

        pr_info("AMIT: Device registration with Major: %d Minor: %d\n", MAJOR(dev), MINOR(dev));

        cdev_init(&my_cdev, &my_fops);
        my_cdev.owner = THIS_MODULE;

        if (cdev_add(&my_cdev, dev, 1) < 0) {
                pr_err("AMIT: Failed to add cdev\n");
                goto r_dev;
        }

        my_cls = class_create(THIS_MODULE, "amit-class");
        if (NULL == my_cls) {
                pr_err("AMIT: Failed to create device class\n");
                goto r_cls;
        }

        if (device_create(my_cls, NULL, dev, NULL, "amit-dev") == NULL) {
                pr_err("AMIT: Failed to create device\n");
                goto r_cls;
        }

        init_waitqueue_head(&my_wait_q);

        wq_thread = kthread_create(wait_q_function, NULL, "wait-queue-thread");
        if(wq_thread) {
                pr_info("AMIT: Wait queue thread creation successful\n");
		wake_up_process(wq_thread);
	} else
                pr_info("AMIT: Wait queue thread creation failed\n");

        pr_info("AMIT: wait-queue module loaded successfully\n");

        return 0;

r_cls:
        class_destroy(my_cls);
r_dev:
        unregister_chrdev_region(dev,1);

        return -1;
}

static void __exit my_exit(void)
{
        wait_q_flag = 2;
        wake_up_interruptible(&my_wait_q);
        device_destroy(my_cls, dev);
        class_destroy(my_cls);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev,1);
        pr_info("AMIT: wait-queue module un-loaded successfully\n");
        return;
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("AMit Chauhan");
MODULE_DESCRIPTION("Test module for wait-queue");
MODULE_LICENSE("GPL");
