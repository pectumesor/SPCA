#include <stdlib.h>

typedef struct tree_node {
  int key;
  int value;
  struct tree_node* left;
  struct tree_node* right;
} tree_node;

tree_node* insert(tree_node* root, int key, int value);
tree_node* lookup(tree_node* root, int key);
tree_node* delete(tree_node* root, int key);