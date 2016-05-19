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
 *  Notes:  Using author's implementation, translated to C, because it's beautiful,
 *  and I never would've thought of it before this.
 *          Also, I want to understand it better.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Use a TypeDef to allow for booleans
typedef enum { false, true } bool;

// Create function Prototypes
bool isPermutationOfPalindrome(char *phrase);
int createBitVector(char *phrase);
int toggle(int bitVector, int index);
bool checkExactlyOneBitSet(int bitVector);

////////////////////////
////// FUNCTIONS ///////
////////////////////////
bool isPermutationOfPalindrome(char *phrase)
{
    int bitVector = createBitVector(phrase);
    bool result;
    if (bitVector == 0 || checkExactlyOneBitSet(bitVector))
        result = true;
    else
        result = false;

    return result;
}
/* Create a bit vector for the string. For each letter with value i,
 * toggle the ith bit */
int createBitVector(char *phrase)
{
    int bitVector = 0;
    int index;
    for(index=0; index<strlen(phrase); index++)
    {
        int x = (int)phrase[index];
        if (x == 32)
            continue; // ignore spaces
        bitVector = toggle(bitVector, x);
    }

    return bitVector;
}

/* Toggle the ith bit in the integer */
int toggle(int bitVector, int index)
{
    if (index < 0)  return bitVector;

    int mask = 1 << index; // set ith bit to 1, using a shift left
    if ((bitVector & mask) == 0) // if the bitVector and mask don't share any common bits set to 1
    {
        bitVector |= mask; // Or the bitVector with the mask and set it equal to that value
    }
    else
    {
        bitVector &= ~mask; // Otherwise, flip all the bits of mask
                            // AND the bitVector with that new value,
                           // and assign bitVector to that value
    }
    return bitVector;
}

/*
 * Check that exactly one bit is set by subtracting one from the integer and
 * ANDing it with the original integer
 */
bool checkExactlyOneBitSet(int bitVector)
{
    bool result;
    if ((bitVector & (bitVector - 1)) == 0)
        result = true;
    else
        result = false;

    return result;
}

/*
 * Main entry point: pass in the string to check as the first argument
 */
int main(int argc, char *argv[])
{
    // Get the string
    char *inputString = argv[1];

    if (isPermutationOfPalindrome(inputString) == true)
        printf("'%s' is a permutation of a palindrome.", inputString);
    else
        printf("'%s' is NOT a permutation of a Palindrome", inputString);



}
