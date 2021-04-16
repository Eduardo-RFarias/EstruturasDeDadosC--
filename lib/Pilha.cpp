#include "Pilha.hpp"

Pilha::Pilha()
{
    size = 0;
    topo = NULL;
}

Pilha::~Pilha()
{
    esvaziar();
}

bool Pilha::isEmpty()
{
    return (size == 0) ? true : false;
}

int Pilha::getSize()
{
    return size;
}

void Pilha::esvaziar()
{
    Node *aux;
    while (topo != NULL)
    {
        aux = topo->prox;
        delete[] topo;
        topo = aux;
    }
    size = 0;
}

void Pilha::empilhar(int valor)
{
    Node *novoNo;
    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->prox = topo;
    topo = novoNo;
    size++;
}

int Pilha::desempilhar()
{
    if (isEmpty())
    {
        cout << "A lista está vazia" << endl;
        return 0;
    }
    int valor = topo->valor;
    delete[] topo;
    size--;
    return valor;
}

int Pilha::consultar()
{
    if (isEmpty())
    {
        cout << "A lista está vazia" << endl;
        return 0;
    }
    return topo->valor;
}
