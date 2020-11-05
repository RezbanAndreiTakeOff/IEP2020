#include <iostream>
#include <cstring>
#include <operations/operations.h>
using namespace std;

void normal_op()
{
  int a,b;
  cout<<"Enter the first term of the operation:";
  cin>>a;
  cout<<"Enter the second term of the operation:";
  cin>>b;
  Operations o(a,b);
  Operations o1,o2;
  o1=o2=o;//since assignment operator now returns a reference, this is a safe chain
  o=o; //this doesn't have to make another copy since it's just self assignment
  //the check at the beginning of the assignment operator method takes care of this case
  cout<<"\nHere are the operations made with the numbers entered:\n";
  o.sum();
  o.difference();
  o.product();
  o.division();
  o.power();
  o.~Operations();
  cout<<"\nHere are the operations with the squares of the numbers entered:\n";
  o2*=o1;//the operator *= is declared in operations class
  o2.sum();
  o2.difference();
  o2.product();
  o2.division();
  o2.power();
  o2.~Operations();
  cout<<"\nThere is an operations object with values equal to the one already shown above. Do you want to change its values? [Y/N]  ";
  char opt;
  cin>>opt;
  if(opt == 'Y')
  {
    cout<<"Enter the unique term of the operation:";
    cin>>a;
    o1=a;
    cout<<"Here are the operations made with the number entered:\n";
  }
  else{
    cout<<"Here are the operations made with the same numbers entered at the beginning:\n";
  }
  o1.sum();
  o1.difference();
  o1.product();
  o1.division();
  o1.power();
  o1.~Operations();
}
void enhanced_op()
{
  int a,b;
  char op;
  cout<<"Enter the first term of the operation:";
  cin>>a;
  cout<<"Enter the operation type [+,-,*,/,^]:";
  cin>>op;
  while(!strchr("+-*/^",op))
  {
    cout<<"Wrong character! Enter the operation type [+,-,*,/,^]:";
    cin>>op;//making sure that a good characted was introduced
  }
  cout<<"Enter the second term of the operation:";
  cin>>b;
  OperationsEnhanced o(a,b,op);
  OperationsEnhanced o1;
  o1=o;//since assignment operator now returns a reference, this is a safe chain
  o=o; //this doesn't have to make another copy since it's just self assignment
  //the check at the beginning of the assignment operator method takes care of this case
  o.~OperationsEnhanced();
  cout<<"\nHere is the result of the operation entered:\n";
  o1.calculate();//the assignment operator was written to be sure that it copies all parts of the object
  o1.~OperationsEnhanced();
}
int main()
{
  cout<<"The next steps will show the works of Operations class:\n\n\n";
  normal_op();
  cout<<"\n\n\nThe next steps will show the works of Operations Enhanced class:\n\n\n";
  enhanced_op();

}
