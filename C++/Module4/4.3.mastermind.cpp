#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
  bool test((c == '.') || (c == 'R') || (c == 'G') || (c == 'B') || (c == 'C') || (c == 'Y') || (c == 'M'));
  return test;
}

// ======================================================================
bool verifier(char first_c, char& second_c, int& score)
{
  if (first_c == second_c) {
    second_c = 'x'; // Mark as used
    score += 1;
    return true;
  }
  return false;
}

// ======================================================================
void apparier(char proposed_c, char& ref_c1, char& ref_c2, char& ref_c3, int& score)
{
  if (verifier(proposed_c, ref_c1, score)) return;
  if (verifier(proposed_c, ref_c2, score)) return;
  verifier(proposed_c, ref_c3, score);
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
  int correct_c = 0, incorrect_c = 0, missing_c = 0;

  if (c1 == r1) { correct_c++; c1 = 'X'; r1 = 'x'; }
  if (c2 == r2) { correct_c++; c2 = 'X'; r2 = 'x'; }
  if (c3 == r3) { correct_c++; c3 = 'X'; r3 = 'x'; }
  if (c4 == r4) { correct_c++; c4 = 'X'; r4 = 'x'; }

  if (c1 != 'X') apparier(c1, r2, r3, r4, incorrect_c);
  if (c2 != 'X') apparier(c2, r1, r3, r4, incorrect_c);
  if (c3 != 'X') apparier(c3, r1, r2, r4, incorrect_c);
  if (c4 != 'X') apparier(c4, r1, r2, r3, incorrect_c);

  // Remaining incorrect guesses
  missing_c = 4 - correct_c - incorrect_c;

  // Display results
  afficher(correct_c, '#');
  afficher(incorrect_c, '+');
  afficher(missing_c, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
  bool test((c1 == r1) && (c2 == r2) && (c3 == r3) && (c4 == r4));
  return test;
}

// ======================================================================
void jouer(int max_shots = 8)
{
  int nb_shots(0);

  char r1(tirer_couleur()), r2(tirer_couleur()), r3(tirer_couleur()), r4(tirer_couleur());
  char c1('x'), c2('x'), c3('x'), c4('x');

  while (nb_shots < max_shots) {
    c1 = lire_couleur();
    c2 = lire_couleur();
    c3 = lire_couleur();
    c4 = lire_couleur();

    afficher_coup(c1,c2,c3,c4,r1,r2,r3,r4);

    if (gagne(c1, c2, c3, c4, r1, r2, r3, r4)) {
      message_gagne(nb_shots + 1);
      return;
    }

    nb_shots += 1; ;
  }

  message_perdu(r1, r2, r3, r4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
