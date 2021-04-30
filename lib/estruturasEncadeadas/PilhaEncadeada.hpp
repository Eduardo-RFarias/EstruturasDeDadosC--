#ifndef PILHAENCADEADA
#define PILHAENCADEADA

#include <iostream>
using namespace std;

class PilhaEncadeada
{
private:
    class Node
    {
    public:
        Node *prox;
        int valor;
    };

    Node *topo;
    int size;

public:
    PilhaEncadeada();
    ~PilhaEncadeada();

    bool isEmpty();
    int getSize();

    void esvaziar();
    void empilhar(int valor);
    int desempilhar();
    int consultar();
};

#endif