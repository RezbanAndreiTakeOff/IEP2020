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
  operations o1;
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
}
