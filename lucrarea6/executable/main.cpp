#include <iostream>
#include <cstring>
#include <operations/operations.h>
#include <functional>
using namespace std;

//factory function implementation
Operations* createOperations(int &n1, int &n2)
{
  return new Operations(n1,n2);
}
static void deletion(Operations* op)
{
  cout<<"\nThe operation "<<op<<" has been deleted!\n";
  op->~Operations();
}
void normal_op()
{
  int a,b;
  cout<<"Enter the first term of the operation:";
  cin>>a;
  cout<<"Enter the second term of the operation:";
  cin>>b;
  shared_ptr<Operations> o(createOperations(a,b),deletion);
  shared_ptr<Operations> o1;
  auto_ptr<Operations> oa(createOperations(a,b));
  auto_ptr<Operations> o1a;
  cout<<"\nHere are the operations made with the numbers entered:\n";
  o1=o;//both shared_ptr pointers point at the same objects
  /* same result would  appear for this
  o->sum();
  o->difference();
  o->product();
  o->division();
  o->power();
  */
  o1->sum();
  o1->difference();
  o1->product();
  o1->division();
  //using "->" helps get to the Operations object
  //since at the end both pointers wont be reachable anymore, the object is deleted with the custom method without explicitly calling it at the end
  o1a=oa;//only o1a points to the object now
  o1a->power();//calling oa->power would lead to segmentation fault
}
int main()
{
  cout<<"The next steps will show the works of Operations class:\n\n\n";
  normal_op();
}
