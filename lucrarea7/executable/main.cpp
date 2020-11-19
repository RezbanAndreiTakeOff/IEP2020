#include <iostream>
#include <cstring>
#include <operations/operations.h>
using namespace std;

inline const Operations operator+(Operations &o1, Operations &o2)
{
  return Operations(o1.calculate(), o2.calculate(), '+');//Item 21 - return an object instead of a reference
}

void editare(Operations *o)
{
  int nr;
  char op;
  cout<<"Introduceti primul termen (actual "<<o->getA()<<"):";
  cin>>nr;
  o->setA(nr);
  cout<<"Introduceti al doilea termen (actual "<<o->getB()<<"):";
  cin>>nr;
  o->setB(nr);
  cout<<"Introduceti tipul operatiei [+,-,*,/,^] (actual "<<o->getOp()<<"):";
  cin>>op;
  while(!strchr("+-*/^",op))
  {
    cout<<"Caracter gresit! Introduceti tipul operatiei [+,-,*,/,^]:";
    cin>>op;
  }
  o->setOp(op);
}
void rezultat(Operations o)
{
  cout<<"Rezultatul operatiei este: -> ";
  cout<<o.getA()<<" "<<o.getOp()<<" "<<o.getB()<<" = "<<o.calculate()<<"\n";
}
void adunare(Operations o1, Operations o2)
{
  rezultat(o1+o2);
}
void adunare_numar(Operations o1)
{
  int nr;
  cout<<"Dati numarul:\n";
  cin>>nr;
  adunare(nr,o1);//Item 24 - because operator+ is a non-member function, type convertors apply automatically
  //the second parameter is an int, but the method takes it as an Operations object because of the not explicit constructor
}

int main()
{
  int o=1;
  Operations o1,o2;
  while(o){
    cout<<"\n\nMeniu operatii:\n";
    cout<<"1. Editati prima operatie.\n";
    cout<<"2. Editati a doua operatie.\n";
    cout<<"3. Afisati prima operatie.\n";
    cout<<"4. Afisati a doua operatie.\n";
    cout<<"5. Adunati cele doua operatii si aflati rezultatul.\n";
    cout<<"6. Adunati prima operatie cu un numar dat.\n";
    cout<<"0. Iesire.\n";
    cin>>o;
    switch(o){
      case 1:editare(&o1);break;
      case 2:editare(&o2);break;
      case 3:rezultat(o1);break;
      case 4:rezultat(o2);break;
      case 5:adunare(o1,o2);break;
      case 6:adunare_numar(o1);break;
      default: o=0;break;
    }
  }

}
