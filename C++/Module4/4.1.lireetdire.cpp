#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  nombre = nombre * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
  for (int i = 1; i <= 2; ++i){
    ajouter_chiffre_droit(nombre, repetitions_chiffre);
    repetitions_chiffre = chiffre;
  }
}

int lire_et_dire(int nombre)
{
  int right_dig = nombre;
  int left_dig = separer_chiffre_gauche(right_dig);
  int rep(1);
  int final_nb(0);

  while(left_dig != 0){
    int next_left_dig(separer_chiffre_gauche(right_dig));

    if (left_dig == next_left_dig) {
      rep +=1;
    } else {
      dire_chiffre(final_nb, rep, left_dig);
      rep = 1;
    }

    left_dig = next_left_dig;
  }

  return final_nb;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}