#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

#define N_LOTTO 6
#define VAL_MIN 1
#define VAL_MAX 90

using namespace std;

void estrai_numeri(int vet[], int n);
void scegli_numeri(int vet[], int n);
void visual(int vet[], int n, string sep = "; ", string end = ".");
int confronta(int vet1[], int vet2[], int n1, int n2);
int cerca_valore(int vet[], int n, int v);

int main()
{
#ifdef _WIN32
	//coloriamo lo sfondo di verde...
	//otteniamo il riferimento (HANDLE) alla console
	HANDLE sth = GetStdHandle(STD_OUTPUT_HANDLE);
	//impostiamo il colore del testo (FOREGROUND) bianco e lo sfondo (BACKGROUND) verde
	SetConsoleTextAttribute(sth, BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//ripuliamo lo schermo
	system("CLS");
	//impostiamo l'output UTF-8 (per il supporto ad accenti e caratteri estesi)
	SetConsoleOutputCP(CP_UTF8);
#endif

	int estratti[N_LOTTO] = { 0 * 6 }, scelti[N_LOTTO] = { 0 * 6 };
	srand(time(NULL));

	cout << "Super Enalotto" << endl;
	cout << "——————————————" << endl << endl;

	cout << "Gioca la tua schedina!" << endl;
	scegli_numeri(scelti, N_LOTTO);

	cout << "Ora estraiamo i 6 numeri vincenti:" << endl;
	estrai_numeri(estratti, N_LOTTO);
	visual(estratti, N_LOTTO);
	cout << endl << endl;

	confronta(scelti, estratti, N_LOTTO, N_LOTTO);
}


void estrai_numeri(int vet[], int n)
{
	int i, comp;
	for (i = 0; i < n; i++) {
		do {
			comp = (rand() % VAL_MAX) + VAL_MIN;
		} while (cerca_valore(vet, i, comp) > 0);
		vet[i] = comp;
	}
}


void scegli_numeri(int vet[], int n)
{
	int i, v, t;
	for (i = 0; i < n; i++) {
		do {
			cout << u8"Inserire il " << i + 1 << "^ numero: ";
			cin >> v;
			t = cerca_valore(vet, i, v);
			if (t > 0) {
				cout << u8"Hai già scelto " << v << ". Prova con un altro numero" << endl;
			}
			else {
				vet[i] = v;
			}
		} while (t > 0);
	}
}

// Ricerca un valore in un array e restituisce il numero di occorrenze
// @param vet array in cui cercare
// @param n numero di elementi
// @param v valore da cercare
int cerca_valore(int vet[], int n, int v)
{
	int i, trovati = 0;
	for (i = 0; i < n; i++) {
		//cout << vet[i] << endl;
		if (vet[i] == v) {
			trovati++;
		}
	}
	return trovati;
}



// Mostra a video il contenuto di un vettore
// @param vet vettore da mostrare a video
// @param n numero di elementi 
// @param sep (facoltativo) separatore degli elementi
// @param end (facoltativo) terminatore ultimo elemento
void visual(int vet[], int n, string sep, string end) {
	int i;
	for (i = 0; i < n; i++) {
		cout << vet[i];
		if (i < n - 1) {
			cout << sep;
		}
		else {
			cout << end;
		}
	}
}


// Confronta due vettori di numeri per verificare se vi sono corrispondenze
// @param vet1 primo vettore
// @param vet2 secondo vettore
// @param n1 numero elementi primo vettore
// @param n2 numero elementi secondo vettore
// @returns numero di corrispondenze rilevate
int confronta(int vet1[], int vet2[], int n1, int n2)
{
	int i, j, c = 0;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			if (vet1[i] == vet2[j]) {
				cout << "Trovato " << vet1[i] << endl;
				c++;
			}
		}
	}

	cout << "Hai indovinato " << c << " numeri." << endl;
	return c;
}
