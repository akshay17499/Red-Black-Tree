#include"header.h"

void checkviolation(node**root,node*newnode)
{
    while(newnode->parent!=NULL&&newnode->colour!='B'&&newnode->parent->colour=='R')
    {
        node* parent = newnode->parent;
        node*grandparent = parent->parent;

        if(grandparent->right == parent)
        {
            node*uncle = grandparent->left;
            if(uncle!=NULL&&uncle->colour=='R')
            {
                //printf("root->val : %d uncle->val : %d  node->val %d in R R R\n",(*root)->data,uncle->data,newnode->data);
                uncle->colour = 'B';
                parent->colour = 'B';
                grandparent->colour = 'R';
                newnode = grandparent;
                
            }
            else{

                if(parent->left == newnode)
                {//printf("root->val : %d node->val %d in R L(rotation)\n",(*root)->data,newnode->data);
                    rightrotate(root,parent);
                    newnode = parent;
                    parent = newnode->parent;
                }
                //printf("root->val : %d node->val %d in  L(rotation)\n",(*root)->data,newnode->data);
                leftrotate(root,grandparent);
                char temp = parent->colour;
                parent->colour = grandparent->colour;
                grandparent->colour = temp;
                newnode = parent;
            }
        }
        else{
            node*uncle = grandparent->right;

            if(uncle!=NULL&&uncle->colour=='R')
            {//printf("root->val : %d uncle->val : %d  node->val %d in R R R\n",(*root)->data,uncle->data,newnode->data);
                uncle->colour = 'B';
                parent->colour = 'B';
                grandparent->colour = 'R';
                newnode = grandparent;
            }
            else{
                if(parent->right == newnode)
                {//printf("root->val :%d node->val %d in  LR(rotation)\n",(*root)->data,newnode->data);
                    leftrotate(root,parent);
                    newnode = parent;
                    parent = newnode->parent;
                }
                //printf(" node->val %d in  R(rotation)\n",newnode->data);
                 rightrotate(root,grandparent);
                 char temp = parent->colour;
                 parent->colour = grandparent->colour;
                 grandparent->colour = temp;
                 newnode = parent;
            }
        }
    }
   // printf("\n\n(before)root->val : %d root->colour : %c newnode->data : %d\n",(*root)->data,(*root)->colour,newnode->data);
    (*root)->colour='B';
    //printf("(after)root->val : %d root->colour : %c newnode->data : %d\n\n\n",(*root)->data,(*root)->colour,newnode->data);
}

void insert_rbt(node**root,int data)
{
    node*newnode = create_node(data);
    if(*root==NULL)
    {
        *root = newnode;
        newnode->colour = 'B';
        return;
    }

    node*temp = *root,*prev = NULL;

    while(temp!=NULL)
    {
        prev = temp;
        if(temp->data > data)
        temp = temp->left;
        else if(temp->data < data)
        temp = temp->right;
        else{
            return;
        }
    }
    if(prev->data > data)
    {
        prev->left = newnode;
        newnode->parent = prev;
    }
    else{
        prev->right = newnode;
        newnode->parent = prev;
    }
     //printf("prev->data : %d  new->data : %d\n",prev->data,newnode->data);
    checkviolation(root,newnode);
}
