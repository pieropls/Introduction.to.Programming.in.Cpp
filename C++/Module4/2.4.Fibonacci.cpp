#include <iostream>
using namespace std;

int Fibonacci(int n);
int FibonacciIteratif(int n);

int main()
{
    int n(0);

    cout << "On va calculer le n-ième terme de la suite de Fibonacci." << endl;
    cout << "Entrez un entier n : ";
    cin >> n;

    cout << " -> Par la méthode récursive, F(" << n << ") = " 
         << Fibonacci(n) << "." << endl;
    cout << " -> Par la méthode itérative, F(" << n << ") = " 
         << FibonacciIteratif(n) << "." << endl;

    return 0;
}

int Fibonacci(int n)
{
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}

int FibonacciIteratif(int n)
{
    int Fn(0);     // stocke F(n), initialisé à 0
    int Fn_1(0);   // stocke F(n-1), initialisé à 0
    int Fn_2(1);   // stocke F(n-2), initialisé à 1 (pour que ça marche F(2))
    if (n > 0){
        for (int i(1); i <= n; ++i) {
            Fn = Fn_1 + Fn_2; // pour n>=1 on calcule F(n)=F(n-1)+F(n-2)
            Fn_2 = Fn_1;      // et on decale...
            Fn_1 = Fn;
        }
    }
    return Fn;
}