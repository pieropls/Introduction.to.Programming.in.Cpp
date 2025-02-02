#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  do {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  } while (renards_i < 2);
  do {
    cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  } while (lapins_i < 5);
  
  // ===== PARTIE 2 =====
  // Première simulation
  double l(lapins_i), r(renards_i);
  double nb_l(lapins_i), nb_r(renards_i);

  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  for (int i(1); i <= duree; ++i){
    if (lapins_i > 0){
      l *= (1.0 + taux_croissance_lapins - taux_attaque * renards_i);
      l = max(0.0, l);
    }
    if (renards_i > 0){
      r *= (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
      r = max(0.0, r);
    }
    lapins_i = l, renards_i = r;
    cout << "Après " << i << " mois, il y a " << lapins_i << " lapins et " << renards_i << " renards" << endl;
  }
  
  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;

  // Taux d'attaques
  double taux_debut = 0, taux_fin = 0;
	do {
		cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
		cin >> taux_debut;
	} while ((taux_debut < 0.5) or (taux_debut > 6));
	do {
		cout << "taux d'attaque à la fin  en % (entre " << taux_debut << " et 6) ? ";
		cin >> taux_fin;
	} while (taux_fin < taux_debut or taux_fin > 6);

  // Boucle for principale
	for (double i(taux_debut); i <= taux_fin; i++) {

    bool test_extinction_l(false), test_extinction_r(false);
    int nb_de_mois(0);
    taux_attaque = i / 100.0;

    cout << endl << "***** Le taux d'attaque vaut " << i << "%" << endl;
    l = nb_l, r = nb_r, lapins_i = nb_l, renards_i = nb_r;

    // Boucle for secondaire
    for (int j(1); j <= duree; ++j){

      // Simulation imbriquée
      if (lapins_i >= 2){
          l *= (1.0 + taux_croissance_lapins - taux_attaque * renards_i);
          if (l < 2) l = 0;  // Force l'extinction si la population devient trop faible
      } else {
          l = 0;
      }
      if (renards_i >= 2){
        r *= (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
        if (r < 2) r = 0;
      } else {
        r = 0;
      }
      lapins_i = l, renards_i = r;

      nb_de_mois = j;
      // Break test
      if ((lapins_i == 0) and (renards_i == 0)){
        break;
      }
      // Extinction test
      if (lapins_i < 5 && !test_extinction_l){
        test_extinction_l = true;
      }
      if (renards_i < 5 && !test_extinction_r){
        test_extinction_r = true;
      }
    }
    
    cout << "Après " << nb_de_mois << " mois, il y a " << lapins_i << " lapins et " << renards_i << " renards" << endl;

    // Test renards
    if (test_extinction_r){
      cout << "Les renards ont été en voie d'extinction" << endl;
      if (renards_i == 0){
        cout << "et les renards ont disparu :-(" << endl;
      } else {
        cout << "mais la population est remontée ! Ouf !" << endl;
      }
		}

    // Test lapins
    if (test_extinction_l){
      cout << "Les lapins ont été en voie d'extinction" << endl;
      if (lapins_i == 0){
        cout << "et les lapins ont disparu :-(" << endl;
      } else {
        cout << "mais la population est remontée ! Ouf !" << endl;
      }
    }

    if (test_extinction_l == false and test_extinction_r == false and lapins_i != 0 and renards_i != 0){
			cout << "Les lapins et les renards ont des populations stables." << endl;
		}
	}

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
