#include "BST.h"

int main()
{
    BST *bst = create_empty_tree();

    insert_tree(bst, 100);
    printf("After insertion of 100, size=%d\n", bst->size);
    printf("root exits: %d\n", (bst->root != NULL));
    insert_tree(bst, 20);
    printf("After insertion of 20, size=%d\n", bst->size);
    printf("root->left exists: %d\n", (bst->root->left != NULL));


    insert_tree(bst, 500);

    insert_tree(bst, 10);

    insert_tree(bst, 30);

    printf("size should be 5: %d\n", bst->size);
    return 0;
    traverse_inorder_tree(bst);


 
    return 0;
}








