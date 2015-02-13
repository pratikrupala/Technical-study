#include <linux/init.h>
#include <linux/module.h>
#include "header-two.h"

static int __init my_module_one_init(void)
{
	printk(KERN_ALERT "Module one says: Hello world!!!\n");
	function_from_module_two();
	return 0;
}

static void __exit my_module_one_exit(void)
{
	printk(KERN_ALERT "Module one says: Good bye world!!!\n");
}

module_init(my_module_one_init);
module_exit(my_module_one_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pratik Rupala");
MODULE_DESCRIPTION("Module which uses function exported by other module");
