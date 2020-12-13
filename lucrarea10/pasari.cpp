#include <iostream>
#include <list>

using namespace std;

// clasa abstracta Pasare care va contine functia pur virtuala `zbroara` si functia pur virtuala `sunet`
class Pasare{
public:
    Pasare(){};
    virtual void zboara(){};
    virtual void sunet(){};
};

// clasa derivata Papagal
class Papagal:public Pasare{
private:
    list<string> cuvinte_cunsocute;
public:
    Papagal(){}
    void invataCuvant(string cuvant)
    {
      cuvinte_cunsocute.push_front(cuvant);//adauga intr-o lista cuvinte pe care le stie papagalul
    }
    //afiseaza cuvintele stiute de papagal
    void spuneCuvintele()
    {
      cout << "Papagalul stie: ";
      list<string>::iterator cuv;
      for(cuv = cuvinte_cunsocute.begin(); cuv != cuvinte_cunsocute.end(); ++cuv)
        cout << *cuv << " | ";
      cout<<"\n";
    }
    //cat de departe poate sa zboare acesta
    void zboara()
    {
      cout << "Papagalul poate sa zboare sute de kilometri pe zi!\n";
    }
    //sunet caracteristic papagalului
    void sunet()
    {
      cout << "Papagalul canta cand e fericit!\n";
    }
};

//clasa derivata Strut
class Strut:public Pasare{

private:
    int nr_gaini;
    Strut():nr_gaini(0){}
    static Strut *strut;
public:
    //Aceasta clasa este singleton
    static Strut* verificaStrut()
    {
        if(!Strut::strut)
            Strut::strut = new Strut();
        return strut;
    }
    void adaugaGaina()
    {
      this->nr_gaini++;
    }
    void gainiStrut()
    {
      cout << "Strutul are " << nr_gaini << " gaini.\n";
    }
    void zboara()
    {
        cout << "Un strut nu poate zbura!\n";
    }
    void sunet()
    {
        cout <<"Piu piu!\n";
    }
};

// clasa derivata Gaina
class Gaina:public Pasare{
private:
    Gaina(){}
public:
    static int nr_gaini;
    static Gaina* cumparGaina()
    {
      if(Gaina::nr_gaini < 30)//numarul maxim de gaini va fi 30
      {
        Gaina *pui = new Gaina();
        Gaina::nr_gaini++;
        return pui;
      }
      else
        cout << "Nu poti avea mai mult de 30 de gaini!\n";
      return NULL;
    }
    void mutaGaina()
    {
      Gaina::nr_gaini--;
    }
    //O gaina poate fi vanduta pe un alt tip de pasare
    Pasare* vindeGaina(string tip_pasare)
    {
      if(tip_pasare == "papagal")
      {
          Gaina::nr_gaini--;
          return new Papagal();
      }
      else if(tip_pasare == "strut")
      {
        Gaina::nr_gaini--;
        return Strut::verificaStrut();
      }else
      {
        cout << tip_pasare << " nu exista!\n";
        return NULL;
      }
    }
    //O gaina poate sa zboare insa pe o distanta mai mica de 10 m
    void zboara()
    {
      cout << "Gaina zboara mai putin de 10m.\n";
    }
    void sunet()
    {
      cout << "Cotcodac!\n";
    }
};

//adunarea intre un strut si o gaina(supraincarcarea operatorului +)
inline const Strut operator+(Strut s, Gaina g)
{
  s.adaugaGaina();//incrementarea numarului de gaini continut de un strut
  g.mutaGaina();//scaderea unei gaini din numarul de gaini introduse
  return s;
}

int Gaina::nr_gaini = 0;
Strut *Strut::strut = NULL;


int main(){

    Gaina *g1 = Gaina::cumparGaina();
    Gaina *g2 = Gaina::cumparGaina();
    Gaina *g3 = Gaina::cumparGaina();
    Gaina *g4 = Gaina::cumparGaina();

    cout<< "Ai "<< Gaina::nr_gaini << " gaini in tarc.\n";
    cout << "\n\nGaina: \n";
    cout << "\t";g1->zboara();
    cout << "\t";g1->sunet();

    cout << "\n\nPapagal: \n";
    Papagal *p = (Papagal*)g3->vindeGaina("papagal");
    p->invataCuvant("buna");
    p->invataCuvant("biscuit");
    p->invataCuvant("haide");
    cout << "\t";p->spuneCuvintele();
    cout << "\t";p->zboara();
    cout << "\t";p->sunet();

    cout << "\n\nStrut: \n";
    Strut *strut1 = (Strut*)g2->vindeGaina("strut");
    cout << "\t";strut1->gainiStrut();
    cout << "\t";strut1->zboara();
    cout << "\t";strut1->sunet();
    cout << "\n\t";cout<<"Adaugam o gaina in tarcul strutului.\n";
    *strut1 = *strut1 + *g4;
    cout << "\t";strut1->gainiStrut();

    cout<< "\n\nMai ai "<< Gaina::nr_gaini << " gaini in tarc.\n";
    return 0;
}
