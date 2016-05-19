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
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Setup TypeDef for bools
typedef enum { false, true } bool;

// Function prototypes
int createBitVector(char *string);
int toggle(int bitVector, int index);
int generateDifference(int vectorOne, int vectorTwo);


/* Create a bit vector for a string. For each letter with value i,
 * toggle the ith bit */
int createBitVector(char *string)
{
     int bitVector = 0;
     int index;
     for(index=0; index<strlen(string); index++)
     {
         int x = (int)string[index];
         if (x == 32)
             continue;
        bitVector = toggle(bitVector, x);
     }

     return bitVector;
}

/* Toggle the ith bit in the integer */
int toggle(int bitVector, int index)
{
    if (index < 0)  return bitVector;

    int mask = 1 << index;
    if ((bitVector & mask) == 0)
        bitVector |= mask;
    else
        bitVector &= ~mask;

    return bitVector;
}

int generateDifference(int bitVectorOne, int bitVectorTwo)
{
    int vectorLength = sizeof(int) * 8;
    printf("vectorLength=%d\n\n", vectorLength);
    int totalDifference = 0;

    int bitIndex;
    for (bitIndex=0; bitIndex < vectorLength; bitIndex++)
    {
        int v1bit;
        int v2bit;

        // get the bit value for each position in both vectors
        if (bitVectorOne & (1<<bitIndex))
            v1bit = 1;
        else
            v1bit = 0;

        if (bitVectorTwo & (1<<bitIndex))
            v2bit = 1;
        else
            v2bit = 0;

        printf("char=%c, v1bit=%d\n", bitIndex+'`', v1bit);
        printf("char=%c, v2bit=%d\n\n", bitIndex+'`', v2bit);

        if (v1bit != v2bit)
            totalDifference += 1;
    }

    return totalDifference;
}

int main(int argc, char *argv[])
{
    // Get command line inputs
    char *str1 = argv[1];
    char *str2 = argv[2];

    // idea:  convert each string to a bitVector, using the toggle method, like before
    int bitVectorOne = createBitVector(str1);
    int bitVectorTwo = createBitVector(str2);

    // then find the difference between the vectors,
    // and if difference is < 1 we are one away
    int vectorDifference = generateDifference(bitVectorOne, bitVectorTwo);

    if (vectorDifference <= 2)
        printf("'%s' and '%s' ARE one edit away.\n", str1, str2);
    else
        printf("'%s' and '%s' are NOT one edit away.\n", str1, str2);

    printf("difference is: %d\n", vectorDifference);

}
