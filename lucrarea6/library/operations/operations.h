#include <iostream>
using namespace std;
class Operations{
private:
    int a,b;
    Operations(const Operations&);//not using parameter names since these methods are not defined here
public:
    Operations();
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
