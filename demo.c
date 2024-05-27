#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>
#include <linux/device.h>

#define DEVICE_NAME "demo"
#define CLASS_NAME "demo_class"

static int major_number;
static char userChar[100];
static struct class* demo_class = NULL;
static struct device* demo_device = NULL;

static int dev_open(struct inode *inodep, struct file *filep){
    printk(KERN_INFO "Enter Open function\n");
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep){
    printk(KERN_INFO "Enter Release function\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
    printk(KERN_INFO "Enter Read function\n");
    return 0;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
    printk(KERN_INFO "Enter Write function\n");
    copy_from_user(userChar,buffer,len);
    userChar[len-1]=0;
    printk("userChar(char): %s\n",userChar);
    printk("userChar(int): %d\n",(int)sizeof(userChar));
    char gpio[10]={0};
    strncpy(gpio,userChar, 3);
    printk("gpio: %s, length: %d\n", gpio, strlen(gpio));
    struct file *io;
    loff_t pos = 0;
    mm_segment_t old_fs;
    old_fs = get_fs();
    set_fs(get_ds());
    return len;
}

static long dev_ioctl(struct file *filep, unsigned int cmd, unsigned long arg){
    printk(KERN_INFO "Enter I/O Control function\n");
    return 0;
}

static struct file_operations fops = {
        .open = dev_open,
        .release = dev_release,
        .read = dev_read,
        .write = dev_write,
        .unlocked_ioctl = dev_ioctl,
};

static int __init demo_init(void){
    printk(KERN_INFO "Initializing the demo LKM\n");

    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0){
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    demo_class = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(demo_class)){
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Failed to register device class\n");
        return PTR_ERR(demo_class);
    }

    demo_device = device_create(demo_class, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(demo_device)){
        class_destroy(demo_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Failed to create the device\n");
        return PTR_ERR(demo_device);
    }

    printk(KERN_INFO "Demo: device class created correctly\n");
    return 0;
}

static void __exit demo_exit(void){
    device_destroy(demo_class, MKDEV(major_number, 0));
    class_unregister(demo_class);
    class_destroy(demo_class);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Demo: Goodbye from the LKM!\n");
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("A simple Linux char driver for LED control");
MODULE_VERSION("1.0");
