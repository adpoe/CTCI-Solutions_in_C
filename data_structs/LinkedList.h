#ifndef LINKEDLIST_H_   /* Include guard */
#define LINKEDLIST_H_

typedef struct Node Node;
struct Node {
   void *item;
   Node *next;
   Node *prev;
};

typedef struct DoubleyLinkedList DoubleyLinkedList;
struct DoublyLinkedList {
    Node pre;
    Node post;
    int n;
};

int foo(int x);  /* An example function declaration */

#endif // LINKEDLIST_H_
