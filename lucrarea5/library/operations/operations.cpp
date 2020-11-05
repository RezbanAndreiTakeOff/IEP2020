#include <iostream>
#include <cmath>
#include "operations.h"
using namespace std;

// Operations functions implementation
Operations::Operations(int &n1,int &n2)
:a(n1),b(n2) //use the member initialization list
{}
Operations::Operations()
:a(0),b(0) //use the member initialization list
{}
void Operations::sum()
{
  cout<<"Sum: "<<a<<"+"<<b<<"="<<a+b<<'\n';
}
void Operations::difference()
{
  cout<<"Difference: "<<a<<"-"<<b<<"="<<a-b<<'\n';
}
void Operations::product()
{
  cout<<"Product: "<<a<<"*"<<b<<"="<<a*b<<'\n';
}
void Operations::division()
{
  if(b==0)
    cout<<"B can't be 0 for division!\n";
  else
    cout<<"Division: "<<a<<"/"<<b<<"="<<(float)a/b<<'\n';
}
void Operations::power()
{
    cout<<"Power: "<<a<<"^"<<b<<"="<<pow(a,b)<<'\n';
}


// Operations functions implementation
OperationsEnhanced::OperationsEnhanced(int &n1,int &n2, char &operation)
:Operations(n1,n2),op(operation) //use the member initialization list and the constructor of the upper class
{}

OperationsEnhanced::OperationsEnhanced()
:Operations(),op('+') //use the member initialization list and the constructor of the upper class
{}

void OperationsEnhanced::calculate()
{
  switch (op) {//depending on the op value, a function from the Operation class will be called
    case '+': sum();break;
    case '-': difference();break;
    case '*': product();break;
    case '/': division();break;
    case '^': power();break;
    default: break;
  }
}
