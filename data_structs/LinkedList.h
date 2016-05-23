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


void initNode(Node *Node);
void initDList(DoubleyLinkedList *DList);
boolean isEmpty(DoubleyLinkedList *DList);
void add(DoubleyLinkedList *DList, void *item);
Node* createIterator(DoubleyLinkedList *DList)
void removeNode(DoubleyLinkedList *DList, Node *removeNode);
void printListInts(DoubleyLinkedList *DList);


#endif // LINKEDLIST_H_
