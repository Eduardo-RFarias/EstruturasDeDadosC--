#include "FilaEncadeada.hpp"

FilaEncadeada::FilaEncadeada()
{
    this->start = NULL;
    this->end = NULL;
    this->size = 0;
}

FilaEncadeada::~FilaEncadeada()
{
    empty();
}

bool FilaEncadeada::isEmpty()
{
    return (size == 0) ? true : false;
}

void FilaEncadeada::empty()
{
    Node *aux;
    for (int i = 0; i < size; i++)
    {
        aux = start->next;
        delete[] start;
        start = aux;
    }
}

void FilaEncadeada::put(int valor)
{
    Node *novoNo = new Node;
    novoNo->valor = valor;
    novoNo->next = NULL;

    if (size == 0)
    {
        start = novoNo;
        end = novoNo;
    }
    else
    {
        end->next = novoNo;
        end = novoNo;
    }

    size++;
}

int FilaEncadeada::remove()
{
    if (size == 0)
    {
        cout << "A fila esta vazia" << endl;
        return -1;
    }

    Node *aux;
    int valor;

    if (size == 1)
    {
        valor = start->valor;
        delete[] start;
        start = NULL;
        end = NULL;
    }
    else
    {
        aux = start->next;
        valor = start->valor;
        delete[] start;
        start = aux;
    }

    size--;

    return valor;
}

int FilaEncadeada::see()
{
    return start->valor;
}