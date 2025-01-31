#include <iostream>
using namespace std;

int main()
{
    cout << "Entrez un nombre réel : ";
    double x(0.0);
    cin >> x;
    
    // Définition des trois intervalles en utilisant uniquement '<' et '=='
    // Intervalle [-10, -2]
    bool int1 = (-10 < x && x < -2) || (x == -2);
    // Intervalle ]0,1]
    bool int2 = (0 < x && x < 1) || (x == 1);
    // Intervalle [2,3[
    bool int3 = (x == 2) || (2 < x && x < 3);

    // Vérification si x appartient à au moins un des intervalles
    if (int1 || int2 || int3) {
        cout << "x appartient à I !";
    } else {
        cout << "x n'appartient par à I !";
    }

    return 0;
}


