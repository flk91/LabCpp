/*
Presi in input due numeri, mostrare a video il risultato delle 4 operazioni aritmetiche fondamentali.
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, somma, differenza, prodotto, quoziente1, resto;
    float quoziente2;

    cout << "Digitare il primo numero: ";
    cin >> a;

    cout << "Digitare il secondo numero: ";
    cin >> b;

    somma = a + b;
    cout << "La somma tra " << a << " e " << b << " vale: " << somma << "." << endl;

    differenza = a - b;
    cout << "La differenza tra " << a << " e " << b << " vale: " << differenza << "." << endl;

    prodotto = a * b;
    cout << "Il prodotto di " << a << " per " << b << " vale: " << prodotto << "." << endl;

    // dobbiamo ora calcolare quoziente e resto.
    // Tuttavia, non è possibile dividere un numero per zero.
    // poniamo una condizione per fare in modo che il nostro programma esegua operazioni diverse
    if (b != 0) {
        quoziente1 = a / b;
        cout << "Il quoziente (intero) di " << a << " diviso " << b << " e': " << quoziente1 << "." << endl;

        //problema. In c++ la divisione di due interi dà sempre quoziente intero, eliminando l'evenquale parte decimale.
        //un modo per superare questo problema è trasformare gli operandi (almeno uno dei due) in decimale
        //anteponendo il prefisso (float).
        quoziente2 = (float)a / (float)b;
        cout << "Il quoziente (decimale) di " << a << " diviso " << b << " e': " << quoziente2 << "." << endl;

        //L'operatore % (modulo) non ha significato di calcolo percentuale, ma di resto della divisione
        resto = a % b;
        cout << "Il resto della divisione di " << a << " per " << b << " e': " << resto << "." << endl;
    }
    else {
        cout << "Non e' possibile dividere un numero per zero." << endl;
    }
}
