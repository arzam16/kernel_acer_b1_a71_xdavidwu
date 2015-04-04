#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

static int __init proc_cel_property_init(void)
{
	struct proc_dir_entry *pty_dir = NULL;
	pty_dir = proc_mkdir("cel_property", NULL);
	if(!pty_dir){
		printk(KERN_ERR"%s:koala cel_peoperty fail\n",__func__);
	}
	return 0;
}
core_initcall(proc_cel_property_init);
