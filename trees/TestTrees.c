#include "BST.h"

int main()
{
    BST *bst = create_empty_tree();

    insert_tree(bst, 100);
    printf("After insertion of 100, size=%d\n", bst->size);
    printf("has root: %d\n", (bst->root == NULL));
    insert_tree(bst, 20);
    printf("After insertion of 100, size=%d\n", bst->size);
    printf("root->left exists: %d\n", (bst->root->left == NULL));


    return 1;

    insert_tree(bst, 500);

    // insert_tree(bst, 10);

    // insert_tree(bst, 30);

    traverse_inorder_tree(bst);


 
    return 0;
}








