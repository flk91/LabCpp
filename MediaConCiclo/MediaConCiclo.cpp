// calcolare la media di una sequenza di numeri inseriti in input

#include <iostream>

using namespace std;

int main()
{
    int v, s = 0, c = 0; 
    float m;
    do {
        cout << "Inserire un valore. Digitare 0 per terminare" << endl;
        cin >> v;
        if (v > 0) {
            s += v;
            c++;
        }
    } while (v > 0);
    m = (float)s / (float)c;
    cout << "La media dei valori inseriti e': " << m << endl;
}