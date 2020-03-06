// Amicabili.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>

using namespace std;

int sdiv(int n);
bool amicabili(int a, int b);

int main()
{
	int x, y;
	cout << "Numeri amicabili" << endl;
	cout << "----------------" << endl << endl;

	cout << "Inserire il primo numero: ";
	cin >> x;
	cout << "Inserire il secondo numero: ";
	cin >> y;

	if (amicabili(x, y) == true) {
		cout << "I due numeri inseriti sono amicabili" << endl;
	} else {
		cout << "I due numeri inseriti NON sono amicabili" << endl;
	}
}

///<summary>Restituisce la somma dei divisori propri
///di un numero n (escluso il numero stesso).</summary>
/// <param name="n">numero di cui trovare la somma dei divisori</param>
int sdiv(int n)
{
	int resto;
	int sd = 0;
	int i = 1;

	while (i <= n / 2) {
		resto = n % i;
		if (resto == 0) {
			sd += i;
		}
		i++;
	}

	return sd;
}

bool amicabili(int a, int b)
{
	int sdiva, sdivb;
	bool ami = false;

	sdiva = sdiv(a);
	if (sdiva == b) {
		sdivb = sdiv(b);
		if (sdivb == a) {
			ami = true;
		}
	}

	return ami;
}
