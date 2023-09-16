#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");
static int __init test_hello_init(void)
{
    int i = 10;
    void *virtual_address = (void *)&i;
    phys_addr_t physical_address = virt_to_phys(virtual_address);

    pr_info("Virtual Address(hashed) of i is %p\n", virtual_address);
    pr_info("Virtual Address(unmodified) of i is %px\n", virtual_address);
    pr_info("Physical Address of i is %pa\n", &physical_address);
    pr_info("Virtual address of i is %px\n", phys_to_virt(physical_address));
    return -1;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
