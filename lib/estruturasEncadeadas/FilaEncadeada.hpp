#ifndef FILAENCADEADA
#define FILAENCADEADA

#include <iostream>
using namespace std;

class FilaEncadeada
{
private:
    class Node
    {
    public:
        Node *next;
        int valor;
    };

    Node *start;
    Node *end;
    int size;

public:
    FilaEncadeada();
    ~FilaEncadeada();

    bool isEmpty();

    void empty();
    void put(int valor);
    int remove();
    int see();
};

#endif
