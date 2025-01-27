#include <iostream>
using namespace std;

int main()
{
    // Initialisation des variables x et y
    double x(2), y(4);
    double a, b, c, d;

    // Calcul des différentes opérations entre x et y
    a = x + y; b = x - y;
    c = x * y; d = x / y;

    // Affichage
    cout << "La somme de " << x << " et de " << y << " vaut : " << a << "." << endl;
    cout << "La différence de " << x << " et de " << y << " vaut : " << b << "." << endl;
    cout << "Le produit de " << x << " par " << y << " vaut : " << c << "." << endl;
    cout << "Le quotient de " << x << " par " << y << " vaut : " << d << "." << endl;

    return 0;
}