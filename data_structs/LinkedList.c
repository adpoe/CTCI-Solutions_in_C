/*
 *----------------------
 *|  Doubly-Linked List |
 *----------------------
 * A Doubly LinkedList implementation in C
 *
 * */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node Node;
struct Node {
   void *item;
   Node *next;
   Node *prev;
};
