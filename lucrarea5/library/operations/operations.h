#include <iostream>
using namespace std;
class Operations{
private:
    int a,b;
    Operations(const Operations&);//not using parameter names since these methods are not defined here
public:
    Operations();
    ~Operations(){};//declare destructor myself instead of letting the compiler
    Operations(int &, int &);//not using parameter names since this constructor is not defined here
    void sum();
    void difference();
    void product();
    void division();
    void power();
    Operations& operator=(const Operations& o){
      if (this == &o) return *this;// in case of self assignment
      //this check should be enough since there are no dinamically allocated objects in my class
      this->a = o.a;//make sure everything is copied right
      this->b = o.b;
      return *this;//return a *this reference for assignment operators
    }
    Operations& operator=(int n){
      this->a = n;//both variables get the same value
      this->b = n;
      return *this;//return a *this reference for assignment operators
    }
    Operations& operator*=(const Operations& o){
      this->a = this->a * o.a;
      this->b = this->b * o.b;
      return *this;//return a *this reference for assignment operators
    }

};

class OperationsEnhanced: public Operations{
private:
    char op;//char variable to make only the requested operation
    OperationsEnhanced(const OperationsEnhanced&);//not using parameter names since these methods are not defined here
public:
    OperationsEnhanced();//empty constructor to be able to create objects with default values
    ~OperationsEnhanced(){};//declare destructor myself instead of letting the compiler
    OperationsEnhanced(int &, int &, char &);//not using parameter names since this constructor is not defined here
    void calculate();
    OperationsEnhanced& operator=(const OperationsEnhanced& o){
      if (this == &o) return *this;// in case of self assignment
      //this check should be enough since there are no dinamically allocated objects in my class
      Operations::operator=(o);
      this->op = o.op;
      return *this;//return a *this reference for assignment operators
    }

};
