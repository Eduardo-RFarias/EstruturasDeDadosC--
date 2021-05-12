#include <iostream>
#include "lib/estruturasEncadeadas/ListaEncadeada.hpp"
#include "lib/estruturasEncadeadas/PilhaEncadeada.hpp"
#include "lib/estruturasEncadeadas/FilaEncadeada.hpp"
#include "lib/estruturasVetorizadas/ListaVetorizada.hpp"
#include "lib/estruturasEncadeadas/Abp.hpp"
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
    ListaVetorizada listaVetorizada(aux, 9, false);
    ListaVetorizada listaVetorizadaDinamica;

    listaVetorizada.sort();
    listaVetorizada.binarySearch(4);

    listaVetorizadaDinamica.append(5);
    listaVetorizadaDinamica.append(2);
    listaVetorizadaDinamica.insertIn(10, 1);
    listaVetorizadaDinamica.remove(0);
    listaVetorizadaDinamica.sort();

    PilhaEncadeada pilhaEncadeada;

    pilhaEncadeada.empilhar(10);
    pilhaEncadeada.empilhar(20);
    pilhaEncadeada.empilhar(15);
    pilhaEncadeada.esvaziar();

    FilaEncadeada filaEncadeada;
    filaEncadeada.put(1);
    filaEncadeada.put(2);
    filaEncadeada.remove();
    filaEncadeada.see();
    filaEncadeada.remove();

    Abp arvoreAVL;

    for (int i = 0; i <= 15; i++)
    {
        arvoreAVL.insert(i);
    }

    cout << "Arvore Balanceada:" << endl;
    arvoreAVL.display();
    cout << "Valores e respectivos fatores de balanceamento:\n"
         << endl;
    arvoreAVL.showBalance();

    return 0;
}
