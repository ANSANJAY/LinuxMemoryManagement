#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static void *ptr;
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
		phys_addr_t physical_address = virt_to_phys(ptr);
		pr_info("Memory Allocated:%px\n", ptr);
		pr_info("Physical Address of i is %pa\n", &physical_address);
	}

	return 0;
}

static void test_hello_exit(void)
{
	kfree(ptr);
	pr_info("Memory freed\n");

}

module_init(test_hello_init);
module_exit(test_hello_exit);
