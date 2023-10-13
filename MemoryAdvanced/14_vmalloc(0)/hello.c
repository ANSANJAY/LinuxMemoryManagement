#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static int *ptr;

static int test_hello_init(void)
{
	ptr = vmalloc(0);
	if (ptr) {
		pr_info("Memory Allocated:%px\n", ptr);
		vfree(ptr);
	} else {
		pr_info("Memory not allocated\n");
	}

	return -1;
}

static void test_hello_exit(void)
{

}

module_init(test_hello_init);
module_exit(test_hello_exit);
