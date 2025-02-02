#include <iostream>
using namespace std;

int main()
{
    double u0(1.0), v0(0.0);
    cout << "U0 = " << u0 << endl;
    v0 = u0;
    cout << "V0 = " << v0 << endl;

    for (int i(0); i < 10; ++i){
        cout << "U" << i + 1 << " = " << u0 / (i + 1) << endl;
        u0 = u0 / (i + 1);
        v0 += u0;
        cout << "V" << i + 1 << " = " << v0 << endl;
    }

    return 0;
}