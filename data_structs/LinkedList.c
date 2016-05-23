/*
 *----------------------
 *|  Doubly-Linked List |
 *----------------------
 * A Doubly LinkedList implementation in C
 *
 * Based on Sedgewick's Java Implementation: http://algs4.cs.princeton.edu/13stacks/DoublyLinkedList.java.html
 * */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum { false, true } boolean;

typedef struct Node Node;
struct Node {
   void *item;
   Node *next;
   Node *prev;
};

typedef struct DoubleyLinkedList DoubleyLinkedList;
struct DoubleyLinkedList {
    Node *pre;
    Node *post;
    int n;
};

void initNode(Node *Node) {
    Node->item = NULL;
    Node->next = NULL;
    Node->prev = NULL;
}
void initDList(DoubleyLinkedList *DList) {
    initNode(DList->pre);
    initNode(DList->post);
    DList->n = 0;
    DList->pre->next = DList->post;
    DList->post->prev = DList->pre;
}

boolean isEmpty(DoubleyLinkedList *DList) {
    if (DList->n == 0)
        return true;
    else
        return false;
}
/*
 * Driver program
 */
int main(int argc, char *argv[]) {

}
