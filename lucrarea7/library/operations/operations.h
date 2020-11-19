#include <iostream>
using namespace std;

class Operations{
private:
    //Item 22 - Declare data members private
    int a,b;
    char op;
public:
    Operations(int a=0, int b=0, char c='+');//constructor is not explicit for Item 24
    int calculate();
    //Item 22 - all data members have read-write access and there is more precise control over every data member
    void setA(int nr){a = nr;}
    int getA(){return a;}
    void setB(int nr){b = nr;}
    int getB(){return b;}
    void setOp(char o){op = o;}
    char getOp(){return op;}
};
