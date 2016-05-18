/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.4:  Palindrome Permutation
 *
 * "Given a string, write a function to check if it is a permutation of a palindrome.
 *  A palindrome is a word of phrase that is the same forwards and backwards.
 *  A permutation is a rearrangement of letters. The palindrome does not need to be limited
 *  to just dictionary words."
 *
 * Notes:  Permutation method taken from:  http://stackoverflow.com/questions/9148543/program-to-print-permutations-of-given-elements
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// variable size array struct
struct var_length_array {
    size_t size;
    size_t capacity;
    int numPermutations = 0;
    int nextFreeIndex = 0;
    int arrayCurrentSize = 100;
    char *allPerms[arrayCurrentSize];
}

// standard C swap method
void swap(char *str, int indexOne, int indexTwo)
{
    // create a temp char, so we don't lose the initial char in our swap
    char temp = str[indexOne];

    // swap one char in our string
    str[indexOne] = str[indexTwo];
    str[indexTwo] = temp;

}

// need a method to do the actual permutation
void permute(char *string, int start, int end)
{
    // base case
    if (start == end)
    //{
        // add to the array
        return
    //}

    // recursive case
    permute(string, start + 1, end);

    // once we're in the recursive case, swap for every other permutation
    // this runs only after we've bottomed out and hit each base case
    int i;
    for (i = start + 1; i < end; i++)
    {
        // if the char at the current position is the same as the character we would swap,
        // just skip to next iteration
        if (string[start] == string[i])
            continue;

        // else, we swap permute recursively
        swap(string, start, i);
        permute(string, start + 1, end);
        // and swap back, so we don't miss any permutations
        swap(string, start, i);
    }
}

int main(int argc, char *argv[])
{
    // Get the string
    char *inputString = argv[1];
    // need to get all permutations


    // need to iterate through all the permutations and see if any is a palindrome
}
