#include <iostream>
#include <string>
#include <list>

using namespace std;

struct una_data {
    int giorno, mese, anno;
    string toString();
};

struct contatto {
    string nome;
    string cognome;
    string data_nascita;
    string indirizzo;
    string cap;
    string citta;
    string provincia;
    string telefono1;
    string telefono2;
    string cellulare;
    string email;
};

list<contatto> contatti;

int main()
{
    
}

contatto* crea_contatto_input() {
    contatto* c = new contatto();
    
    cout << "Nome: ";
    cin >> c->nome;

    cout << "Cognome: ";
    cin >> c->cognome;

    return c;
}

string una_data::toString()
{
    string s = "";
    s =  to_string(this->anno) + "-" + to_string(this->mese) + "-" + to_string(this->giorno);
    return s;
}
