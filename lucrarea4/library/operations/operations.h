#include <iostream>
using namespace std;
class operations{
private:
    int a,b;
    operations(const operations&);//not using parameter names since these methods are not defined here
    operations& operator=(const operations&);
public:
    // operations();//made sure that if I need the default constructor I will declare and define it
    ~operations(){};//declare destructor myself instead of letting the compiler
    operations(int &, int &);//not using parameter names since this constructor is not defined here
    void sum();
    void difference();
    void product();
    void division();
    void power();
    void setA(int a);
    void setB(int b);
};
