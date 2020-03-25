#include <bits/stdc++.h>
#include "Complex.h"

/**
D2 Clasa pentru numar complex, avand:
    - membrii privati pentru partea reala si partea imaginara (double);
    - constructori pentru initializare si copiere;
    - metode publice pentru setat/furnizat partea reala si partea imaginara;
    - metoda publica pentru citire;
    - metoda publica de afisare (sub forma "a", "i*a", "-i*a", "a+i*b", "a-i*b", dupa caz);
    - operatori friend: + (adunare), +(numarul insusi), - (scadere),  - (opus), * (inmultire),
    / (impartire), +=, -=, *=, /= (cu efectul  cunoscut), ^ (ridicare la putere naturala),
    == (test de egalitate),  != (test de neegalitate); operatorii binari +, -, *, /, ==,
    != se  scriu in cate trei variante, pentru a putea lucra cu operanzi  complex-complex,
    double-complex, complex-double; operatorii +=, -=, *=, /= se scriu in doua variante,
    pentru a putea lucra cu operanzi  complex-complex, complex-double.
    - functii friend: "abs" (furnizeaza modulul), "sqrt" (furnizeaza radicalul  de ordinul doi).
   Program de rezolvare a ecuatiei de ordinul doi cu coeficienti complecsi.
   Pentru clasa "complex" se va scrie un fisier header si un fisier de implementare.
Programul se va scrie ca un project.

*/
using namespace std;

int main()
{
    Complex z1;
    Complex z2;
    double a, b, c, delta, x;
    cout << "Ecuatia de forma: a * x^2 + b * x + c = 0\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        x = ( (-1) * b + sqrt(delta) ) / (2 * a);
        cout << "Prima solutie: " << x << "\n";
        z1 = z1 + x;
        x = ( (-1) * b - sqrt(delta) ) / (2 * a);
        cout << "A doua solutie: " << x << "\n";
        z2 = z2 + x;
    }
    else if (delta == 0)
    {
        x = (-1) * b / (2 * a);
        cout << "Solutia este: " << x << "\n";
        z1 += x;
    }
    else
    {
        x = (-1) * b / (2 * a);
        z1.Set_Re(x);
        x = sqrt(delta) / (2 * a);
        z1.Set_Im(x);
        cout << "Prima solutie: ";
        z1.Afisare();
        cout << "\n";
        x = (-1) * b / (2 * a);
        z2.Set_Re(x);
        x = (-1) * sqrt(delta) / (2 * a);
        z2.Set_Im(x);
        cout << "A doua solutie: ";
        z2.Afisare();
        cout << "\n";
    }
    return 0;
}
