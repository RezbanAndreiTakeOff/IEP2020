

## Enunt problema


Considerand clasa de baza **Figura**, construiti 3 clase derivate care sa implementeze figuri geometrice si perimetrul acestora (cu numar diferit de laturi).

- Fiecare figura contine un vector (sau lista) de puncte.

 - Clasa **Punct** detine coordonatele unui punct in axele x si y.

Se va folosi o *functie template* pentru a afla panta dreptei formata din oricare doua puncte ale unei figuri geometrice - se poate face pentru primele doua puncte din lista de puncte a figurii.

Se va crea clasa *singleton* **Cerc**, cu o raza specificata si un punct de origine. O *functie template* va fi implementata pentru a determina daca o figura se afla pe cerc (verificam daca punctele ce creaza figura, de forma (X,Y), satisfac relatia matematica (x-a)^2+ (y-b)^2=R^2, unde a si b sunt coordonatele centrului C(a,b)-daca satisfac relatia atunci se afla pe cerc).
- !!Crearea unui nou cerc va arunca o eroare ce va fi prinsa pentru ca iesirea din program sa nu fie brusca.

In **main** se va crea un meniu care va permite:
 1. adaugarea de figuri geometrice de tipurile alese
 2. adaugarea de puncte
 3. modificarea punctelor
 4. afisarea pantei dreptei pe o figura aleasa
 5. crearea unui cerc
 6. verificarea daca o figura are puncte pe cerc
