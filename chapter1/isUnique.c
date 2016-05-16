/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.1:  is Unique
 *
 *"Implement an algorithm to determine if a string has all unique characters.
 *  What if you cannot use additional data structures?"
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * In-place solution with no additional data structures.
 * Uses pointers to check for a duplicate char, and exits if one is found.
 */
int main(int argc, char *argv[]){

    char *ptr_one;
    char *ptr_two;
    char *input_string = argv[1];

    int counter_one;
    int counter_two;

    int strLength = strlen(input_string);

    for (counter_one=0; counter_one < strLength; counter_one++) {
        for (counter_two=counter_one+1; counter_two < strLength; counter_two++) {

            // if we get a match exit
            char current_char = input_string[counter_one];
            char next_char = input_string[counter_two];
            if (current_char == next_char) {
                 printf("All characters are NOT unique.");
                 exit(0);
            }
        }
    }

    // if we make it this far, all the characters are unique
    printf("All characters are unique.");
}
