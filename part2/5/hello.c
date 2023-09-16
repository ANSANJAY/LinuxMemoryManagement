#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static char *ptr;
int alloc_size = 1024;

module_param(alloc_size, int, 0);

static int test_hello_init(void)
{
	ptr = kmalloc(alloc_size,GFP_ATOMIC);
	if(!ptr) {
		/* handle error */
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	} else {
		pr_info("Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+102 is %d\n", *(ptr+102));
	}
	kfree(ptr);
	ptr = kzalloc(alloc_size,GFP_ATOMIC);
	if(!ptr) {
		/* handle error */
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	} else {
		pr_info("Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+102 is %d\n", *(ptr+102));
	}
	kfree(ptr);

	return -1;
}

static void test_hello_exit(void)
{

}

module_init(test_hello_init);
module_exit(test_hello_exit);
