#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>

char proc_array[30] = "Testing procfs";
static int len = 1;

static int proc_open (struct inode *inode, struct file *file) {
        pr_info("AMIT: opening procfs device file\n");

        return 0;
}

static int proc_release (struct inode *inode, struct file *file) {
        pr_info("AMIT: opening procfs device file\n");

        return 0;
}

ssize_t proc_read (struct file *file, char __user *buff, size_t len_l, loff_t *ofset)
{
        pr_info("AMIT: Reading from procfs\n");
	if (len) {
		pr_info("len: %d and seeting to ZERO\n", len);
		len=0;
	} else {
		pr_info("len: %d and seeting to ONE\n", len);
		len=1;
		return 0;
	}

        copy_to_user(buff, proc_array, strlen(proc_array));

        pr_info("AMIT: Reading data: %s of length [%ld]\n", proc_array, strlen(proc_array));

        return len_l;
}

ssize_t proc_write (struct file *file, const char __user *buff, size_t len, loff_t *ofset)
{
        pr_info("AMIT: Writing to procfs\n");
        copy_from_user(proc_array ,buff, len);

        return len;
}

static struct file_operations proc_fops = {
        open:           proc_open,
        read:           proc_read,
        write:          proc_write,
        release:        proc_release
};

void init_proc (void) {

        pr_info("Initializing proc interface\n");
        proc_create("my_proc", 0666, NULL, &proc_fops);

        return;

}

void exit_proc (void) {

        pr_info("Removing proc interface\n");
	remove_proc_entry("my_proc", NULL);

	return;
}

MODULE_AUTHOR ("Amit Chauhan");
MODULE_DESCRIPTION ("Test character driver module");
MODULE_LICENSE ("GPL");
