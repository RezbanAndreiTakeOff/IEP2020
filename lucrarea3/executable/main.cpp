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
  o.sum();
  o.difference();
  o.product();
  o.division();
  o.power();
}
