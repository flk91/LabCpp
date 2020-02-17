// ListaSTL.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void visualizza_lista(list<string> lista);
void visualizza_lista_inverso(list<string> lista);
string ottieni_elemento(list<string> lista, int posizione);
void rimuovi_elemento(list<string> lista, int posizione);
void sostituisci_elemento(list<string> lista, string elemento, int posizione);
void scambia_posizioni(list<string> lista, int posizione);


int main()
{
    list<string> frutti;
    string frutto;
    int n_frutti, seleziona_frutto;
    char altro;
    
    do {
        cout << "Digita il nome di un frutto: ";
        cin >> frutto;

        frutti.push_back(frutto);

        cout << "Vuoi caricare un altro frutto? [s/N]: ";
        cin >> altro;
    } while (altro == 's' || altro=='S');

    cout << "\n\nVisualizziamo la lista:\n";
    visualizza_lista(frutti);
    cout << "\n\nLista inversa:\n";
    visualizza_lista_inverso(frutti);

    n_frutti = frutti.size();

    do {
        cout << "Ci sono " << n_frutti << " frutti." << endl;
        cout << "Quale vuoi visualizzare? ";
        cin >> seleziona_frutto;
    } while (seleziona_frutto<1 || seleziona_frutto>n_frutti);

    string frutto_selezionato = ottieni_elemento(frutti, seleziona_frutto);
    cout << "Il frutto e': " << frutto_selezionato;
    
}


void visualizza_lista(list<string> lista) {
    //per iterare sulla lista ho bisogno di usare un iterator
    list<string>::iterator iter = lista.begin();
    
    //finché la posizione di iter è diversa dalla fine della lista
    while (iter != lista.end()) {
        //mostro in output il valore a cui punta iter
        cout << *iter << endl;
        
        //iter è un puntatore. Incrementarlo di 1 equivale a posizionarlo all'elemento successivo.
        iter++;
    }
    
}


void visualizza_lista_inverso(list<string> lista) {
    //per leggere la lista dalla fine all'inizio devo usare un reverse_iterator

    list<string>::reverse_iterator iter = lista.rbegin();
    while (iter != lista.rend()) {
        cout << *iter << endl;
        iter++;
    }
}

string ottieni_elemento(list<string> lista, int posizione) {
    //non posso accedere direttamente alla posizione di una lista come fosse un vettore.
    //devo quindi usare un iteratore
    list<string>::iterator iter = lista.begin();
    if (posizione > 1) {
        //la funzione advance permette di far avanzare l'iteratore di n posizioni
        advance(iter, (posizione - 1));
    }
    //restituisco l'elemento della lista
    return *iter;
}

void rimuovi_elemento(list<string> lista, int posizione)
{
    throw new exception("Not implemented yet!");
}

void sostituisci_elemento(list<string> lista, string elemento, int posizione)
{
    throw new exception("Not implemented yet!");
}

void scambia_posizioni(list<string> lista, int posizione)
{
    throw new exception("Not implemented yet!");
}
