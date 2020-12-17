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

  Punct a(2,0), b(0,2), c(0,-2), d(-2,0), e(1,-1),o(0,0);
  cout<<"\n\nTriunghi:\n\n";
  Triunghi t(a,b,c);
  cout<<"Punctele triunghiului sunt:\n";
  t.afiseazaPuncte();
  cout<<"\nPerimetrul triunghiului este: "<<t.perimetru()<<"\n";
  cout<<"O latura a triunghiului are panta: "<<pantaDreptei(t)<<"\n";

  cout<<"\n\nPatrulater:\n\n";
  Patrulater p(a,b,c,d);
  cout<<"Punctele patrulaterului sunt:\n";
  p.afiseazaPuncte();
  cout<<"\nPerimetrul patrulaterului este: "<<p.perimetru()<<"\n";
  cout<<"O latura a patrulaterului are panta: "<<pantaDreptei(p)<<"\n";

  cout<<"\n\nPentagon:\n\n";
  Pentagon pg(a,b,c,d,e);
  cout<<"Punctele pentagonului sunt:\n";
  pg.afiseazaPuncte();
  cout<<"\nPerimetrul pentagonului este: "<<pg.perimetru()<<"\n";
  cout<<"O latura a pentagonului are panta: "<<pantaDreptei(pg)<<"\n";

  try{
    cout<<"\n\nCerc\n\n";
    Cerc *c = Cerc::creeazaCerc(o,2);
    cout<<"\nPerimetrul cercului este: "<<c->perimetru()<<"\n";
    if(figuraPeCerc(*c,t))
      cout<<"Triunghiul este pe cerc!\n";
    else
      cout<<"Triunghiul nu este pe cerc!\n";

    if(figuraPeCerc(*c,p))
      cout<<"Patrulaterul este pe cerc!\n";
    else
      cout<<"Patrulaterul nu este pe cerc!\n";

    if(figuraPeCerc(*c,pg))
      cout<<"Paralelogramul este pe cerc!\n";
    else
      cout<<"Paralelogramul nu este pe cerc!\n";


    Cerc::creeazaCerc(o,1);
  }
  catch(int n)
  {
    cout<<"\n\nExceptie: Nu se mai poate crea inca un cerc!\n";
  }
  return 0;
}
