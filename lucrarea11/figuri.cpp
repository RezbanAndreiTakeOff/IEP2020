#include <iostream>
#include <list>
#include <cmath>

using namespace std;

//clasa Punct detine coordonatele unui punct in axele x si y
class Punct{
private:
    int x,y;
public:
    Punct(int a,int b):x(a),y(b){}
    int getX()
    {
      return x;
    }
    int getY()
    {
      return y;
    }
    void setX(int a)
    {
      x=a;
    }
    void setY(int b)
    {
      y=b;
    }
};

// clasa de baza Figura
class Figura{
protected:
    list<Punct> puncte;
public:
    float perimetru()
    {
      list<Punct>::iterator p;
      Punct aux = puncte.back();
      float perimetru = 0;
      for(p = puncte.begin(); p != puncte.end(); ++p)
      {
        perimetru += sqrt(pow((p->getX()-aux.getX()),2)+pow((p->getY()-aux.getY()),2));
        aux = *p;
      }
      return perimetru;
    }
    list<Punct> puncteFigura()
    {
      return puncte;
    }
    void seteazaPuncte(list<Punct> p)
    {
      puncte = p;
    }
    void afiseazaPuncte()
    {
      list<Punct>::iterator p;
      for(p = puncte.begin(); p != puncte.end(); ++p)
        cout<<"("<<p->getX()<<","<<p->getY()<<")"<<" ";
    }
};


class Triunghi:public Figura{
public:
    Triunghi(Punct a,Punct b, Punct c)
    {
      puncte.push_front(a);
      puncte.push_front(b);
      puncte.push_front(c);
    }
};

class Patrulater:public Figura{
public:
    Patrulater(Punct a,Punct b, Punct c,Punct d)
    {
      puncte.push_front(a);
      puncte.push_front(b);
      puncte.push_front(c);
      puncte.push_front(d);
    }
};

class Pentagon:public Figura{
public:
    Pentagon(Punct a,Punct b, Punct c,Punct d,Punct e)
    {
      puncte.push_front(a);
      puncte.push_front(b);
      puncte.push_front(c);
      puncte.push_front(d);
      puncte.push_front(e);
    }
};

//clasa singleton cerc, cu o raza specificata si un punct de origine
class Cerc:public Figura{
private:
    int raza;
    Cerc(Punct o, int r):raza(r)
    {
      puncte.push_front(o);
    }
    static Cerc *c;
public:
    static Cerc* creeazaCerc(Punct o, int r)
    {
      if(!Cerc::c)
      {
          Cerc::c = new Cerc(o,r);
          return c;
      }
      else
        throw r;//crearea unui nou cerc va arunca o eroare ce va fi prinsa pentru ca iesirea din program sa nu fie brusca
    }
    int razaCerc()
    {
      return raza;
    }
    float perimetru()
    {
      return 6.3*raza;
    }
};

// functie template pentru a afla panta dreptei formata din oricare doua puncte ale unei figuri geometrice
template <class Figura>
float pantaDreptei(Figura fig)
{
  list<Punct> puncte = fig.puncteFigura();
  Punct a = puncte.front();
  Punct b = puncte.back();
  float aux = b.getY() - a.getY();
  return aux/(b.getX() - a.getX());
}

//functie template va fi implementata pentru a determina daca o figura se afla pe cerc
template <class Figura>
int figuraPeCerc(Cerc c,Figura fig)
{
    list<Punct> puncte = fig.puncteFigura();
    Punct centru = c.puncteFigura().front();
    int r = c.razaCerc();
    list<Punct>::iterator p;
    for(p = puncte.begin(); p != puncte.end(); ++p)
        if(pow(p->getX()-centru.getX(), 2) + pow(p->getY()-centru.getY(), 2) != pow(r,2))
            return 0;
    return 1;
}

Cerc *Cerc::c = NULL;

