#include <iostream>
using namespace std;

int main()
{
    int n(0);
    do {
        cout << "Entrez le nombre d'étagnes n>0 du triangle : ";
        cin >> n;
    } while (n <= 0);

    int nb_etoiles_final(n*2 - 1);
    int k(0);

    for (int i(0); i < n; ++i){
        
        for (int j(k); j < nb_etoiles_final / 2; ++j) {
            cout << " "; 
        }
        for (int j(0); j < 2*i + 1; ++j) { 
            cout << "*";
        }
        cout << endl;
        k += 1;
    }

    return 0;
}