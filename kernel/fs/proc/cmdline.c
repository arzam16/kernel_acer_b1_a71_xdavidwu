#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
extern unsigned int g_demo_boot_mode;
static int cmdline_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%s\n", saved_command_line);
	return 0;
}

static int cmdline_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, cmdline_proc_show, NULL);
}

static const struct file_operations cmdline_proc_fops = {
	.open		= cmdline_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int demo_proc_show(struct seq_file *m, void *v)
{
        if(g_demo_boot_mode == 1){
	        seq_printf(m, "BOOT MODE : DEMO BOOT");
	}else{
	        seq_printf(m, "BOOT MODE : NORMAL BOOT");
	}

	return 0;
}

static int demo_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, demo_proc_show, NULL);
}


static ssize_t
read_demo(struct file *file, char __user *buffer, size_t buflen, loff_t *fpos)
{
	char tmp = '0';
	if(g_demo_boot_mode == 1)
		tmp = '1';
	else if(g_demo_boot_mode == 2)
		tmp = '2';
	else if(g_demo_boot_mode == 3)
		tmp = '3';
	else if(g_demo_boot_mode == 4)
		tmp = '4';
	copy_to_user(buffer, &tmp, 1);
	return 0;
}

static const struct file_operations demo_proc_fops = {
	.open		= demo_proc_open,
	.read		= read_demo,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_cmdline_init(void)
{
	proc_create("cmdline", 0, NULL, &cmdline_proc_fops);
	proc_create("demo_boot_mode", 0, NULL, &demo_proc_fops);
	return 0;
}
module_init(proc_cmdline_init);
