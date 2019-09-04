/*Writing Charcter Device Driver For User-Space Communication*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>

#define DEVICE_NAME "amit_test_driver"
#define DEVICE_NODE "amits_device"
#define DEVICE_CLASS "amits_class"

static unsigned int major;
static struct class *my_class;
static struct cdev  my_cdev;


int my_open (struct inode *inode, struct file *file) {

	pr_info("AMIT:I am opening file\n");

	return 0;
}


int my_release (struct inode *inode, struct file *file) {

	pr_info("AMIT:I am closing file\n");

	return 0;
}

ssize_t my_read (struct file *file, char __user *buf, size_t count,
	       	 loff_t *offset) {

	pr_info("AMIT:I am writing data\n");

	return 0;
}

ssize_t my_write (struct file *file, const char __user *buf, size_t count,
	          loff_t *offset) {

	pr_info("AMIT:I am writing data\n");

	return count;
}

struct file_operations  my_fops = {
	.open    = my_open,
	.read    = my_read,
	.write   = my_write,
	.release = my_release
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

	my_device = device_create(my_class, NULL, dev, NULL, DEVICE_NODE"%d", 1);
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
