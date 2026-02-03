#include "BST.h"

Node *create_node(int data) 
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
};

BST *create_empty_tree()
{
    BST *new_tree = malloc(sizeof(BST));
    new_tree->size = 0;
    new_tree->root = NULL;

    return new_tree;
}

Node *insert(Node *root, int data) 
{
    if (root == NULL) // insert here
    {
        return create_node(data);
    }

    if (data < root->data) // insert somewhere in left subtree
        root->left = insert(root->left, data);
    else if (data > root->data) // insert somewhere in right subtree
        root->right = insert(root->right, data);

    return root;
};

BST *insert_tree(BST *bst, int key)
{
    if (bst == NULL || bst->size == 0)
    {
        BST *new_tree = create_empty_tree();
        new_tree->root = insert(new_tree->root, key);
        new_tree->size = (new_tree->size) + 1; // could just set to 1 probably
        return new_tree;
    } 
    else
    {
        insert(bst->root, key);
        bst->size = (bst->size) + 1;
        return bst;
    }
}


void traverse_inorder_tree(BST *tree)
{
    if (tree == NULL || tree->size == 0) {
        printf("[inorder_tree] tree is empty.\n");
        return;
    }

    traverse_inorder_node(tree->root);
    printf("\n");
}

void traverse_inorder_node(Node *root)
{
    if (root == NULL) {
        // printf("[inorder node] root is null.\n");
        return;
    }

    traverse_inorder_node(root->left);

    printf("%d  ", root->data);

    traverse_inorder_node(root->right);
}






