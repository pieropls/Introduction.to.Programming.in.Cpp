#include <iostream>
using namespace std;

int main()
{
    // Définition des constantes et des ingrédients de base pour 4 personnes
    const int BASE(4);       // NB : BASE est une constante qui ne change jamais au cours du programme !
    double fromage(800.0);
    double eau(2.0);
    double ail(2.0);
    double pain(400.0);

    // Demande du nombre de convives à l'utilisateur
    cout << "Entrez le nombre de personne(s) conviées à la fondue : ";
    int nb_convives;
    cin >> nb_convives;
    cout << endl;

    // Calcul du ratio pour ajuster les ingrédients
    double ratio = nb_convives;
    ratio /= BASE;

    // Ajustement des ≠ quantités
    fromage *= ratio;
    eau *= ratio;
    ail *= ratio;
    pain *= ratio;
    
    // Affichage
    cout << "Pour faire une fondue fribourgeoise pour " << nb_convives << " personnes, il vous faut :" << endl;
    cout << "- " << fromage << " gr de Vacherin fribourgeois ;" << endl;
    cout << "- " << eau << " dl d'eau ;" << endl;
    cout << "- " << ail << " gousse(s) d'ail ;" << endl;
    cout << "- " << pain << " gr de pain ;" << endl;
    cout << "- du poivre à volonté." << endl;

    return 0;
}