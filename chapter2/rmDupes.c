/*
 *---------------------
 *|  CTCI - Chapter 2 |
 *---------------------
 * Problem 2.1:  Remove Dupes From a LinkedList
 *
 * Using @tonius's HashTable Implementation, from: https://gist.github.com/tonious/1377667
 * Using a Linked List implementation from Skiena's Algorithm Design Manual
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../data_structs/SList.c"
#include "../data_structs/hash.c"

int main(int argc, char *argv[]){
    // create linked list with some dupes
    list *l = malloc( sizeof( list ) );
    l->next = NULL;
    insert_list(&l, "one");
    insert_list(&l, "two");
    insert_list(&l, "three");
    insert_list(&l, "zero");
    insert_list(&l, "one");
    insert_list(&l, "two");
    insert_list(&l, "four");
    insert_list(&l, "five");

    // print the list
    list *iterator = l;
    while (iterator->next != NULL) {
        printf("ITEM IS: %s\n", iterator->item);
        iterator = iterator->next;
    }

    // test hash table
	hashtable_t *hashtable = ht_create( 65536 );

	ht_set( hashtable, "key1", "inky" );
	ht_set( hashtable, "key2", "pinky" );
	ht_set( hashtable, "key3", "blinky" );
	ht_set( hashtable, "key4", "floyd" );

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

    // add our strings from the LL to the hashtable
    hashtable_t *ht = ht_create( 65536 );

    iterator = l;
    while (iterator->next != NULL) {
        if (ht_get( hashtable, iterator->item) != NULL) {
            delete_list(&l, iterator->item);
        } else {
            ht_set( hashtable, iterator->item, iterator->item );
        }

        iterator = iterator->next;
    }

    // print everything out again to make sure the right stuff was removed
    iterator = l;
    while (iterator->next != NULL) {
        printf("ITEM IS: %s\n", iterator->item);
        iterator = iterator->next;
    }



	return 0;

}
