/* hello.c */
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
    printk(KERN_ALERT "hello - Hello, World\n");
    return 0;
}

static void hello_exit(void)    // Note: 此处返回void，有些Linux版本对此严格
{
    printk(KERN_ALERT "hello - Goodbye, cruel world\n");
}

module_init(hello_init);

module_exit(hello_exit);