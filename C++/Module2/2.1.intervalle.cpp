#include <iostream>
using namespace std;

int main()
{
    // Demande à l'utilisateur d'entrer un nombre réel
    cout << "Entrez un nombre réel : ";
    // Déclaration et initialisation de la variable x à 0.0 + lecture
    double x(0.0);
    cin >> x;

    // Vérification si x appartient à l'intervalle [-1, 1[
    if ((-1.0 <= x) and (x < 1.0)) {
        cout << "x appartient à I !";
    } else {
        cout << "x n'appartient par à I !";
    }

    return 0;
}