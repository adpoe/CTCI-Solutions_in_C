/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.6:  String Compression
 *
 * "Implement a method to perform a basic string compression using the counts
 * of repeated characters.
 * - Example:  aabcccccaaa -> a2b2c5a3
 * If the "compressed" string would not be a smaller than the original string,
 * the method should return the original string. Can assume only letters (a-z)"
 *
 * */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Setup TypeDef for bools
typedef enum { false, true }  bool;

// count the number of contiguous repeats in each string and replace
char* compress(char* str, int maxLen)
{
    char *initialString = str;
    char compressedStr[maxLen];
    int compressedIndex = 0;

    int index;
    for (index=0; index<maxLen; index++)
    {
        // count how many contiguous repeated characters we have
        char initialCharThisSequence = initialString[index];
        printf("Initial Char this sequence: %c\n", initialCharThisSequence);
        printf("Index is: %d\n", index);
        int count = 1;
        if (initialCharThisSequence == initialString[index + 1])
        {
            while( initialCharThisSequence == initialString[index + 1] )
            {
                count++;
                index++;
            }
        }

        // write the compressed string when we leave the while loop
        compressedStr[compressedIndex++] = initialCharThisSequence;
        printf("Compressed string index is: %d\n", compressedIndex);
        printf("Writing value: %c\n", initialCharThisSequence);
        char countAsChar = count + '0';
        compressedStr[compressedIndex++] = countAsChar;
        printf("Compressed string index is: %d\n", compressedIndex);
        printf("Writing value: %c\n\n", countAsChar);


    }
    // ensure the compressed string is null terminated when we exit the loop
    compressedStr[++compressedIndex] = '\0';

    // malloc  a string on the heap to return, so we don't return stack memory
    char *returnString = malloc(strlen(compressedStr) * sizeof(char));
    strcpy(returnString, compressedStr);

    return returnString;
}


int main(int argc, char *argv[])
{
    // get input string and its length
    char *inputString = argv[1];
    int inputLen = strlen(inputString);

    char *compressedString = compress(inputString, inputLen);

    // print the smaller string, no matter what
    if (strlen(inputString) < strlen(compressedString))
        printf("Compressed string is LONGER than input string, so we don't compress, output is: \"%s\"", inputString);
    else
        printf("Compressed string is: \"%s\"", compressedString);

    // free the malloc'd string before we exit
    free(compressedString);
}

