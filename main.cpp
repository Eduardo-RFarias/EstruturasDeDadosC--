#include <iostream>
#include "ListaEncadeada.hpp"
#include "ListaVetorizada.hpp"
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

    int x = listaEncadeada.search(10);

    return 0;
}
