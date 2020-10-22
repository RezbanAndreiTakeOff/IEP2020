#include <iostream>
#include <cmath>
#include "operations.h"
using namespace std;
operations::operations(int n1,int n2)
{
  a=n1;
  b=n2;
}
void operations::sum()
{
  cout<<"Sum: "<<a<<"+"<<b<<"="<<a+b<<'\n';
}
void operations::difference()
{
  cout<<"Difference: "<<a<<"-"<<b<<"="<<a-b<<'\n';
}
void operations::product()
{
  cout<<"Product: "<<a<<"*"<<b<<"="<<a*b<<'\n';
}
void operations::division()
{
  if(b==0)
    cout<<"B can't be 0 for division!\n";
  else
    cout<<"Division: "<<a<<"/"<<b<<"="<<(float)a/b<<'\n';
}
void operations::power()
{
    cout<<"Power: "<<a<<"^"<<b<<"="<<pow(a,b)<<'\n';
}
