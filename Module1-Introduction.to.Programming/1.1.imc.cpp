#include <iostream>
using namespace std;

int main()
{
    // Initialisation des variables pour le poids (en kg) et la taille (en m)
    double poids(67);
    double taille(1.8);

    // Demande + lecture des données de l'utilisateur
    cout << "Insérez votre poids (en Kg) : ";
    cin >> poids; 
    cout << "Insérez votre taille (en m) : ";
    cin >> taille;

    // Calcul de l'IMC. Formule : IMC = poids / (taille * taille)
    double imc(poids / (taille * taille));
    
    // Affichage
    cout << "Pour " << poids
    << " kg et " << taille
    << " m, l'IMC est de " 
    << imc << "." << endl;

    return 0;
}