#include <iostream>
using namespace std;

int main()
{
    cout << "Voici une application de l'algorithme d'Euclide pour le calcul de PGCD." << "\n" << endl;

    int a1(0), b1(0);
    do {
        cout << "-> Entrez un entier a >= b, a > 0 : ";
        cin >> a1;
    } while (a1 <= 0);
    do {
        cout << "-> Entrez un entier b <= a, b > 0 : ";
        cin >> b1;
    } while (b1 <= 0);

    cout << "\n";

    int a(a1), b(b1);
    int quotient(a / b), reste(a % b);

    while (reste > 0) {
        cout << a << " = " << b << " x " << quotient << " + " << reste << endl;
        a = b, b = reste;
        if (a % b == 0) {
            cout << a << " = " << b << " x " << a / b << " + " << a % b << endl;
            cout << "\n" << "Le PGCD étant le dernier reste non nul, on a : PGCD(" 
            << a1 << " ; " << b1 << ") = " << reste << "." << endl;
        }
        quotient = a / b, reste = a % b;
    }
    
    return 0;
}