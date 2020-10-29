#include <iostream>
#include <operations/operations.h>
using namespace std;

int main()
{
  int a,b;
  cout<<"Enter the first term of the operation:";
  cin>>a;
  cout<<"Enter the second term of the operation:";
  cin>>b;
  operations o(a,b);
  operations o1;//if I have a constructor declared, the compiler will not automatically create the empty one 
  cout<<"Here are the operations made with the numbers entered:\n";
  o.sum();
  o.difference();
  o.product();
  o.division();
  o.power();
  cout<<"Here are the results from the operations without specified numbers:\n";
  o1.sum();
  o1.difference();
  o1.product();
  o1.division();
  o1.power();
  /*
  //because of making the copy constructor and copy assignment operator private methods, the next two lines will return errors:
  o1 = o; // error: 'operator=' is a private member of 'operations'
  operations o2(o); // calling a private constructor of class 'operations'
  //the messages are taken from terminal after calling `make` command
  */
}
