/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.5:  One Away
 *
 * "There are 3 types of edits that can be performed on a string.
 *   - insert a char
 *   - remove a char
 *   - replace a char
 *
 * Given two strings, write a function to check if they are 1 edit (or 0 edits) away"
 *
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Setup TypeDef for bools
typedef enum { false, true } bool;

// Function prototypes
int createBitVector(char *string);
int toggle(int bitVector, int index);
int checkIfLessThanOneDifference(char *str1, char *str2);

int main(int argc, char *argv[]){
    // Get command line inputs
    char *str1 = argv[1];
    char *str2 = argv[2];

    // idea:  convert each string to a bitVector, using the toggle method, like before
    // then, AND the bitVectors
    // then iterate through the bitVectors,
    // and if more than number is different, we have don't have a "one away" match


}
