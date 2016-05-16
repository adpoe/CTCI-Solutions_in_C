/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.2:  Check Permutation
 *
 *"Given two strings, write a method to decide if one is
 * a permutation of the other.""
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmpfunc( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int main(int argc, char *argv[]){
    // get strings as user args
    char *str1 = argv[1];
    char *str2 = argv[2];

    // get str lengths
    int strLen1 = strlen(str1);
    int strLen2 = strlen(str2);

    // lengths aren't equal, we can't have perms
    if (strLen1 != strLen2) {
        printf("Strings are NOT permutations");
        exit(0);
    }

    // sort each string, and if they aren't equal, then we don't have perms
    // sorts are done in place, because q-sort is in place
    // each sort is n(log(n)) on average, n^2 in worst case
    qsort(str1, (size_t) strlen(str1), (size_t) sizeof(char), cmpfunc);
    qsort(str2, (size_t) strlen(str2), (size_t) sizeof(char), cmpfunc);

    // check for equality using strcmp()
    int cmpResult = strcmp(str1, str2);

    if (cmpResult !=0) {
        printf("Strings are NOT permutations");
        exit(0);
    }

    // if we make it this far, strings are equal
    printf("Strings ARE permutations");
}
