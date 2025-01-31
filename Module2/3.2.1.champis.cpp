#include <iostream>
using namespace std;

int main()
{
     // Affichage de l'introduction du programme
     cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
          << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

     int reponse(0);

     // Première question : Le champignon a-t-il un chapeau convexe ?
     cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
     cin >> reponse;

     if (reponse == 0) { // Si le champignon n'a PAS de chapeau convexe
          // Deuxième question : Le champignon a-t-il des lamelles ?
          cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
          cin >> reponse;
          
          if (reponse == 0) { // Si le champignon N'A PAS de lamelles
               // Conclusion : Le champignon est le cèpe de Bordeaux
               cout << "==> Le champignon auquel vous pensez est ";
               cout << "le cèpe de Bordeaux";
          } else { // Si le champignon a des lamelles
               // Troisième question : Le champignon a-t-il un anneau ?
               cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
               cin >> reponse;
               
               if (reponse == 0) { // Si le champignon N'A PAS d'anneau
                    // Conclusion : Le champignon est la girolle
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "la girolle";
               } else { // Si le champignon a un anneau
                    // Conclusion : Le champignon est le coprin chevelu
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "le coprin chevelu";
               }
          }
     } else { // Si le champignon a un chapeau convexe
          // Deuxième question : Le champignon vit-il en forêt ?
          cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
          cin >> reponse;
          
          if (reponse == 0) { // Si le champignon ne vit PAS en forêt
               // Conclusion : Le champignon est l'agaric jaunissant
               cout << "==> Le champignon auquel vous pensez est ";
               cout << "l'agaric jaunissant";
          } else { // Si le champignon vit en forêt
               // Troisième question : Le champignon a-t-il un anneau ?
               cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
               cin >> reponse;
               
               if (reponse == 0) { // Si le champignon N'A PAS d'anneau
                    // Conclusion : Le champignon est le pied bleu
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "le pied bleu";
               } else { // Si le champignon a un anneau
                    // Conclusion : Le champignon est l'amanite tue-mouches
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "l'amanite tue-mouches";
               }
          }
     }

     return 0;
}


  
