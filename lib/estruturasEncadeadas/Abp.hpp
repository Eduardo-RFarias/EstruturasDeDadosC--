#ifndef ABP
#define ABP

#include <iostream>
using namespace std;

typedef struct Node
{
    int value;
    Node *left;
    Node *right;
};

class Abp
{
private:
    Node *root;
    int size;

public:
    Abp();
    ~Abp();

    int getSize();

    Node *rotateRR(Node *parent);
    Node *rotateRL(Node *parent);
    Node *rotateLR(Node *parent);
    Node *rotateLL(Node *parent);
};

#endif