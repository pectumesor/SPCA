#include "binary_search_tree.h"

tree_node* insert(tree_node* root, int key, int value) {
  
    if (root == NULL){
      tree_node *newNode = (tree_node *) malloc(sizeof(tree_node));
      newNode->key = key;
      newNode->value = value;
      newNode->left = NULL; newNode->right = NULL;
      return newNode;
    } else if (root->key < key){
      root->right = insert(root->right,key,value);
    } else if (root->key > key){
      root->left = insert(root->left,key,value);
    } 
  return root;
}

tree_node* lookup(tree_node* root, int key) {
  
  if (root == NULL){
    return root;
  }
  
  if (root->key < key) return lookup(root->right,key);
  if (root->key > key) return lookup(root->left,key);

  return root;
}

tree_node* delete(tree_node* root, int key) {
  
  if (root == NULL){
    return NULL;
  }
  
  if (root->key == key){
    
      if (root->left == NULL && root->right == NULL){ //no children
          free(root);
          return NULL;
      } else if (root->left != NULL && root->right == NULL){ //only left children
          tree_node *tmp = root->left;
          free(root);
          return tmp;
      } else if (root->left == NULL && root->right != NULL){ //only right children
        tree_node *tmp = root->right;
        free(root);
        return tmp;
      } else {  //has both children
        //need to find inorder successor(once right, then always left)
        tree_node* succ = root->right;
        tree_node* father;
        while (succ->left != NULL){
          father = succ;
          succ = succ->left;
        }
        father->left = succ->right;
        succ->left = root->left;
        succ->right = root->right;
        free(root);
        return succ;
      }
  } else if (root->key < key){
     root->right = delete(root->right,key);
     return root;
  } else if (root->key > key){
    root->left = delete(root->left,key);
    return root;
  }
  return root;
}