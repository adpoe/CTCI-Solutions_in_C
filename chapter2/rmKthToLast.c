/*
 *---------------------
 *|  CTCI - Chapter 2 |
 *---------------------
 * Problem 2.2:  Kth to last element from a Singly Linked List
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
    // handle error
    if (argc == 1) {
         printf("Please pass in a number for 'k' in range [1, 10]\n");
         return 1;
    }

    // get user input
    int kth = atoi(argv[1]);
    printf("SELECTED: K=%d\n", kth);

    if (kth>10 || kth<1 ) {
        printf("K must be in rage [1,10]");
        return 2;
    }


    // create linked list, 10 elements
    list *l = malloc( sizeof( list ) );
    l->next = NULL;
    insert_list(&l, "Last");
    insert_list(&l, "second to last");
    insert_list(&l, "third to last");
    insert_list(&l, "fourth to last");
    insert_list(&l, "fifth to last");
    insert_list(&l, "sixth to last");
    insert_list(&l, "seventh to last");
    insert_list(&l, "eighth to last");
    insert_list(&l, "ninth to last");
    insert_list(&l, "tenth to last");
    printf("list is allocated\n");


    // ASSUME:  We aren't keeping a count of the # items in the list
    // iterate through the LL, and get a count of how many items, assuming we don't keep a count
    int count = 0;
    list *iterator = l;
    printf("iterator starts at: %s\n", l->item);
    while(iterator->next != NULL) {
        printf("ITEM IS: %s\n", iterator->item);
        count++;
        iterator = iterator->next;
        printf("count = %d\n", count);
    }

    // Okay. Know that we have a count, we can iterate again to get a reference
    // to the kth to last item, then remove it.
    iterator = l;
    while(count > kth) {
        count--;
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
