#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double g(9.81);

    double H0(0.0);
    double eps(0.0);
    int nbr(0);
    do {
        cout << "Insérez la hauteur initiale H0 : ";
        cin >> H0;
    } while (H0 <= 0);
    do {
        cout << "Insérez le coefficient de rebond eps : ";
        cin >> eps;
    } while (not((eps < 1) and (eps >= 0)));
    do {
        cout << "Insérez le nombres de rebonds nbr : ";
        cin >> nbr;
    } while (nbr < 0);
    
    if (nbr == 0) {
        cout << "Hauteur après 0 rebond : " << H0 << "." << endl;
    }

    double v(0.0), v1(0.0), h(0.0);;
    v = sqrt(2 * H0 * g);
    v1 = eps * v;
    for (int i(1); i <= nbr; ++i){
        h = pow(v1, 2) / (2 * g);
        v = sqrt(2 * h * g);
        v1 = eps * v;
    }

    cout << "Hauteur après " << nbr << " rebonds : " << h << "." << endl;

    return 0;
}