#include <iostream>
#include <cmath>         // Inclusion de la bibliothèque mathématique pour utiliser sqrt()
using namespace std;

int main()
{
    // Déclaration et initialisation des coefficients du polynôme ax² + bx + c
    double a(0.0), b(0.0), c(0.0);

    // Demande à l'utilisateur d'entrer une valeur non nulle pour a
    cout << "Entrez une valeur non nulle pour a : "; 
    cin >> a;

    // Vérification que a est bien non nul
    if (a == 0.0) {
        // cerr est comme cout, mais pour les messages d'erreur. 
        cerr << "Erreur : a est nul !" << endl;
        return 1; // On quitte le programme !
    }

    // Demande à l'utilisateur d'entrer les coefficients b et c
    cout << "Entrez une valeur pour b : "; 
    cin >> b;
    cout << "Entrez une valeur pour c : "; 
    cin >> c;

    // Calcul du discriminant : delta = b² - 4ac
    double delta(b*b - 4*a*c);

    // Vérification de la nature des racines en fonction du discriminant
    if (delta < 0.0) {
        cout << "Votre polynôme n'admet pas de racines réelles !" << endl;
    } else if (delta == 0.0) {
        cout << "Votre polynôme admet une unique racine réelle : "
        << -b/2.0*a << "." << endl;
    } else {
        cout << "Votre polynôme admet deux racines réelles : " << endl;
        cout << "* " << (-b + sqrt(delta)) / 2.0*a << "." << endl; 
        cout << "* " << (-b - sqrt(delta)) / 2.0*a << "." << endl; 
    }

    return 0;
}