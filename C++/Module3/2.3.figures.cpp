#include <iostream>
using namespace std;

int main()
{
    int figure(0);
    do {
        cout << "Entrez la figure que vous voulez effectuer (1 à 4) : ";
        cin >> figure;
    } while ((figure <= 0) and (figure >= 5));

    if (figure == 1){
        for (int i(1); i < 10; ++i){
            cout << i;
        }
        return 1;
    }
    if (figure == 2){
        for (int i(1); i < 10; ++i){
            for (int j(1); j < 10; ++j){
                cout << j;
            }
            cout << endl;
        }
        return 1;
    }
    if (figure == 3){
        for (int i(1); i < 10; ++i){
            for (int j(1); j < i+1; ++j){
                cout << j;
            }
            cout << endl;
        }
        return 1;
    }
    if (figure == 4){
        for (int i(1); i < 10; ++i){
            for (int j(1); j <= (9-i); ++j){
                cout << " ";
            }
            for (int j(1); j < i+1; ++j){
                cout << j;
            }
            cout << endl;
        }
        return 1;
    }

    return 0;    
}