// AltoBasso.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

#define MAX_TENT 7

using namespace std;

int main()
{
	int comp, user, difficolta, maxcomp, ntent;
	bool indovinato = false;

	srand(time(NULL));

	cout << "Alto o basso?\n";
	cout << "-------------\n\n";
	cout << "Scegli tipo di gioco\n1: facile [1-100]\n2: medio [1-1.000]\n3: difficile[1.000-10.000]\n\n:";
	cin >> difficolta;

	switch (difficolta) {
	case 1:
		maxcomp = 100;
		break;
	case 3:
		maxcomp = 10000;
		break;
	default:
		maxcomp = 1000;
	}

	comp = rand() % maxcomp + 1;

	ntent = 1;
	while (ntent <= MAX_TENT && indovinato == false) {
		cout << "Indovina il numero misterioso: ";
		cin >> user;
		if (comp == user) {
			indovinato = true;
			cout << "Hai indovinato in " << ntent << " tentativi!" << endl;
			Beep(500, 1000); // 523 hertz (C5) for 500 milliseconds     
			cin.get(); // wait 
		}
		else {
			if (user > comp) {
				cout << "Il numero da indovinare e' piu' basso!" << endl;
				Beep(300, 500);
				cin.get();
			}
			else {
				cout << "Il numero da indovinare e' piu' alto!" << endl;
				Beep(800, 500);
				cin.get();
			}
			cout << endl;
		}
		ntent++;
	}

	if (!indovinato) {
		cout << "Non hai indovinato il numero misterioso nei " << MAX_TENT << " tentativi concessi." << endl;
		cout << "Il numero misterioso era: " << comp << endl;
	}
}