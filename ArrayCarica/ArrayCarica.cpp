#include <iostream>
#include <ctime>

using namespace std;

void carica(int vet[], int n);
void carica(float vet[], int n);
void carica_range(int vet[], int n, int vmin = 0, int vmax = 100);
void carica_range(float vet[], int n, float vmin=0, float vmax=100);
void carica_rand(int vet[], int n, int vmin = 0, int vmax = 1000);
void azzera(int vet[], int n, int v = 0);
void azzera(float vet[], int n, float v=0);

int main()
{
    srand(time(NULL));
    int vet[100];

    azzera(vet, 100);
}

// OVERLOADING
// L'overloading è la possibilità di dichiarare più funzioni aventi lo stesso nome, ma parametri di tipo e/o numero diverso.
// in fase di richiamo, il numero e tipo di parametri determinerà quale delle funzioni viene eseguita.

void carica(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Inserire " << i << ". valore: ";
        cin >> vet[i];
    }
}

void carica(float vet[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Inserire " << i << ". valore: ";
        cin >> vet[i];
    }
}

void carica_range(int vet[], int n, int vmin=0, int vmax=100)
{
    int v;
    for (int i = 0; i < n; i++) {
        do {
            cout << "Inserire " << i << ". valore: ";
            cin >> v;
            if (v >= vmin && v <= vmax) {
                vet[i] = v;
            }
            else {
                cout << "Valore " << v << " al di fuori dell'intervallo ammesso." << endl;
            }
        } while (v<vmin || v>vmax);
    }

}

void carica_range(float vet[], int n, float vmin=0, float vmax=100)
{
    float v;
    for (int i = 0; i < n; i++) {
        do {
            cout << "Inserire " << i << ". valore: ";
            cin >> v;
            if (v >= vmin && v <= vmax) {
                vet[i] = v;
            }
            else {
                cout << "Valore " << v << " al di fuori dell'intervallo ammesso." << endl;
            }
        } while (v<vmin || v>vmax);
    }
}

void carica_rand(int vet[], int n, int vmin, int vmax)
{
    int comp;
    
    for (int i = 0; i < n; i++) {
        comp = rand() % vmax + vmin;
        vet[i] = comp;
    }
    
}


void azzera(int vet[], int n, int v=0) {
    for (int i = 0; i < n; i++) {
        vet[i] == v;
    }
}

void azzera(float vet[], int n, float v = 0) {
    for (int i = 0; i < n; i++) {
        vet[i] == v;
    }
}

void visual(int vet[], int n) {

}