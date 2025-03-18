#include <iostream> 
using namespace std;

double moyenne (double nombre1, double nombre2);

int main() 
{
    double note1, note2;
    cout << "Entrez vos deux notes :" << endl; cin >> note1 >> note2;
    cout << "Votre moyenne est : " << moyenne(note1, note2) << endl;
    
    return 0; 
}

double moyenne(double nombre1, double nombre2) 
{
    return (nombre1 + nombre2) / 2.0; 
}