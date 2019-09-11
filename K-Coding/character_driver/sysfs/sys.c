#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>

static dev_t dev;
static struct cdev my_cdev;
static struct class *my_cls;

volatile int sys_val = 0;
struct kobject *sys_koj;

static ssize_t sysfs_show(struct kobject *kobj, struct kobj_attribute *kobj_attr, char *buf)
{
	pr_info("sysfs_show value: %d\n", sys_val);

	return 0;
}

static ssize_t sysfs_store(struct kobject *kobj, struct kobj_attribute *kobj_attr, const char *buf, size_t count)
{
	pr_info("sysfs_show value: %p\n", &sys_val);

	return 0;
}

struct kobj_attribute attribute = __ATTR(sys_val, 0660, sysfs_show, sysfs_store);

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
        if (alloc_chrdev_region(&dev, 0, 1, "amit-dev") < 0) {
                pr_err("Failed to allocate major no\n");
        }

        cdev_init(&my_cdev, &my_fops);
        my_cdev.owner = THIS_MODULE;

        if (cdev_add(&my_cdev, dev, 1) < 0) {
                pr_err("Failed to add device\n");
                goto r_dev;
        }

        my_cls = class_create(THIS_MODULE, "amit-class");
        if (NULL == my_cls) {
                pr_err("Failed to cleate class\n");
                goto r_dev;
        }

        if (device_create(my_cls, NULL, dev, NULL, "amit-dev") < 0) {
                pr_err("Failed to cleate device\n");
                goto r_cls;
        }

	sys_koj = kobject_create_and_add("amit-sysfs", kernel_kobj);

	if (sysfs_create_file(sys_koj, &attribute.attr)) {
		pr_err("Failed to create sysfs file\n");
		goto r_sysfs;
	}

        pr_info("Sysfs module loaded succesfully\n");

        return 0;

r_sysfs:
	kobject_put(sys_koj);
	sysfs_remove_file(sys_koj, &attribute.attr);
r_cls:
        class_destroy(my_cls);
r_dev:
	cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);

        return -1;
}

static void __exit sys_exit (void)
{
	kobject_put(sys_koj);
	sysfs_remove_file(sys_koj, &attribute.attr);
        device_destroy(my_cls, dev);
        class_destroy(my_cls);
	cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Sysfs module unloaded succesfully\n");

        return;
}

module_init(sys_init);
module_exit(sys_exit);
MODULE_AUTHOR("Amit Chauhan");
MODULE_DESCRIPTION("Test module for sysfs interface");
MODULE_LICENSE("GPL");
