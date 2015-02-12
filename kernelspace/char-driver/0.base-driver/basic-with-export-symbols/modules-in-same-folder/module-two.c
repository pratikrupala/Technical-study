#include <linux/init.h>
#include <linux/module.h>

static int __init my_module_two_init(void)
{
	printk(KERN_ALERT "Module two says: Hello world!!!\n");
	return 0;
}

static void __exit my_module_two_exit(void)
{
	printk(KERN_ALERT "Module two says: Good bye world!!!\n");
}

void function_from_module_two(void)
{
	printk(KERN_ALERT "Greetings from module two.\n");
}
EXPORT_SYMBOL_GPL(function_from_module_two);

module_init(my_module_two_init);
module_exit(my_module_two_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pratik Rupala");
MODULE_DESCRIPTION("Module which exports function as a symbol");
