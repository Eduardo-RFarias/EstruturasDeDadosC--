#ifndef ABP
#define ABP

#include <iostream>
#include <cstring>

using namespace std;

class Abp
{
private:
    class Node
    {
    public:
        int value;
        char *text;
        Node *left;
        Node *right;
    };

    Node *root;
    bool avl;
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

    Node *insert(int, Node *, string text);
    Node *remove(Node *, int);
    void display(Node *, int = 1);
    void showBalance(Node *);

public:
    Abp(bool avl = true);
    ~Abp();

    void reset();
    bool isEmpty();
    int getSize();

    void insert(int value, string text);
    void remove(int value);
    string get(int value);
    void display();
    void showBalance();
};

#endif