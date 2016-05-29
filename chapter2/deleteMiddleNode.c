/*
 *---------------------
 *|  CTCI - Chapter 2 |
 *---------------------
 * Problem 2.3:  Delete a node in the middle of a linked list (any but first or last is okay)
 *
 * Using a Linked List implementation from Skiena's Algorithm Design Manual
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structs/SList.c"
#include "../data_structs/hash.c"

int main(int argc, char *argv[]) {

    // create linked list, 10 elements
    list *l = malloc( sizeof( list ) );
    l->next = NULL;
    insert_list(&l, "A");
    insert_list(&l, "B");
    insert_list(&l, "C");
    insert_list(&l, "D");
    insert_list(&l, "E");
    insert_list(&l, "F");
    printf("list is allocated\n");


    list *iterator = l;
    printf("iterator starts at: %s\n", l->item);
    while(strcmp(iterator->next->item, "D") != 0) {
        printf("ITEM IS: %s\n", iterator->item);
        iterator = iterator->next;
    }

    printf("ended at: %s\n", iterator->item);
    // delete the kth to last item, using our reference to it
    printf("Deleting item #: %s\n", iterator->item);
    delete_list(&l, iterator->item);

    // and display everything, one last time to show that kth to last was deleted
    printf("----LIST IS NOW-----\n");
    iterator = l;
    while(iterator->next != NULL) {
        printf("ITEM=%s\n", iterator->item);
        iterator = iterator->next;
    }

}
