#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static int i = 1;
static int cb_value = 1;
static int arr[2] = {1, 2};
static char *p = "I am amit";

int notify_function (const char *value, const struct kernel_param *kp) 
{
	int res = param_set_int(value, kp);

	if (res == 0)
	{
		pr_info("AMIT: Change on cb_value occured: %d\n", cb_value);
		return 0;
	}

	return -1;
}

struct kernel_param_ops my_cb_obj = {
	set: notify_function,
	get: param_get_int
};

module_param_cb(cb_value, &my_cb_obj, &cb_value, S_IRUSR | S_IWUSR);

module_param(i, int, S_IRUSR | S_IWUSR);
module_param(p, charp, S_IRUSR | S_IWUSR);
module_param_array(arr, int, NULL, S_IRUSR | S_IWUSR);


static int __init my_param_init(void)
{
        pr_info("AMIT:PARAM: test loaded successfully\n");

        pr_info("My int value: %d\n", i);
        pr_info("My int CB-value: %d\n", cb_value);
        pr_info("My int array values: %d : %d\n", arr[0], arr[1]);
        pr_info("My char p-value: %s\n", p);

        return 0;
}

static void __exit my_param_exit(void)
{
        pr_info("AMIT:PARAM: test un-loaded successfully\n");
        return;
}

module_init(my_param_init);
module_exit(my_param_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Chauhan");
MODULE_DESCRIPTION("Test for module parameters");
MODULE_VERSION("1.0");
