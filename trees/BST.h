#include <stdio.h>

typedef struct node
{
    int data;
    node *left;
    node *right;
} node;


typedef struct BST 
{
    node *root;
    int size;
} BST;


BST* create(int n);

BST* create(node *root);