int main(){

  Figura figuri[20];
  Cerc *c = NULL;
  int op=1,n=0;
  while(op>=1 && op<=9)
  {
    cout<<"\n\nAlege o optiune:\n";
    cout<<"1. Adauga un triunghi\n";
    cout<<"2. Adauga un patrulater\n";
    cout<<"3. Adauga un pentagon\n";
    cout<<"4. Adauga un cerc\n";
    cout<<"5. Calculeaza panta laturii unei figuri alese\n";
    cout<<"6. Vezi perimetrul unei figuri alese\n";
    cout<<"7. Vezi perimetrul cercului\n";
    cout<<"8. Schimba unul sau mai multe puncte ale unei figuri alese\n";
    cout<<"9. Vezi daca o figura aleasa se afla sau nu pe cerc\n";
    cout<<"Alta valoare -> Exit\n";
    cin>>op;
    switch(op)
    {
      case 1:
      {
        cout<<"Introdu coordonatele celor 3 puncte ale triunghiului:\n";
        int x,y;
        Punct *p[3];
        for(int i=0;i<3;i++)
        {
          cout<<"x"<<i+1<<"=";
          cin>>x;
          cout<<"y"<<i+1<<"=";
          cin>>y;
          p[i] = new Punct(x,y);
        }
        Triunghi t(*p[0],*p[1],*p[2]);
        figuri[n] = t;
        n++;
        break;
      }
      case 2:
      {
        cout<<"Introdu coordonatele celor 4 puncte ale patrulaterului:\n";
        int x,y;
        Punct *p[4];
        for(int i=0;i<4;i++)
        {
          cout<<"x"<<i+1<<"=";
          cin>>x;
          cout<<"y"<<i+1<<"=";
          cin>>y;
          p[i] = new Punct(x,y);
        }
        Patrulater pa(*p[0],*p[1],*p[2],*p[3]);
        figuri[n] = pa;
        n++;
        break;
      }
      case 3:
      {
        cout<<"Introdu coordonatele celor 5 puncte ale pentagonului:\n";
        int x,y;
        Punct *p[5];
        for(int i=0;i<5;i++)
        {
          cout<<"x"<<i+1<<"=";
          cin>>x;
          cout<<"y"<<i+1<<"=";
          cin>>y;
          p[i] = new Punct(x,y);
        }
        Pentagon pg(*p[0],*p[1],*p[2],*p[3],*p[4]);
        figuri[n] = pg;
        n++;
        break;
      }
      case 4:
      {
        try{
          cout<<"Introdu coordonatele centrului cercului:\n";
          int x,y,r;
          cout<<"x"<<"=";
          cin>>x;
          cout<<"y"<<"=";
          cin>>y;
          Punct o(x,y);
          cout<<"Introdu lungimea razei cercului:";
          cin>>r;
          c = Cerc::creeazaCerc(o,r);
        }
        catch(int n)
        {
          cout<<"\n\nExceptie: Nu se mai poate crea inca un cerc!\n";
        }
        break;
      }
      case 5:
      {
        cout<<"Introdu indicele figurii pentru care se va calcula panta:\n";
        int i;
        cin>>i;
        cout<<"\nPanta unei laturi din figura "<<i<<" este "<<pantaDreptei(figuri[i])<<"\n";
        break;
      }
      case 6:
      {
        cout<<"Introdu indicele figurii pentru care se va calcula perimetrul (intre 0 si "<<n<<"):\n";
        int i;
        cin>>i;
        cout<<"\nPerimetrul figurii "<<i<<" este "<<figuri[i].perimetru()<<"\n";
        break;
      }
      case 7:
      {
        cout<<"\nPerimetrul cercului este "<<c->perimetru()<<"\n";
        break;
      }
      case 8:
      {
        cout<<"Introdu indicele figurii pentru care se vor schimba punctele (intre 0 si "<<n<<"):\n";
        int i,x,y;
        cin>>i;
        list <Punct> puncte, puncte_noi;
        puncte = figuri[i].puncteFigura();
        list<Punct>::iterator p;
        for(p = puncte.begin(); p != puncte.end(); ++p)
        {
          cout<<"Reintroduceti valorile punctului ("<<p->getX()<<","<<p->getY()<<"):";
          cin>>x>>y;
          Punct aux(x,y);
          puncte_noi.push_front(aux);
        }
        figuri[i].seteazaPuncte(puncte_noi);
        cout<<"\nPunctele figurii "<<i<<" au fost modificate.\n";
        break;
      }
      case 9:
      {
        cout<<"Introdu indicele figurii pentru care se va verifica daca se afla pe cerc (intre 0 si "<<n<<"):\n";
        int i;
        cin>>i;
        cout<<"Figura "<<i;
        if(!figuraPeCerc(*c,figuri[i]))
          cout<<" nu";
        cout<<" se afla pe cerc\n";
        break;
      }
      default: break;
    }
  }
  return 0;
}
