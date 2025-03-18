#include <iostream>
using namespace std;

int somme(int n);

int main()
{
    char rep('n'); 
    do {
        int n(0);
        cout << "Veuillez entrer un entier n : ";
        cin >> n;
        cout << "La somme des " << n << " premiers entiers naturels est de : " 
             << somme(n) << "." << endl;
        
        do {
            cout << "Voulez-vous recommencer [o/n] ? "; cin >> rep;
        } while ((rep != 'o') and (rep != 'n'));
    } while (rep == 'o');
    
    return 0;
}

int somme(int n)
{
    if (n <= 0){
        return 0;
    } else {
        return (n + somme(n-1));
    }
}