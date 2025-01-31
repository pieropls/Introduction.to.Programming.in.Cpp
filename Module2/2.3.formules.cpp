#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Entrez un nombre réel : ";
    double x(0.0);
    cin >> x;

    // Définition de plusieurs expressions booléennes utilisées pour vérifier si une expression mathématique est indéfinie
    // Vérifie si x est exactement égal à 0
    bool expr1(x == 0.0);
    // Vérifie si x est inférieur ou égal à 0 ou si x est exactement égal à 1
    bool expr2((x <= 0) || (x == 1));
    // Vérifie si x est exactement égal à 2 ou si x² < 8x
    bool expr3((x == 2.0) || (x*x < 8*x));
    // Vérifie si x² ≤ 1/x ou si l'expression (sin(x) - x/20) * log(x² - 1/x) est négative
    bool expr4((x*x <= 1.0/x) || ((sin(x) - x/20.0) * log(x*x - 1.0/x) < 0));

    // Vérification et affichage du résultat de l'expression 1
    if (expr1) {
        cout << "Expression 1 : indéfinie !" << endl;
    } else {
        cout << "Valeur de l'expression 1 : " << x / (1.0 - exp(x)) << "." << endl;
    }
    // De même pour les expressions 2,3,4
    if (expr2) {
        cout << "Expression 2 : indéfinie !" << endl;
    } else {
        cout << "Valeur de l'expression 2 : " << x * log(x) * exp(2.0 / (x - 1.0)) << "." << endl;
    }
    if (expr3) {
        cout << "Expression 3 : indéfinie !" << endl;
    } else {
        cout << "Valeur de l'expression 3 : " << (-x - sqrt(x*x - 8.0*x)) / (2.0 - x ) << "." << endl;
    }
    if (expr4) {
        cout << "Expression 4 : indéfinie !" << endl;
    } else {
        cout << "Valeur de l'expression 4 : " << sqrt((sin(x) - x/20.0) * log(x*x - 1.0/x)) << "." << endl;
    }

    return 0;
}