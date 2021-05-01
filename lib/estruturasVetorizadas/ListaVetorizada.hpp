#ifndef LISTAVETORIZADA
#define LISTAVETORIZADA

#include <iostream>
using namespace std;

class ListaVetorizada
{
private:
    int *array;
    int size;
    int MAXSIZE;
    bool isSorted;
    bool isResizable;

public:
    ListaVetorizada(int maxSize = 0, bool isResizable = true);
    ListaVetorizada(int *array, int maxSize, bool isResizable = true);
    ~ListaVetorizada();

    int getSize();
    int getMaxSize();

    int get(int index);
    int search(int value);

    void remove(int index);
    void append(int value);
    void insertIn(int value, int index);

    void sort();
    int binarySearch(int value);
};

#endif
