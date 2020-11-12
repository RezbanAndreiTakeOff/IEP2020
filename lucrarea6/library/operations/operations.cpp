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
