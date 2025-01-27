#include <iostream>
using namespace std;

int main()
{
    // Demande à l'utilisateur de saisir son âge
    cout << "Entrez votre âge (en nombre d'années) : ";
    int age;     // Déclaration var âge
    cin >> age;  // Lecture de l'âge saisi

    // Calcul de l'année de naissance
    int annee(2025 - age);

    // Affichage
    cout << "Votre année de naissance est : "
    << annee << "." << endl;

    return 0;
}