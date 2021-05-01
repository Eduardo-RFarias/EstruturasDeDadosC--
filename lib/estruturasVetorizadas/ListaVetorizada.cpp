#include "ListaVetorizada.hpp"

ListaVetorizada::ListaVetorizada(int maxSize, bool isResizable)
{
    this->array = new int[maxSize];
    this->size = 0;
    this->MAXSIZE = maxSize;
    this->isResizable = isResizable;
    this->isSorted = false;
}

ListaVetorizada::ListaVetorizada(int *array, int size, bool isResizable)
{
    this->array = new int[size];
    this->MAXSIZE = size;
    this->size = size;
    this->isResizable = isResizable;
    this->isSorted = false;

    for (int i = 0; i < size; i++)
    {
        this->array[i] = array[i];
    }
}

ListaVetorizada::~ListaVetorizada()
{
    delete[] array;
}

int ListaVetorizada::getSize()
{
    return size;
}

int ListaVetorizada::getMaxSize()
{
    return MAXSIZE;
}

int ListaVetorizada::get(int index)
{
    if (index >= size)
    {
        cout << "Indice indefinido" << endl;
    }

    return this->array[index];
}

int ListaVetorizada::search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (*(this->array + i) == value)
        {
            return i;
        }
    }

    return -1;
}

void ListaVetorizada::sort()
{
    int i = 0;
    int j = 1;
    int aux = 0;

    while (j < this->size)
    {
        aux = this->array[j];
        i = j - 1;

        while (i >= 0 && this->array[i] > aux)
        {
            this->array[i + 1] = this->array[i];
            i--;
        }

        this->array[i + 1] = aux;

        j++;
    }
    this->isSorted = true;
}

int ListaVetorizada::binarySearch(int value)
{
    if (!this->isSorted)
    {
        cout << "Array não está ordenada" << endl;
        return -2;
    }

    int esquerda = 0;
    int direita = this->size - 1;

    int meio;
    int valorLido;

    while (esquerda <= direita)
    {
        meio = (direita + esquerda) / 2;
        valorLido = *(this->array + meio);

        if (valorLido == value)
        {
            return meio;
        }
        else if (valorLido > value)
        {
            direita = meio - 1;
        }
        else
        {
            esquerda = meio + 1;
        }
    }

    return -1;
}

void ListaVetorizada::remove(int index)
{
    if (size == 0)
    {
        cout << "A lista está vazia" << endl;
        return;
    }

    if (index >= size)
    {
        cout << "Indice grande demais" << endl;
        return;
    }

    if (this->isResizable)
    {
        int i = 0;
        int j = 0;
        int *newArray = new int[size - 1];

        for (int j = 0; j < size; j++)
        {
            if (this->array[j] != index)
            {
                newArray[i] = this->array[j];
                i++;
            }
        }

        MAXSIZE = size - 1;
        delete[] this->array;
        this->array = newArray;
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + 1];
        }
    }
    size--;
}

void ListaVetorizada::append(int value)
{
    if (this->isResizable)
    {
        int *newArray = new int[size + 1];
        this->MAXSIZE = size + 1;

        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }

        newArray[size] = value;

        delete[] this->array;
        this->array = newArray;
    }
    else
    {
        if (size == MAXSIZE)
        {
            cout << "A lista está cheia" << endl;
            return;
        }

        this->array[size] = value;
    }

    size++;
    isSorted = false;
}

void ListaVetorizada::insertIn(int value, int index)
{
    if (index >= size)
    {
        cout << "Indice grande demais" << endl;
        return;
    }

    if (this->isResizable)
    {
        int *newArray = new int[size + 1];

        int i = 0;
        for (int j = 0; j < size; j++)
        {
            if (j == index)
            {
                i++;
            }
            newArray[i] = this->array[j];
            i++;
        }
        newArray[index] = value;

        this->MAXSIZE = size + 1;
        delete[] this->array;
        this->array = newArray;
    }
    else
    {
        if (size == MAXSIZE)
        {
            cout << "A lista está cheia" << endl;
            return;
        }

        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = value;
    }
    size++;
    isSorted = false;
}
