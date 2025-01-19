#include"header.h"

int search(node*root,int data)
{
    if(root==NULL)
    return -2;

    while(root!=NULL)
    {
        if(root->data > data)
        root = root->left;
        else if(root->data < data)
        root = root->right;
        else
        return 0;
    }
    return -1;
    
}
