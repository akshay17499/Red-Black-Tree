#include"header.h"

node*get_min(node*root)
{
    while(root->left!=NULL)
    root = root->left;
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d(%c)  ",root->data,root->colour);
    inorder(root->right);
}
void count(node*root,int*black,int*red)
{
   if(root==NULL)
   return;
   if(root->colour=='B')
   (*black)++;
   else 
   (*red)++;
   count(root->left,black,red);
   count(root->right,black,red);
}
