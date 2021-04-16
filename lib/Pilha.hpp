#ifndef PILHA
#define PILHA

#include <iostream>
using namespace std;

class Pilha
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
    Pilha();
    ~Pilha();

    bool isEmpty();
    int getSize();

    void esvaziar();
    void empilhar(int valor);
    int desempilhar();
    int consultar();
};

#endif