#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int n);

typedef struct BST 
{
    Node *root;
    int size;
} BST;

BST *insert(Node *root);





