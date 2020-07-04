#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/kthread.h>
#include <linux/mutex.h>

#define DEVICE_NAME	"mutex-cdev"
#define CLASS_NAME	"mutex-class"

struct mutex mutexTest;
struct task_struct *thread1;
struct task_struct *thread2;
static int gValueCounter;


int threadFunction1 (void *data)
{
	while (!kthread_should_stop())
	{
		mutex_lock(&mutexTest);
		gValueCounter++;
		pr_info("threadFunction1 gValueCounter: %d\n", gValueCounter);
		mutex_unlock(&mutexTest);
	}

	return 0;
}


int threadFunction2 (void *data)
{
	while (!kthread_should_stop())
	{
		mutex_lock(&mutexTest);
		gValueCounter++;
		pr_info("threadFunction2 gValueCounter: %d\n", gValueCounter);
		mutex_unlock(&mutexTest);
	
	}

	return 0;
}


static int __init mutexTestInit (void)
{
	mutex_init(&mutexTest);

	thread1 = kthread_run(threadFunction1, NULL, "thread1");
	if (thread1) {
		pr_info("Thread1 created successfully\n");
	} else {
		pr_err("Thread1 creation failed\n");
		return -1;
	}

	thread2 = kthread_run(threadFunction2, NULL, "thread2");
	if (thread1) {
		pr_info("Thread2 created successfully\n");
	} else {
		pr_err("Thread2 creation failed\n");
		return -1;
	}

	pr_info("Mutex test module inserted successfully\n");
	return 0;
}


static void __exit mutexTestExit (void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	pr_info("Mutex test module removed successfully\n");
	return;
}

module_init(mutexTestInit);
module_exit(mutexTestExit);

MODULE_DESCRIPTION("Mutex Test Module");
MODULE_VERSION("v1.0");
MODULE_AUTHOR("Amit Chauhan");
MODULE_LICENSE("GPL");
