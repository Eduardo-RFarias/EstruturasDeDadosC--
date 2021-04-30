#include "PilhaEncadeada.hpp"

PilhaEncadeada::PilhaEncadeada()
{
    size = 0;
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada()
{
    esvaziar();
}

bool PilhaEncadeada::isEmpty()
{
    return (size == 0) ? true : false;
}

int PilhaEncadeada::getSize()
{
    return size;
}

void PilhaEncadeada::esvaziar()
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

void PilhaEncadeada::empilhar(int valor)
{
    Node *novoNo;
    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->prox = topo;
    topo = novoNo;
    size++;
}

int PilhaEncadeada::desempilhar()
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

int PilhaEncadeada::consultar()
{
    if (isEmpty())
    {
        cout << "A lista está vazia" << endl;
        return 0;
    }
    return topo->valor;
}
