#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static char *ptr;
int alloc_size = 4096*1234;


static int test_hello_init(void)
{
	ptr = vmalloc(alloc_size);
	if(!ptr) {
		/* handle error */
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	} else {
		pr_info("Physical address:%px\t Virtual Address:%llx\n", 
				ptr+4096, virt_to_phys(ptr+(4096*1234)));
	}
	return 0;
}

static void test_hello_exit(void)
{
	vfree(ptr);
	pr_info("Memory freed\n");

}

module_init(test_hello_init);
module_exit(test_hello_exit);
