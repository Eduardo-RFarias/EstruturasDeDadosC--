#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada()
{
    this->first = NULL;
    this->size = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    clear();
}

void ListaEncadeada::clear()
{
    for (int i = 0; i < size; i++)
    {
        Node *aux = first->next;
        delete[] first;
        first = aux;
    }
    this->size = 0;
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
    novoNo->next = (size == 0) ? NULL : first;
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

    Node *novoNo, *aux, *aux2;
    bool flag = false;
    aux = first;
    aux2 = NULL;

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
        aux2 = aux;
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
    aux2->next = novoNo;
    size++;
}

void ListaEncadeada::addLast(int valor)
{
    if (size == 0)
    {
        addFirst(valor);
        return;
    }

    Node *novoNo;
    novoNo = new Node;
    novoNo->valor = valor;
    novoNo->next = NULL;

    if (size == 1)
    {
        first->next = novoNo;
    }
    else
    {
        Node *aux;
        aux = first;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = novoNo;
    }

    size++;
}

void ListaEncadeada::removeFirst()
{
    if (size == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    if (size == 1)
    {
        delete[] first;
        first = NULL;
        size--;
        return;
    }

    Node *aux;
    aux = first;
    first = first->next;
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

    Node *aux, *aux2;
    aux = first;
    aux2 = NULL;
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

    while (true)
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
        aux2 = aux;
        aux = aux->next;
    }

    if (!flag)
    {
        cout << "Chave não encontrada." << endl;
        return;
    }

    if (aux2 == NULL)
    {
        removeFirst();
    }
    else if (aux->next == NULL)
    {
        removeLast();
    }
    else
    {
        aux2->next = aux->next;
        delete[] aux;
        size--;
    }
}

void ListaEncadeada::removeLast()
{
    if (size == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    if (size == 1)
    {
        delete[] first;
        first = NULL;
        size--;
        return;
    }

    Node *aux;
    aux = first;

    while (aux->next->next != NULL)
    {
        aux = aux->next;
    }

    delete[] aux->next;
    aux->next = NULL;
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
