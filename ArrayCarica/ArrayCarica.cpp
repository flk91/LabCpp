#include <iostream>
#include <ctime>

#define MAX_EL 100

using namespace std;

int menu();
int quanti_elementi(int max_el, int min_el=1);
void array_carica(int vet[], int n);
void array_carica(float vet[], int n);
void array_carica_range(int vet[], int n, int vmin = 0, int vmax = 100);
void array_carica_range(float vet[], int n, float vmin=0, float vmax=100);
void array_carica_rand(int vet[], int n, int vmin = 0, int vmax = 1000);
void array_azzera(int vet[], int n, int v = 0);
void array_azzera(float vet[], int n, float v=0);

void array_visual(int vet[], int n);

template<class T>
void array_visual_generica(T vet[], int n);

// Main program
int main()
{
    srand(time(NULL));
    int vet[MAX_EL], elementi, scelta;
    float vet2[MAX_EL];
    array_azzera(vet, 100);
    
    do {
        scelta = menu();

        array_azzera(vet, MAX_EL);

        switch (scelta) {
        case 1: // caricamento con interi
            elementi = quanti_elementi(MAX_EL);
            array_carica(vet, elementi);
            array_visual_generica<int>(vet, elementi);
            break;
        case 2: // caricamento manuale con float
            elementi = quanti_elementi(MAX_EL);
            array_carica(vet2, elementi);
            break;
        default:
            cout << "Scelta non riconosciuta" << endl;
        }

    } while (scelta != 9);

  
}


int menu() {
    int scelta;

    cout << "***************************" << endl;
    cout << "*   CARICAMENTO VETTORI   *" << endl;
    cout << "***************************" << endl << endl;

    cout << "1. Carica con valori interi" << endl;
    cout << "2. Carica con valori decimali" << endl;
    cout << "3. Carica con valori interi in un range" << endl;
    cout << "4. Carica con valori decimali in un range" << endl;
    cout << "5. Carica con valori interi casuali" << endl;
    cout << "---" << endl;
    cout << "9. esci" << endl;

    cout << "N. SCELTA:> ";
    cin >> scelta;

    return scelta;
}


// Richiede all'utente quanti elementi intende inserire in un vettore
// e restituisce il numero dopo averne eseguito la convalida
// @param max_el numero massimo di elementi ammesso
// @returns numero di elementi desiderato
int quanti_elementi(int max_el, int min_el) {
    int e;
    do {
        cout << "Quanti elementi vuoi inserire? [1-" << max_el <<"]: ";
        cin >> e;

        if (!(e >= 1 && e <= max_el)) {
            cout << "Numero elementi non compreso tra 1 e " << max_el << endl;
        }
    } while (!(e >= 1 && e <= max_el));
    return e;
}

// OVERLOADING
// L'overloading è la possibilità di dichiarare più funzioni aventi 
// lo stesso nome, ma parametri di tipo e/o numero diverso.
// in fase di richiamo, il numero e tipo di parametri determinerà 
// quale delle funzioni viene eseguita.
// Nell'esempio che segue, la funzione array_carica è definita due volte:
// 1. per un vettore di int
// 2. per un vettore di float
// La funzione giusta tra le due viene richiamata in base ai dati forniti in input.
//------------------------------------------------------------------

// Carica un array con valori interi
// @param int vet il vettore
// @n numero di elementi
void array_carica(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Inserire " << i << ". valore: ";
        cin >> vet[i];
    }
}

// Carica un array con valori decimali
// @param vet il vettore da caricare
// @param n numero di elementi
void array_carica(float vet[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "Inserire " << i << ". valore: ";
        cin >> vet[i];
    }
}

// Carica un vettore con valori interi presi in input assicurando che questi
// siano compresi in un range
// @param vet vettore da caricare
// @param n numero elementi
// @param vmin valore minimo ammesso (compreso)
// @param vmax valore massimo ammesso (compreso)
void array_carica_range(int vet[], int n, int vmin, int vmax)
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

// Carica un vettore con valori decimali presi in input assicurando che questi
// siano compresi in un range
// @param vet vettore da caricare
// @param n numero elementi
// @param vmin valore minimo ammesso (compreso)
// @param vmax valore massimo ammesso (compreso)
void array_carica_range(float vet[], int n, float vmin, float vmax)
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

// Riempie un vettore con numeri casuali
// @param vet vettore da riempire
// @param n numero di elementi
// @param vmin valore minimo da generare
// @param vmax valore massimo da generare
void array_carica_rand(int vet[], int n, int vmin, int vmax)
{
    int comp;
    
    for (int i = 0; i < n; i++) {
        comp = rand() % vmax + vmin;
        vet[i] = comp;
    }
    
}

// Inizializza un vettore
// @param vet il vettore da inizializzare
// @param n numero di elementi
// @param v valore con cui riempire
void array_azzera(int vet[], int n, int v) {
    for (int i = 0; i < n; i++) {
        vet[i] = v;
    }
}

void array_azzera(float vet[], int n, float v) {
    for (int i = 0; i < n; i++) {
        vet[i] = v;
    }
}

void array_visual(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vet[i] << ";";
    }
}

/*
APPROFONDIMENTO
Programmazione generica ("generics")
Uno svantaggio dell'overloading è la necessità di ripetere lo stesso codice
per funzioni che eseguono le medesime operazioni su dati di tipo diverso.
Un'alternativa all'overloading delle funzioni è la creazione di un template, 
cioè una funzione "universale" capace di accettare in input e/o restituire 
in output dati di tipo diverso.

Una funzione generica è preceduta dalla dichiarazione
template<class T>

la lettera T sarà sostituita, nel richiamo della funzione, dal tipo di dati richiesto.

Il richiamo della funzione di seguito implementata sarà quindi
array_visual<int>(vetI, n); ...se vetI è un vettore di interi
array_visual<float>(vetF, n); ...se vetF è un vettore di float
array_visual<string>(vetS, n); ...se vetS è un vettore di stringhe
*/

// Visualizza a video il contenuto di un vettore
template<class T>
void array_visual_generica(T vet[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vet[i] << ";";
    }
}

template<class T>
void array_carica_generica(T vet[], int n) {
    T v;
    for (int i = 0; i < n; i++) {
        cout << "Inserire valore " << i << "o elemento: ";
        cin >> v;
        vet[i] = v;
    }
}