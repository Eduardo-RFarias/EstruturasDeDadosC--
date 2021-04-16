#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada()
{
    this->first = NULL;
    this->last = NULL;
    this->size = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    for (int i = 0; i < size; i++)
    {
        Node *aux = first->next;
        delete[] first;
        first = aux;
    }
}

bool ListaEncadeada::isEmpty()
{
    return (size == 0) ? true : false;
}

void ListaEncadeada::addFirst(int valor)
{
    Node *novoNo;
    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->pre = NULL;
    if (size == 0)
    {
        novoNo->next = NULL;
        last = novoNo;
    }
    else
    {
        novoNo->next = first;
        first->pre = novoNo;
    }
    first = novoNo;
    size++;
}

void ListaEncadeada::addBeforeKey(int chave, int valor)
{
    if (size == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    Node *novoNo, *aux;
    bool flag = false;
    aux = first;

    if (size == 1)
    {
        if (aux->valor == chave)
        {
            addFirst(valor);
        }
        else
        {
            cout << "Chave não encontrada" << endl;
        }
        return;
    }

    do
    {
        if (aux->valor == chave)
        {
            flag = true;
            break;
        }
        aux = aux->next;
    } while (aux->next != NULL);

    if (!flag)
    {
        cout << "Chave não encontrada" << endl;
        return;
    }

    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->next = aux;
    novoNo->pre = aux->pre;
    aux->pre->next = novoNo;
    aux->pre = novoNo;
    size++;
}

void ListaEncadeada::addLast(int valor)
{
    Node *novoNo;
    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->next = NULL;
    if (size == 0)
    {
        novoNo->pre = NULL;
        first = novoNo;
    }
    else
    {
        novoNo->pre = last;
        last->next = novoNo;
    }
    last = novoNo;
    size++;
}

void ListaEncadeada::removeFirst()
{
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        delete[] first;
        first = NULL;
        last = NULL;
        size--;
        return;
    }

    Node *aux;
    aux = first;
    first = first->next;
    first->pre = NULL;
    delete[] aux;
    size--;
}

void ListaEncadeada::removeValue(int chave)
{
    if (size == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    Node *aux;
    aux = first;
    bool flag = false;

    if (size == 1)
    {
        if (aux->valor == chave)
        {
            removeFirst();
        }
        else
        {
            cout << "Chave não encontrada" << endl;
        }
        return;
    }

    do
    {
        if (aux->valor == chave)
        {
            flag = true;
            break;
        }
        else if (aux->next == NULL)
        {
            break;
        }
        aux = aux->next;
    } while (true);

    if (!flag)
    {
        cout << "Chave não encontrada." << endl;
        return;
    }

    if (aux->pre == NULL)
    {
        removeFirst();
    }
    else if (aux->next == NULL)
    {
        removeLast();
    }
    else
    {
        aux->pre->next = aux->next;
        aux->next->pre = aux->pre;
        delete[] aux;
        size--;
    }
}

void ListaEncadeada::removeLast()
{
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        delete[] last;
        first = NULL;
        last = NULL;
        size--;
        return;
    }

    Node *aux;
    aux = last->pre;
    aux->next = NULL;
    delete[] last;
    last = aux;
    size--;
}

int ListaEncadeada::getSize()
{
    return this->size;
}

int ListaEncadeada::get(int index)
{
    if (index >= size)
    {
        cout << "Indice indefinido" << endl;
        return -1;
    }

    Node *aux = this->first;

    for (int i = 0; i < index; i++)
    {
        aux = aux->next;
    }

    return aux->valor;
}

int ListaEncadeada::search(int value)
{
    Node *aux = first;
    for (int i = 0; i < size; i++)
    {
        if (aux->valor == value)
        {
            return i;
        }
        aux = aux->next;
    }
    return -1;
}
