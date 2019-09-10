#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static struct cdev my_cdev;
static struct class *my_cls;

static int my_open (struct inode *inode, struct file *file)
{
	pr_info("AMIT: Opening device\n");

	return 0;
}

static int my_release (struct inode *inode, struct file *file)
{
	pr_info("AMIT: Closing device\n");

	return 0;
}

ssize_t my_read (struct file *file, char __user *buf, size_t len, loff_t *offset)
{
	pr_info("AMIT: Reading device file\n");

	return len;
}

ssize_t my_write (struct file *file, const char __user *buf, size_t len, loff_t *offset)
{
	pr_info("AMIT: Reading device file\n");

	return 0;
}

static struct file_operations my_fops = {
	owner: THIS_MODULE,
	open: my_open,
	read: my_read,
	write: my_write,
	release: my_release
};

static int __init sys_init (void)
{

	return 0;
}

static void __exit sys_exit (void)
{

	return;
}

module_init(sys_init);
module_exit(sys_exit);
MODULE_AUTHOR("Amit Chauhan");
MODULE_DESCRIPTION("Test module for sysfs interface");
MODULE_LICENSE("GPL");
