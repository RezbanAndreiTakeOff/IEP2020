#include <iostream>
using namespace std;
class operations{
private:
    int a,b;
public:
    operations();
    operations(int &a, int &b);
    void sum();
    void difference();
    void product();
    void division();
    void power();
    void setA(int a);
    void setB(int b);
};
