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
    int counterOne = 0;
    while (numberOne > 0) {
        int value = numberOne % 10;
        printf("value=%d\n",value);
        numberOne = numberOne/10;
        insert_list(&l1, value);
        counterOne++;
    }

    // get values of numberOne at each decimal place using mods
    int counterTwo = 0;
    while (numberTwo > 0) {
        int value = numberTwo % 10;
        numberTwo = numberTwo/10;
        insert_list(&l2, value);
        counterTwo++;
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


    // rebuild my number from the list itself
    int listNumOne=0;
    int listNumTwo=0;


    iterator = l1;
    printf("iterator starts at: %d\n", l1->item);
    int placeValue = counterOne;
    while(iterator->next != NULL) {
        listNumOne +=  iterator->item * power(10, placeValue - 1);
        iterator = iterator->next;
        printf("NUMBER IS: %d\n", listNumOne);
        placeValue--;
    }

    iterator = l2;
    printf("iterator starts at: %d\n", l2->item);
    placeValue = counterTwo;
    while(iterator->next != NULL) {
        listNumTwo +=  iterator->item * power(10, placeValue - 1);
        iterator = iterator->next;
        printf("NUMBER IS: %d\n", listNumTwo);
        placeValue--;
    }
    printf("listNumOne = %d\n", listNumOne);
    printf("listNumTwo = %d\n", listNumTwo);
    printf("Sum = %d\n", listNumOne + listNumTwo);

}
