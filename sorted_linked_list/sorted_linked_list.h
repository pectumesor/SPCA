#ifndef __LL_H_
#define __LL_H_

/*
 * Sorted linked list
 */

/*
 * Insert a value into the linked list
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern struct node * insert_value( struct node * head, int value );

/*
 * Delete a value into the linked list
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern struct node * delete_value( struct node * head, int value );

#endif // __LL_H_
