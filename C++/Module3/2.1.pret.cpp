#include <iostream>
using namespace std;

int main()
{
    double S0(0.0), r(0.0), ir(0.0);
    do {
        cout << "Quelle est la valeur de votre prêt S0 ? ";
        cin >> S0;
    } while (S0 <= 0);
    do {
        cout << "Quelle est la valeur du montant r payé chaque mois ? ";
        cin >> r;
    } while (r <= 0);
    do {
        cout << "Quelle est le taux d'intérêt mensuel ir (fixe) ? ";
        cin >> ir;
    } while ((ir <= 0) and (ir >= 1));

    double somme_restante(S0), i(0.0), somme(0.0);
    int nb_de_mois(0);
    while (somme_restante > 0.0) {
        nb_de_mois += 1;
        i = ir * somme_restante;
        somme_restante -= r;
        somme += (i + r);
    }
    cout << "La somme des intérêts encaissés (sur "
    << nb_de_mois << " mois) est de : " << somme-S0 << " euros." << endl;

    return 0;
}