#ifndef ABP
#define ABP

#include <iostream>
using namespace std;

class Abp
{
private:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
    };

    Node *root;
    int size;

    void reset(Node *);

    Node *balance(Node *);
    int height(Node *);
    int diff(Node *);
    Node *findMin(Node *);

    Node *rotateRR(Node *);
    Node *rotateRL(Node *);
    Node *rotateLR(Node *);
    Node *rotateLL(Node *);

    Node *insert(int, Node *);
    Node *remove(Node *, int);
    void display(Node *, int = 1);
    void showBalance(Node *);

public:
    Abp();
    ~Abp();

    void reset();
    bool isEmpty();

    void insert(int value);
    void remove(int value);
    void display();
    void showBalance();
};

#endif