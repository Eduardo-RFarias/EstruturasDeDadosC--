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

public:
    Abp();
    ~Abp();
};

#endif