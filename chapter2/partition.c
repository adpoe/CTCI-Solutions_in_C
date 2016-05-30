/*
 *---------------------
 *|  CTCI - Chapter 2 |
 *---------------------
 * Problem 2.4:  Partition a LinkedList such that everything left of var x is <,
 * and everything right is >
 *
 * Using a Linked List implementation from Skiena's Algorithm Design Manual
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structs/SList.c"
#include "../data_structs/hash.c"

//think:  can swap each item, bubble sort style, but that kind of sucks..., is o(n^2)
// or: could iterate through, and do a compare on each element, then build two lists, as we do it...
// one list for <, and one for >. Then, when we're done, make node->prev the the < list, and node->next the > list.  Not bad.
int main(int argc, char *argv[]) {

    // get user input, using chars instead of ints for simplicity's sake, given code already written
    char *x = argv[1];

    // create linked list
    list *l = malloc( sizeof( list ) );
    l->next = NULL;
    insert_list(&l, "H");
    insert_list(&l, "C");
    insert_list(&l, "G");
    insert_list(&l, "J");
    insert_list(&l, "I");
    insert_list(&l, "F");
    insert_list(&l, "A");
    insert_list(&l, "K");
    insert_list(&l, "D");
    insert_list(&l, "E");
    insert_list(&l, "B");
    printf("list is allocated\n");

    list *lessThan = malloc( sizeof( list ) );
    lessThan->next = NULL;
    lessThan->item = "\0";

    list *greaterThan = malloc( sizeof( list ) );
    greaterThan->next = NULL;
    greaterThan->item = x;

    list *iterator = l;
    printf("iterator starts at: %s\n", l->item);
    while(iterator->next != NULL) {
        printf("ITEM IS: %s\n", iterator->item);
        printf("ITEM[0] IS: %c\n", iterator->item[0]);
        printf("X[0] IS: %c\n", x[0]);

        // perform compare, and assign elements to correct list
        if (iterator->item[0] <= x[0]) {
            insert_list(&lessThan, iterator->item);
        } else {
             insert_list(&greaterThan, iterator->item);
        }

        printf("made it past compare\n");

        // increment iterator
        iterator = iterator->next;
    }
/* Works but extra node
    // make a node for the value we're comparing on
    list *xNode = malloc( sizeof( list ) );
    xNode->next = NULL;
    xNode->item = x;

    xNode->next = lessThan;

    iterator = greaterThan;
    while(iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = xNode;
*/

    iterator = greaterThan;
    while(iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = lessThan;

    // and display everything, one last time to show that kth to last was deleted
    printf("----LIST IS NOW-----\n");
    iterator = greaterThan;
    while(iterator->next != NULL) {
        printf("ITEM=%s\n", iterator->item);
        iterator = iterator->next;
    }

}
