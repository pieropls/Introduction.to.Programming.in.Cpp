#include <iostream>
using namespace std;

int main()
{
    cout << "Tables de multiplication" << endl;
    cout << "\n";
    for (int i(2); i <= 10; ++i) {
        cout << "------------" << endl;
        cout << "Table de " << i << " :" << endl;
        cout << "------------" << endl;
        for (int j(1); j <= 10; ++j){
            cout << j << " x " << i << " = " << i*j << endl;
        }
        cout << "------------" << endl;
        cout << "\n";
    }

    return 0;
}