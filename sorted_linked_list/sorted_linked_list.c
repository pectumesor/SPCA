//
// Created by Emerson Leonardo Azevedo Aguiar on 10/5/24.
//

#include "sorted_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  unsigned int frequency;
  struct node* next;
};

/*
 * This function takes two arguments:
 *
 * - `head`: pointer to the start of the sorted linked list
 * - `value`: value to insert into the list
 *
 * The function inserts the value into the list by adding a new node
 * with frequency 1 if the value is not yet present in the list or
 * or increasing the frequency of the value's node if it is already present.
 *
 * The function returns a pointer to the head of the modified list.
 */

 typedef struct node node;

 node* allocate_node(node* next, int value){

      node* newNode = (node *)malloc(sizeof(node));
      newNode -> next = next;
      newNode -> frequency = 1;
      newNode -> value = value;
      return newNode;
 }

struct node* insert_value(struct node* head, int value){

    // Answer goes here

    if (head == NULL){ //empty list
        head = allocate_node(NULL,value);
        return head;
    }

    if(head->value > value ){ //new node has a smaller value then head --> new head
      node* root = allocate_node(head,value);
      return root;
    }

    node* prev = NULL;
    node* curr = head;
    while (curr->value < value && curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }

    if(curr->value == value){
      curr->frequency++;
    } else if (curr->value < value && curr->next == NULL){
      node* tail = allocate_node(NULL,value);
      curr->next = tail;
    } else {
      node* mid = allocate_node(curr,value);
      prev->next = mid;
    }

    return head;
}

/*
 * This function takes two arguments:
 *
 * - `head`: pointer to the start of the sorted linked list
 * - `value`: value to delete into the list
 *
 * The function deletes the value from the list by removing the value's node
 * if the value had frequency 1 or decreasing the frequency if it was > 1.
 * If the value is not present, the function should not modify the list.
 *
 * The function returns a pointer to the head of the (modified) list.
 */
struct node* delete_value(struct node* head, int value){

    // Answer goes here

    if (head == NULL){
      return head;
    }

    node* prev = NULL;
    node* curr = head;
    while(curr->next != NULL && curr->value < value){
      prev = curr;
      curr = curr->next;
    }

    if(curr->value == value){
      if(curr->frequency > 1){
        curr->frequency--;
      } else if (curr->next == NULL) { //tail or only one node
          free(curr);
          if(prev == NULL){
            return NULL;
          } else {
            return head;
          }

      } else if (prev == NULL){
          free(curr);
          return curr->next;
      } else {
        prev->next = curr->next;
        free(curr);
        return head;
      }
    }

    return head;
}