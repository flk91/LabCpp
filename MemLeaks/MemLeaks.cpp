// MemLeaks.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <Windows.h>
#include <malloc.h>

using namespace std;


char nome[100];

void riempi_vettore(char vet[], int dimensione);

int main()
{
    unsigned int dimensione;
    cout << "Quanta memoria vuoi allocare (in byte)?: ";
    cin >> dimensione;
    char* vet;
    vet = (char*) malloc(sizeof(char) * dimensione);
    
    //riempi_vettore(vet, dimensione);
    system("PAUSE");
    free(vet);
    cout << "Ho liberato la memoria" << endl;
    system("PAUSE");

}

void riempi_vettore(char vet[], int dimensione) {
    
    for (int i = 0; i < dimensione; i++) {
        vet[i] = 'a';
    }
    cout << "Ho riempito " << dimensione << " byte di memoria centrale." << endl;
    system("PAUSE");
}
