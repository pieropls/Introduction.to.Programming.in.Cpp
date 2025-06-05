#include <iostream>
using namespace std;

int main()
{
    int n(0);
    do {
        cout << "Entrez un nombre n > 1. Nous allons vérifier s'il est premier." << endl;
        cout << "n = ";
        cin >> n;
    } while (n <= 1);
    
    if (n == 2){
        cout << n << " est bien un nombre premier !" << endl;
        return 1;
    }
    if (n % 2 == 0){
        cout << n << " n'est pas un nombre premier ! Il est divisible par 2..." << endl;
        return 1;
    }

    int diviseur(2);
    for (int i(2); i < n; ++i){
        if(n % diviseur == 0){
            cout << n << " n'est pas un nombre premier ! Il est divisible par " << diviseur << " ..." << endl;
            return 1;
        }
        diviseur += 1;
    }
    cout << n << " est bien un nombre premier !" << endl;

    return 0;
}