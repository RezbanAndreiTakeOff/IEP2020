#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/platform_device.h>
#include<linux/of.h>

static struct of_device_id dev_ids_test[] = {
	{ .compatible = "test,firstdevice" },
	{ .compatible = "test,seconddevice"},
	{ .compatible = "test,thirddevice"},
	{ /* list terminator */},
};//list of compatible devices

MODULE_DEVICE_TABLE(of, dev_ids_test);

void sum(int a, int b)
{
  printk(KERN_ALERT "Sum: %d + %d =%d\n",a,b,a+b);
}
void difference(int a, int b)
{
  printk(KERN_ALERT "Difference: %d - %d =%d\n",a,b,a-b);
}
void product(int a, int b)
{
  printk(KERN_ALERT "Product: %d * %d =%d\n",a,b,a*b);
}
void division(int a, int b)
{
  if(b==0)
    printk(KERN_ALERT "Second number can't be 0 for division!\n");
  else
  {
    int aux = a/b;
    printk(KERN_ALERT "Division: %d / %d =%d\n",a,b,aux);
  }
}
void calculate(int a, int b)
{
	sum(a,b);
  difference(a,b);
  product(a,b);
  division(a,b);
}

static int test_get_info(struct platform_device *drv){
	int n1 = 0;
	int n2 = 0;

	struct device_node *target = drv->dev.of_node;
	printk(KERN_ALERT "Start operations from platform device: %s!\n", drv->name);

  of_property_read_u32(target, "first_number", &n1);
	printk(KERN_ALERT "first number from dtb: %d\n", n1);

  of_property_read_u32(target, "second_number", &n2);
	printk(KERN_ALERT "second number from dtb: %d\n", n2);

  calculate(n1,n2);//same functions like in the previous homework

	return 0;
}

static int test_remove_dev(struct platform_device *drv){
	printk(KERN_ALERT "Finish operations!\n");
	return 0;
}

static struct platform_driver my_driver = {
	.probe 	= test_get_info,//start kernel module
	.remove = test_remove_dev,//stop kernel module
	.driver = {
		.name = "driver_for_testing",
		.of_match_table = of_match_ptr(dev_ids_test),
		.owner = THIS_MODULE,
	},
};

module_platform_driver(my_driver);
