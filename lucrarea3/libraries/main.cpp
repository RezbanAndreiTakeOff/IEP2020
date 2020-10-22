#include <iostream>
#include "operations.h"
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  operations o(a,b);
  o.sum();
}
