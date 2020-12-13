

## Enunt problema

Sa se implementeze un program ce va prezenta urmatorul scenariu:

 - clasa abstracta **Pasare** care va contine functia pur virtuala *zbroara* si functia pur virtuala *sunet*, care va afisa sunetul pe care pasarea il face.
 - clasa derivata **Papagal** care va adauga intr-o lista cuvinte pe care le stie papagalul, poate afisa cuvintele stiute de papagal, un sunet caracteristic papagalului si cat de departe poate sa zboare acesta.
 - clasa derivata **Gaina**, numarul maxim de gaini va fi 30 (numarul de instante ale clasei - se va folosi o variabila statica in interiorul clasei ce se va incrementa la instantierea unui element). O gaina poate sa zboare insa pe o distanta mai mica de 10 m. O gaina poate fi vanduta pe un alt tip de pasare.
 - clasa derivata **Strut**. Aceasta clasa este *singleton*. Un singur obiect de tip strut poate sa existe la un moment dat. Se va implementa adunarea intre un strut si o gaina (supraincarcarea operatorului +), rezultatul fiind incrementarea numarului de gaini continut de un strut si scaderea unei gaini din numarul de gaini introduse.
