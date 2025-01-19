#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    struct node*right;
    struct node*left;
    struct node*parent;
    int data;
    char colour;
}node;

node*create_node(int data);

void rightrotate(node**root,node*x);

void leftrotate(node**root,node*x);

void checkviolation(node**root,node*newnode);

void insert_rbt(node**root,int data);

node*get_min(node*root);

void inorder(node*root);

node*delete_node(node*root,int data);

node*checkfordb(node*root,node*temp);

int search(node*root,int data);

void min(node*root);

void max(node*root);

void count(node*root,int*black,int*red);

#endif
