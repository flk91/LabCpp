// Superenalotto.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#define N_LOTTO 6
#define VAL_MIN 1
#define VAL_MAX 90

using namespace std;

void estrai_numeri(int vet[], int n);
void scegli_numeri(int vet[], int n);
void visual(int vet[], int n);
void confronta(int vet1[], int vet2[], int n1, int n2);
int cerca_valore(int vet[], int n, int v);

int main()
{
	int estratti[N_LOTTO] = { 0 * 6 }, scelti[N_LOTTO] = {0*6};
	srand(time(NULL));

	cout << "Super Enalotto" << endl;
	cout << "--------------" << endl << endl;

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
			cout << "Inserire il " << i+1 << ". numero: ";
			cin >> v;
			t = cerca_valore(vet, i, v);
			if (t > 0) {
				cout << "Hai gia' scelto " << v << ". Prova con un altro numero" << endl;
			}
			else {
				vet[i] = v;
			}
		} while (t>0);
	}
}

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

void visual(int vet[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << vet[i];
		if (i < n - 1) {
			cout << "; ";
		}
		else {
			cout << ".";
		}
	}
}

void confronta(int vet1[], int vet2[], int n1, int n2)
{
	int i, j, c=0;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			if (vet1[i] == vet2[j]) {
				cout << "Trovato " << vet1[i] << endl;
				c++;
			}
		}
	}

	cout << "Hai indovinato " << c << " numeri." << endl;
}
