#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm_types.h>

MODULE_LICENSE("GPL");
static int __init test_hello_init(void)
{
    pr_info("size of page is %lu bytes\n", sizeof(struct page));
    return -1;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
