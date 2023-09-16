#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *addr;

static int test_hello_init(void)
{
	addr = kmalloc(4096, GFP_KERNEL);
        printk("I got: %zu bytes of memory\n", ksize(addr));
        addr = krealloc(addr, 8192, GFP_KERNEL);
        printk("I got: %zu bytes of memory\n", ksize(addr));
        kfree(addr);
	return -1;
}

static void test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
