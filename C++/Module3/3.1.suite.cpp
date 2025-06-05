#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
  for (int i(debut); i <= fin; ++i){
    int var(i), iterations(0);
    while (var > 0) {
      if (var % 3 == 0){
        var += 4;
      } else if (var % 4 == 0){
        var /= 2;
      } else {
        var -= 1;
      }
      iterations += 1;
    }
    cout << i << " -> " << iterations << endl;
  }
  

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
