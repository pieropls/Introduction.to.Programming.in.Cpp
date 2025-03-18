#include <iostream>
using namespace std;

int demander_un_nb(int inferieure, int superieure);

int main()
{
    cout << "On teste la fonction demander un nombre..." << endl;
    int n(demander_un_nb(0, 10));
    cout << n << " est bien compris entre 0 et 10 !";

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