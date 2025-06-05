#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double g(9.81);

    double H0(0.0);
    double eps(0.0);
    double h_fin(0.0);
    do {
        cout << "Insérez la hauteur initiale H0 : ";
        cin >> H0;
    } while (H0 <= 0);
    do {
        cout << "Insérez le coefficient de rebond eps : ";
        cin >> eps;
    } while (not((eps < 1) and (eps >= 0)));
    do {
        cout << "Insérez la hauteur finale désirée : ";
        cin >> h_fin;
    } while (not((h_fin < H0) and (h_fin > 0)));

    double v(0.0), v1(0.0), h(0.0);
    int rebonds(0);
    v = sqrt(2 * H0 * g);
    v1 = eps * v;
    do {
        h = pow(v1, 2) / (2 * g);
        v = sqrt(2 * h * g);
        v1 = eps * v;
        rebonds += 1;
    } while (h > h_fin);

    cout << "La balle rebondit " << rebonds
    << " foi(s) avant que la hauteur de rebond (" << H0
    << ") soit inférieure à la limite de " << h_fin << "." << endl;

    return 0;
}