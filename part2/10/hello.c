#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *ptr;

static int test_hello_init(void)
{
        ptr =vmalloc(1);
        printk("I got: %zu bytes of memory\n", ksize(ptr));
        vfree(ptr);
        ptr = vmalloc(8);
        printk("I got: %zu bytes of memory\n", ksize(ptr));
        vfree(ptr);
        ptr = vmalloc(8080);
        printk("I got: %zu bytes of memory\n", ksize(ptr));
        vfree(ptr);
        ptr = vmalloc(8192);
        printk("I got: %zu bytes of memory\n", ksize(ptr));
        vfree(ptr);
	return -1;
}

static void test_hello_exit(void)
{

}

module_init(test_hello_init);
module_exit(test_hello_exit);
