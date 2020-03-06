#include <iostream>

using namespace std;

int main()
{   
    int a, b, scambio;

    cout << "********************************\n";
    cout << "*   Scambio di due variabili   *\n";
    cout << "********************************\n\n";

    cout << "Digitare valore A: ";
    cin >> a;
    cout << "Digitare valore B: ";
    cin >> b;

    scambio = a;
    a = b;
    b = scambio;

    cout << "I dati nelle due variabili sono stati scambiati.\n";
    cout << "A ora vale: " << a << endl;
    cout << "B ora vale: " << b << endl;
}
