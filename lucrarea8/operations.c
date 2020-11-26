#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int numbers[2] = {0,0};
module_param_array(numbers, int, NULL, S_IRUSR | S_IWUSR);

void sum(void)
{
  printk(KERN_ALERT "Sum: %d + %d =%d\n",numbers[0],numbers[1],numbers[0]+numbers[1]);
}
void difference(void)
{
  printk(KERN_ALERT "Difference: %d - %d =%d\n",numbers[0],numbers[1],numbers[0]-numbers[1]);
}
void product(void)
{
  printk(KERN_ALERT "Product: %d * %d =%d\n",numbers[0],numbers[1],numbers[0]*numbers[1]);
}
void division(void)
{
  if(numbers[1]==0)
    printk(KERN_ALERT "Second number can't be 0 for division!\n");
  else
  {
    int aux = numbers[0]/numbers[1];
    printk(KERN_ALERT "Division: %d / %d =%d\n",numbers[0],numbers[1],aux);
  }
}
void calculate(void)
{
	sum();
  difference();
  product();
  division();
}

static int operations_init(void)
{
  printk(KERN_ALERT "Start operations!\n");
  if(numbers[0]==0&&numbers[1]==0)
    printk(KERN_ALERT "You must give parameters!\n");
  else
    calculate();
  return 0;
}

static void operations_exit(void)
{
  printk(KERN_ALERT "Finish operations!\n");
}

module_init(operations_init);
module_exit(operations_exit);
