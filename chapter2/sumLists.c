/*
 *---------------------
 *|  CTCI - Chapter 2 |
 *---------------------
 * Problem 2.5:  Sum the values of two linked lists, treating each like a separate number
 *
 * Using a Linked List implementation from Skiena's Algorithm Design Manual
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structs/SListInt.c"
#include "../data_structs/hash.c"

/*
 * Implementation from:  http://stackoverflow.com/questions/213042/how-do-you-do-exponentiation-in-c
 */
int power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int main(int argc, char *argv[]) {
    // get user input
    int numberOne = atoi(argv[1]);
    printf("SELECTED: #=%d\n", numberOne);

    int numberTwo = atoi(argv[2]);
    printf("SELECTED: #=%d\n", numberTwo);

    // create linked list, for number one
    list *l1 = malloc( sizeof( list ) );
    l1->next = NULL;

    // same for number two
    list *l2 = malloc( sizeof( list  ) );
    l2->next = NULL;

    // get values of numberOne at each decimal place using mods
    int counter = 1;
    while (numberOne > 0) {
        int value = numberOne % 10;
        printf("value=%d\n",value);
        numberOne = numberOne/10;
        insert_list(&l1, value);
    }

    // get values of numberOne at each decimal place using mods
    counter = 1;
    while (numberTwo > 0) {
        int value = numberTwo % 10;
        numberTwo = numberTwo/10;
        insert_list(&l2, value);
    }

    // iterate through and make sure the number came out okay
    list *iterator = l1;
    printf("iterator starts at: %d\n", l1->item);
    while(iterator->next != NULL) {
        printf("ITEM IS: %d\n", iterator->item);
        iterator = iterator->next;
    }

    // iterate through and make sure the number came out okay
    iterator = l2;
    printf("iterator starts at: %d\n", l2->item);
    while(iterator->next != NULL) {
        printf("ITEM IS: %d\n", iterator->item);
        iterator = iterator->next;
    }

/*
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
*/

}
