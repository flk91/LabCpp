#pragma once
#include<string>

using namespace std;

// carica l'elenco degli alunni
// @param alu vettore che sarà riempito con elenco alunni
// @return numero di alunni caricati
int carica_alunni(string alu[]);

///	<summary>Mostra a video il contenuto di un vettore di stringhe come elenco</summary>
/// <param name="vet">Vettore da visualizzare</param>
/// <param name="n">Numero di elementi</param>
void visual_elenco(string vet[], int n);
