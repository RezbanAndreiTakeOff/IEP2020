#include <iostream>
#include <cmath>
#include "operations.h"
using namespace std;

// Operations functions implementation
Operations::Operations(int n1,int n2, char operation)
:a(n1),b(n2),op(operation) //use the member initialization list and the constructor of the upper class
{}

int Operations::calculate()
{
  switch (getOp()) {//depending on the op value, a function from the Operation class will be called
    case '+': return a + b;break;
    case '-': return a - b;break;
    case '*': return a * b;break;
    case '/': return (int)(a / b);break;
    case '^': return pow(a,b);break;
    default: return 0;break;
  }
}
