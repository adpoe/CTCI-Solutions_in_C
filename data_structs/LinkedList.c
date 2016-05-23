/*
 *----------------------
 *|  Doubly-Linked List |
 *----------------------
 * A Doubly LinkedList implementation in C
 *
 */

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
    Node *head;
    Node *tail;
    int n;
};

void initNode(Node *Node) {
    Node->item = NULL;
    Node->next = NULL;
    Node->prev = NULL;
}

void initDList(DoubleyLinkedList *DList) {
    DList->head = malloc( sizeof(Node) );
    DList->tail = DList->head;
    initNode(DList->head);
    DList->n = 0;
    DList->head->next = DList->tail;
    DList->tail->prev = DList->head;
}

boolean isEmpty(DoubleyLinkedList *DList) {
    if (DList->n == 0)
        return true;
    else
        return false;
}

void add(DoubleyLinkedList *DList, void *item) {
    // create new node
    Node *newNode = malloc( sizeof(Node) );
    newNode->item = item;
    printf("NewNode->item = %d\n", *(int *)newNode->item);

    // get a tail ref
    Node *oldTail = DList->tail;

    printf("inside add\n");
    // add our new node after the tail
    oldTail->next = newNode;
    newNode->prev = oldTail;

    // count our new value in the list size
    DList->n++;
    DList->tail = newNode;
    printf("Head->next->item = %d\n", *(int *)DList->head->next->item);
}

Node* createIterator(DoubleyLinkedList *DList) {
    // return an iterator Node, pointing to head->next
    Node *iterator = malloc( sizeof( Node  ) );
    iterator = DList->head->next;
    printf("created iterator successfully\n");
    return iterator;
}

void removeNode(DoubleyLinkedList *DList, Node *removeNode) {

    // do nothing if the DList we're operating on is actually empty
    if (DList->n < 1)
        return;


    //printf("old prev is: %d\n", *(int *)removeNode->prev->item);
    //printf("old next is: %d\n", *(int *)removeNode->next->item);
    // cut the current node out of the list
    removeNode->next->prev = removeNode->prev;
    //printf("New prev is: %d\n", *(int *)removeNode->next->prev->item);
    removeNode->prev->next = removeNode->next;
    //printf("New next is: %d\n", *(int *)removeNode->next->item);
    //printf("Confirm list intact: %d\n", *(int *)removeNode->prev->next->item);

    // null out everything in removeNode and clean up after it
    removeNode->item = NULL;
    removeNode->next = NULL;
    removeNode->prev = NULL;
    free(removeNode->next);
    free(removeNode->prev);
    free(removeNode);


    // account for the removal
    DList->n--;

    printf("remove successful\n");
}

void printListInts(DoubleyLinkedList *DList) {
    Node *iterNode = DList->head->next;
    while (iterNode->item != NULL)
    {
        printf("iterNode->item=%d\n", *(int *)iterNode->item);
        //printf("iterNode->next=%d\n\n", *(int *)iterNode->next);
        if (iterNode->next == NULL)
            break;
        else
            iterNode = iterNode->next;

        printf("segfault isn't here\n");
    }
}

/*
 * Driver program
 */
int main(int argc, char *argv[]) {

    DoubleyLinkedList *DL = malloc( sizeof(DoubleyLinkedList) );
    initDList(DL);

    // add one
    int itemOne = 0;
    void *item_ptr;
    item_ptr = &itemOne;
    add(DL, item_ptr);

    // add two
    int itemTwo = 1;
    void *itemTwo_ptr;
    itemTwo_ptr = &itemTwo;
    printf("made it here\n");
    add(DL, itemTwo_ptr);

    int i;
    int arr[] = {2,3,4,5,6,7,8,9,10,11,12};
    for (i=0; i<9; i++) {
        int nextItem = arr[i];
        printf(">> Next item is: %d\n", arr[i]);
        void *nextItem_ptr;
        nextItem_ptr = &arr[i];
        add(DL, nextItem_ptr);
    }


    // print everything in the list
    Node *iterNode = DL->head->next;
    while (iterNode->item != NULL)
    {
        printf("iterNode->item=%d\n", *(int *)iterNode->item);
        //printf("iterNode->next=%d\n\n", *(int *)iterNode->next);
        if (iterNode->next == NULL)
            break;
        else
            iterNode = iterNode->next;

        printf("segfault isn't here\n");
    }

    printf("---------\n\n\n");
    printListInts(DL);

    // try removal and iteration
    Node *iterator =  createIterator(DL);
    printf("Iterator's item is: %d\n", *(int *)iterator->item);
    printf("Iterator->Next's item is: %d\n", *(int *)iterator->next->item);
    iterator = iterator->next;
    printf("Iterator's item is: %d\n", *(int *)iterator->item);
    iterator = iterator->next;
    printf("Iterator's item is: %d\n", *(int *)iterator->item);
    iterator = iterator->next;
    printf("Iterator's item is: %d\n", *(int *)iterator->item);

    removeNode(DL, iterator);

    printListInts(DL);


    // check removal of node after head
    Node *newIterator = createIterator(DL);
    removeNode(DL, newIterator);

    printListInts(DL);

}
