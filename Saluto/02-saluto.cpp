#include <iostream>

using namespace std;

int main()
{
	//dichiariamo la variabile nome, di tipo string
	string nome;

	//mostriamo un messaggio per chiedere all'utente di inserire il nome
	cout << "Come ti chiami? ";
	//il programma ora attende che l'utente inserisca il proprio nome e prema invio.
	//quanto letto in input viene inserito nella variabile nome.
	cin >> nome;

	//un messaggio in output può essere composto da più parti ed includere il variabile.
	//le varie parti sono separate dalla sequanza << .
	//endl è una parola che serve per andare a capo.
	//il testo tra virgolette è una costante, cioè la parte del messaggio che non cambia mai.
	cout << "Ciao, " << nome << "!" << endl;

	return 0;
}
