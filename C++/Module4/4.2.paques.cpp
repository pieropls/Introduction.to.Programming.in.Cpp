#include <iostream>
using namespace std;

int demander_annee();
void affiche_date(int year, int days);
int date_Paques(int year);

int main()
{
    int year(demander_annee());

    affiche_date(year, date_Paques(year));
    return 0;
}

int demander_annee()
{
    int year(0);

    do {
        cout << "Entrez une annee (1583-4000) : ";
        cin >> year;
    } while (year < 1583 || year > 4000);

    return year;
}

void affiche_date(int year, int days)
{
    if(days >= 22 && days <=56){
        cout << "Date de Paques en " << year << " : ";
        if (days <= 31) {
            cout << days << " mars";
        } else if (days >= 32){
            cout << days - 31 << " avril";
        }
    }
}

int date_Paques(int year)
{
    int century(year / 100);
    int p((13 + 8*century) / 25);
    int q(century / 4);
    int M ((15 - p + century - q) % 30);
    int N((4 + century - q) % 7);
    int d((M + (19 * (year % 19))) % 30);
    int e((2 * (year % 4) + 4 * (year % 7) + 6 * d + N) % 7);
    int day = e + d + 22;

    if ((e == 6) && ((d == 29) || ((d == 28) && (((11*(M+1))%30) < 19)))){
        day -= 7;
    }
    return day;
}

