#include <iostream>
#include "ListaEncadeada.hpp"
#include "ListaVetorizada.hpp"
#include "Pilha.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    ListaEncadeada listaEncadeada;

    listaEncadeada.addFirst(10);
    listaEncadeada.addFirst(3);
    listaEncadeada.addLast(5);
    listaEncadeada.addBeforeKey(10, 7);
    listaEncadeada.removeFirst();
    listaEncadeada.removeValue(10);
    listaEncadeada.removeLast();

    int aux[9] = {1, 2, 3, 7, 2, 4, 5, 20, 10};
    ListaVetorizada listaVetorizada(aux, 10);

    listaVetorizada.append(6);
    listaVetorizada.sort();

    Pilha pilha;

    pilha.empilhar(10);
    pilha.empilhar(20);
    pilha.empilhar(15);
    pilha.esvaziar();

    return 0;
}
