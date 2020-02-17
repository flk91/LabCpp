#include <iostream>

using namespace std;

void carica(int vet[], int n);
float mediaValori(int vet[], int n);

int main()
{
    int voti1[40], voti2[40];
    int nalu1, nalu2;
    float m1, m2;

    do {
        cout << "Quanti alunni nel primo gruppo?: ";
        cin >> nalu1;
    } while (nalu1 < 1 || nalu1>40);

    do {
        cout << "Quanti alunni nel secondo gruppo?: ";
        cin >> nalu2;
    } while (nalu2 < 1 || nalu2>40);

    cout << "Carichiamo i voti del primo gruppo.\n";
    carica(voti1, nalu1);

    cout << "Carichiamo i voti del secondo gruppo.\n";
    carica(voti2, nalu2);

    m1 = mediaValori(voti1, nalu1);
    m2 = mediaValori(voti2, nalu2);

    cout << "La media voti del primo gruppo di alunni e': " << m1 << endl;
    cout << "La media voti del secondo gruppo di alunni e': " << m2 << endl;

    if (m1 == m2) {
        cout << "I due gruppi hanno la stessa media dei voti" << endl;
    }
    else {
        if (m1 > m2) {
            cout << "Il primo gruppo ha la media piu' elevata" << endl;
        }
        else {
            cout << "Il secondo gruppo ha la media piu' elevata" << endl;
        }
    }


}


void carica(int vet[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << "Digitare " << i << ". valore: ";
        cin >> vet[i];
    }
}

/**
 * trova la media dei valori contenuti in un vettore
 */
float mediaValori(int vet[], int n) {
    int i, s=0, c=0;
    float m;
    for (i = 0; i < n; i++) {
        c++;
        s += vet[i];
    }

    m = (float)s / (float)c;
    return m;
}