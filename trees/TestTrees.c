#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
  #define DBG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DBG(...) ((void)0)
#endif

#ifdef DEBUG
  #define ASSERT_EQ_INT(expected, actual) do {                \
      int _exp = (expected);                                  \
      int _act = (actual);                                    \
      if (_exp != _act) {                                     \
          fprintf(stderr,                                     \
              "ASSERT_EQ_INT failed at %s:%d\n"               \
              "  expected: %d\n"                              \
              "  actual:   %d\n",                             \
              __FILE__, __LINE__, _exp, _act);                \
          exit(1);                                            \
      }                                                       \
  } while (0)

  #define ASSERT_EQ_PTR(expected, actual) do {                \
      const void *_exp = (const void*)(expected);             \
      const void *_act = (const void*)(actual);               \
      if (_exp != _act) {                                     \
          fprintf(stderr,                                     \
              "ASSERT_EQ_PTR failed at %s:%d\n"               \
              "  expected: %p\n"                              \
              "  actual:   %p\n",                             \
              __FILE__, __LINE__, _exp, _act);                \
          exit(1);                                            \
      }                                                       \
  } while (0)

  static void ASSERT_NODE(const Node *n, int expected_data,
                          const Node *expected_left,
                          const Node *expected_right)
  {
      if (n == NULL) {
          fprintf(stderr, "ASSERT_NODE failed at %s:%d\n  node is NULL\n",
                  __FILE__, __LINE__);
          exit(1);
      }

      ASSERT_EQ_INT(expected_data, n->data);
      ASSERT_EQ_PTR(expected_left, n->left);
      ASSERT_EQ_PTR(expected_right, n->right);
  }
#else
  #define ASSERT_EQ_INT(e,a) ((void)0)
  #define ASSERT_EQ_PTR(e,a) ((void)0)
  #define ASSERT_NODE(n,d,l,r) ((void)0)
#endif

int main(void)
{
    BST *bst = create_empty_tree();

    insert_tree(bst, 100);
    ASSERT_NODE(bst->root, 100, NULL, NULL);
    ASSERT_EQ_INT(1, bst->size);

    insert_tree(bst, 20);
    ASSERT_EQ_INT(20, bst->root->left->data);
    ASSERT_EQ_INT(2, bst->size);

    insert_tree(bst, 500);
    insert_tree(bst, 10);
    insert_tree(bst, 30);

    ASSERT_EQ_INT(5, bst->size);

    printf("in-order traversal is: ");
    traverse_inorder_tree(bst);
    return 0;
}
