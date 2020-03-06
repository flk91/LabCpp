#include <iostream>
#include <string>
#include <Windows.h>
#include "VotiClasse.h"

//numero max. alunni per classe
#define MAX_ALU 50

//numero max. voti per alunno
#define MAX_VOTI 10

using namespace std;

int main()
{
	///elenco nominativi alunni
	string alu[MAX_ALU];

	///voti degli alunni
	float voti[MAX_ALU][MAX_VOTI];

	///conteggio voti di ogni alunno
	int contavoti[MAX_ALU];

	///numero alunni
	int nalu;

	nalu = carica_alunni(alu);

	visual_elenco(alu, nalu);
}

int carica_alunni(string alu[]) {
	string nominativo;
	cout << "Inserire gli alunni della classe (1 per riga). Lasciare una riga vuota per terminare l'inserimento" << endl;
	int c = 0;
	do {
		nominativo = "";
		getline(cin, nominativo);

		if(nominativo.length()>0) {
			alu[c] = nominativo;
			c++;
		}
	} while (nominativo.length()>0);

	return c;
}

void visual_elenco(string vet[], int n) {
	for (int i = 0; i < n; i++) {
		cout << vet[i] << endl;
	}
}

void carica_voti(string alunni[MAX_ALU], float voti[MAX_ALU][MAX_VOTI], int n, int cv[MAX_ALU]) {
	for (int i = 0; i < n; i++) {
		cout << "Inserire i voti di " << alunni[i] << endl;
	}
}