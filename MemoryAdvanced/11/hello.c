#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <asm/pgtable.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");


static int test_hello_init(void)
{
	pr_info("Vmalloc start:%lx\n", VMALLOC_START);
	pr_info("Vmalloc end:%lx\n", VMALLOC_END);
	pr_info("Vmalloc size:%d MB\n", (VMALLOC_END - VMALLOC_START)/(1024*1024));
	return -1;
}

static void test_hello_exit(void)
{

}

module_init(test_hello_init);
module_exit(test_hello_exit);
