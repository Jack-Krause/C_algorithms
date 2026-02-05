#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node *insert(Node *root, int data);

void insert_tree(BST *bst, int key);

Node *insert_rec(Node *root, int data);

void insert_tree_rec(BST *bst, int key);

BST *create_empty_tree();

void traverse_inorder_tree(BST *tree);

void traverse_inorder_node(Node *root);

void traverse_levelorder_tree(BST *tree);

void traverse_levelorder_node(Node *root);

bool search(BST *bst, int key);

bool search_rec(Node *root, int key);
