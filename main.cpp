#include "lib/estruturasEncadeadas/ListaEncadeada.hpp"
#include "lib/estruturasEncadeadas/PilhaEncadeada.hpp"
#include "lib/estruturasEncadeadas/FilaEncadeada.hpp"
#include "lib/estruturasVetorizadas/ListaVetorizada.hpp"
#include "lib/estruturasEncadeadas/Abp.hpp"
#include "lib/auxilares/gen_random.hpp"

#include <iostream>

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

    listaVetorizada.sort();
    listaVetorizada.binarySearch(4);

    ListaVetorizada listaVetorizadaDinamica;
    listaVetorizadaDinamica.append(5);
    listaVetorizadaDinamica.append(2);
    listaVetorizadaDinamica.insertIn(10, 1);
    listaVetorizadaDinamica.remove(0);
    listaVetorizadaDinamica.remove(2);
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

    Abp arvoreAVL(true);

    for (int i = 1; i <= 16; i++)
    {
        arvoreAVL.insert(i, gen_random(i));
    }

    arvoreAVL.remove(16);

    arvoreAVL.display();
    arvoreAVL.showBalance();
    cout << arvoreAVL.get(7) << endl;
    return 0;
}
