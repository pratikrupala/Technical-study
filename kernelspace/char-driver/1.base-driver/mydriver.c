#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init my_module_init(void)
{
	printk(KERN_ALERT "Killer says HI!!!:-)...\n");
	return 0;
}

static void __exit my_module_exit(void)
{
	printk(KERN_ALERT "Killer says BYE!!!...\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
