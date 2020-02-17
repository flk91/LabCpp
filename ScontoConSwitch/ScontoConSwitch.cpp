// ScontoConSwitch.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>

using namespace std;

int main()
{
	float prezzo;
	char metodopag;

	cout << "Inserire prezzo: ";
	cin >> prezzo;

	cout << "Metodo di pagamento?" << endl;
	cout << "c = contanti (-10%)" << endl;
	cout << "r = rateale (+5%)" << endl;
	cout << "t = carta di credito (+5%)" << endl;
	cout << ":";
	cin >> metodopag;

	switch (metodopag) {
	case 'c':
		prezzo = prezzo - prezzo * 10 / 100;
		break;
	case 't':
		prezzo = prezzo + prezzo * 3 / 100;
		break;
	case 'r':
		prezzo = prezzo + prezzo * 5 / 100;
		break;
	default:
		cout << "Metodo di pagamento non riconosciuto" << endl;
	}

	cout << "Il prezzo finale e': " << prezzo << endl;
}