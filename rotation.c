#include"header.h"

node*create_node(int data)
{
    node*newnode = malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->data = data;
    newnode->colour = 'R';
    return newnode;
}



void rightrotate(node**root,node*x)
{
    node*y = x->left;
    x->left = y->right;
    if(x->left!=NULL)
    x->left->parent=x;
    y->parent = x->parent;

    if(x->parent==NULL)
    *root=y;
    else if(x->parent->right == x)
    x->parent->right = y;
    else
    x->parent->left = y;
    
    y->right = x;
    x->parent = y;
}

void leftrotate(node**root,node*x)
{
    node*y = x->right;
    x->right = y->left;
    if(y->left!=NULL)
    y->left->parent = x;
    y->parent = x->parent;

    if(x->parent== NULL)
    *root = y;
    else if(x->parent->right == x)
    x->parent->right = y;
    else
    x->parent->left = y;

    y->left = x;
    x->parent = y;
}
