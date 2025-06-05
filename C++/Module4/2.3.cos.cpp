#include <iostream>
#include <cmath>
using namespace std;

int demander_un_nb(int inferieure, int superieure);
double factorielle(int k);
double somme_partielle(double x, int N);

int main()
{
    cout.precision(16);
    int N(demander_un_nb(2, 85));
    double x(0.0);

    do {
        cout << "Entrez une valeur x pour le calcul de cos(x) : ";
        cin >> x;
        cout << "cos(" << x << ") ~ " << somme_partielle(x, N) << endl;
    } while (x != 0.0);

    return 0;
}

int demander_un_nb(int inferieure, int superieure)
{
    int retour(0);
    
    do {
        cout << "Veuillez saisir un nombre n tel que : "
             << inferieure << " <= n <= " << superieure << endl;
        cin >> retour;
    } while(retour < inferieure or retour > superieure);

    return retour;
}

double factorielle(int k){
    double factorielle(1.0);

    for (int i = 1; i <= k; ++i){
        factorielle *= i;
    }

    return factorielle;
}

double somme_partielle(double x, int N){
    double somme(0.0);

    for (int i = 0; i <= N; ++i){
        somme += ( pow((-1.0), i) * pow(x, 2*i) ) / factorielle(2*i);
    }

    return somme;
}