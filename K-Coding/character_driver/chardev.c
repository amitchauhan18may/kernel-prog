/*Writing Charcter Device Driver For User-Space Communication*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include "ioctl.h"

#define DEVICE_NAME "amit_test_driver"
#define DEVICE_NODE "amits_device"
#define DEVICE_CLASS "amits_class"

static unsigned int major;
static struct class *my_class;
static struct cdev  my_cdev;
static char user_data[250];
static int data_size;
static int io_value;


int my_open (struct inode *inode, struct file *file)
{

        pr_info("AMIT:I am opening file\n");

        return 0;
}


int my_release (struct inode *inode, struct file *file)
{

        pr_info("AMIT:I am closing file\n");

        return 0;
}

ssize_t my_read (struct file *file, char __user *buf, size_t count,
                loff_t *offset)
{

        int err_count = 0;

        err_count = copy_to_user(buf, user_data, data_size);

        pr_info("AMIT:I am reading data\n");

        if (err_count == 0) {
                pr_info("Sent Data: %s\n", user_data);
                return 0;

        } else {
                pr_err("failed to send data to user\n");
                return -EFAULT;
        }


}

ssize_t my_write (struct file *file, const char __user *buf, size_t count,
                loff_t *offset) {

        pr_info("AMIT:I am writing data\n");
        copy_from_user(user_data, buf, count);
        data_size = count;
        pr_info("Received data from user: %s : size:%zu\n", user_data, count);

        return count;
}

static long my_ioctl (struct file *file, unsigned int cmd, unsigned long arg)
{
        pr_info("Executing IOCTL command\n");

        switch (cmd)
        {
                case MY_WRITE:
                        pr_info("Writing value\n");
                        copy_from_user(&io_value, (int32_t *)arg, sizeof(io_value));
                        pr_info("Writtten value: %d\n", io_value);
                        break;
                case MY_READ:
                        pr_info("Reading value\n");
                        copy_to_user((int32_t *)arg, &io_value, sizeof(io_value));
                        break;
        }

        return 0;
}

struct file_operations  my_fops = {
        .owner	 = THIS_MODULE,
        .open    = my_open,
        .read    = my_read,
        .write   = my_write,
        .release = my_release,
        .unlocked_ioctl = my_ioctl
};

static int __init my_init (void)
{
        struct device *my_device;
        int error;
        dev_t dev = 0;

        printk(KERN_INFO "AMIT:Hello: module loaded at 0x%p\n", my_init);
        error = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
        if (error < 0) {
                pr_err("AMIT:failed to get Major number\n");
                return error;
        }

        major = MAJOR(dev);
        pr_info("AMIT:Major Number of driver: %d\n", major);

        my_class = class_create(THIS_MODULE, DEVICE_CLASS);
        if (IS_ERR(my_class)) {
                pr_err("AMIT:Failed to create device class\n");
                unregister_chrdev_region(MKDEV(major, 0), 1);
                return PTR_ERR(my_class);
        }

        cdev_init(&my_cdev, &my_fops);
        my_cdev.owner = THIS_MODULE;

        cdev_add(&my_cdev, dev, 1);

        my_device = device_create(my_class, NULL, dev, NULL, DEVICE_NODE);
        if (IS_ERR(my_device)) {
                pr_err("AMIT:Failed to create device\n");
                unregister_chrdev_region(MKDEV(major, 0), 1);
                return PTR_ERR(my_device);
        }

        pr_info("Amit's test driver loaded\n");

        return 0;
}

static void __exit my_exit (void)
{
        unregister_chrdev_region(MKDEV(major, 0), 1);
        device_destroy(my_class, MKDEV(major, 0));
        cdev_del(&my_cdev);
        class_destroy(my_class);
        printk(KERN_INFO "AMIT:Bye: module unloaded at 0x%p\n", my_exit);
}

module_init (my_init);
module_exit (my_exit);

MODULE_AUTHOR ("Amit Chauhan");
MODULE_DESCRIPTION ("Test character driver module");
MODULE_LICENSE ("GPL");
