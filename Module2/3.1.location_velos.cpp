#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  // Vérification que les heures de début et de fin sont comprises entre 0 et 24
  if ((not((0 <= debut) and (debut <= 24))) or (not((0 <= fin) and (fin <= 24)))) {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    return 1;
  }

  // Vérification que la durée de location est correcte
  if (debut == fin){
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    return 1;
  }

  // Vérification que l'heure de début est bien avant l'heure de fin
  if (debut > fin){
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
    return 1;
  }

  // Déclaration et initialisation des compteurs d'heures pour chaque tarif
  int nb_h_tarif_bas(0), nb_h_tarif_elv(0);

  // Calcul du nombre d'heures au tarif bas (1 franc de l'heure)
  // - Plage horaire tarif bas : avant 7h et après 17h
  // - On prend le maximum entre (7 - début) pour éviter les valeurs négatives
  // - On prend aussi le maximum entre (fin - 17) pour compter les heures après 17h
  // - La valeur finale est limitée par la durée totale de location
  nb_h_tarif_bas = min(max((7 - debut), 0) + max((fin - 17), 0), fin - debut);

  // Calcul du nombre d'heures au tarif élevé (2 francs de l'heure)
  // - Plage horaire tarif élevé : entre 7h et 17h
  // - On compte les heures comprises entre début et fin dans cette tranche horaire
  nb_h_tarif_elv = min(fin, 17) - max(debut, 7);

  // Cas 1 : Location uniquement au tarif élevé
  if ((nb_h_tarif_bas <= 0) and (nb_h_tarif_elv > 0)){
    cout << "Vous avez loué votre vélo pendant" << endl;
    cout << nb_h_tarif_elv << " heure(s) au tarif horaire de "
    << 2 << " franc(s)" << endl;
    cout << "Le montant total à payer est de "
    << 2 * nb_h_tarif_elv << " franc(s)." << endl;
  }

  // Cas 2 : Location uniquement au tarif bas
  if ((nb_h_tarif_bas > 0) and (nb_h_tarif_elv <= 0)){
    cout << "Vous avez loué votre vélo pendant" << endl;
    cout << nb_h_tarif_bas << " heure(s) au tarif horaire de "
    << 1 << " franc(s)" << endl;
    cout << "Le montant total à payer est de "
    << nb_h_tarif_bas << " franc(s)." << endl;
  }

  // Cas 3 : Location avec un mix des deux tarifs
  if ((nb_h_tarif_bas > 0) and (nb_h_tarif_elv > 0)){
    cout << "Vous avez loué votre vélo pendant" << endl;
    cout << nb_h_tarif_bas << " heure(s) au tarif horaire de "
    << 1 << " franc(s)" << endl;
    cout << nb_h_tarif_elv << " heure(s) au tarif horaire de "
    << 2 << " franc(s)" << endl;
    cout << "Le montant total à payer est de "
    << nb_h_tarif_bas + 2 * nb_h_tarif_elv << " franc(s)." << endl;
  }
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
