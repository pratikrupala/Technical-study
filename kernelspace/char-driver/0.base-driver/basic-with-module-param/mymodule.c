#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#define SIZE 5

static int myparam = 1;
static int myarray[SIZE] = {0, 1, 2, 3, 4};
static int num = 0;

module_param(myparam, int, S_IRUGO);
module_param_array(myarray, int, &num, S_IRUGO);
MODULE_LICENSE("GPL");

static int __init my_module_init(void)
{
	int i = 0;

	printk(KERN_ALERT "Killer says HI!!!:-)...\n");
	printk(KERN_ALERT "USER has sent %d to killer\n", myparam);
	
	printk(KERN_ALERT "User has sent %d arguments\n", num);
	for(i = 0; i < SIZE; i++) {
		printk(KERN_ALERT "User has sent array value at index %d: %d\n", i, myarray[i]);
	}

	return 0;
}

static void __exit my_module_exit(void)
{
	printk(KERN_ALERT "Killer says BYE!!!...\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
