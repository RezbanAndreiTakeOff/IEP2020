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
  cout<<a<<"+"<<b<<"="<<a+b<<'\n';
}
void operations::difference()
{
  cout<<a<<"-"<<b<<"="<<a-b<<'\n';
}
void operations::product()
{
  cout<<a<<"*"<<b<<"="<<a*b<<'\n';
}
void operations::division()
{
  if(b==0)
    cout<<"B can't be 0 for division!\n";
  else
    cout<<a<<"/"<<b<<"="<<a/b<<'\n';
}
void operations::power()
{
  // cout<<a<<" times "<<b<<"="<<pow(a,b)<<'\n';
}
