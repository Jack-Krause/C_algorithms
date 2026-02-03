#include "BST.h"

#ifdef DEBUG
    #define DBG(...) fprintf(stderr, __VA_ARGS__)
#else
    #define DBF(...) ((void) 0)
#endif


int main()
{
    BST *bst = create_empty_tree();

    insert_tree(bst, 100);
    DBG("root should be 100: %d\n", bst->root->data);
    Node *current = bst->root;
    DBG_check_node(current, 20, NULL); // somehow DBG checks left & right val's

    insert_tree(bst, 20);
    insert_tree(bst, 500);
    insert_tree(bst, 10);
    insert_tree(bst, 30);

    DBG("size should be 5: %d\n", bst->size);



    traverse_inorder_tree(bst);


 
    return 0;
}








