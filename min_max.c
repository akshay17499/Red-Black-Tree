#include"header.h"

void min(node*root)
{
    while(root->left!=NULL)
    {
       root = root->left;
    }
    printf(" %d(%c)\n",root->data,root->colour);
}

void max(node*root)
{
     while(root->right!=NULL)
    {
       root = root->right;
    }
    printf(" %d(%c)\n",root->data,root->colour);
}
