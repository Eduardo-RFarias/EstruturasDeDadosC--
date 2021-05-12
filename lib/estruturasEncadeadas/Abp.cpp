#include "Abp.hpp"

Abp::Abp()
{
    this->root = NULL;
    this->size = 0;
}

Abp::~Abp()
{
}

int Abp::getSize()
{
    return this->size;
}

//Rotations
Node *Abp::rotateRR(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

Node *Abp::rotateLL(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

Node *Abp::rotateLR(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = rotateRR(temp);
    return rotateLL(parent);
}

Node *Abp::rotateRL(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = rotateLL(temp);
    return rotateRR(parent);
}
