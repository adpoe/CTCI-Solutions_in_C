/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.3:  URLify
 *
 * "Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space
 * at the end to hold the additional characters, and that you are given the "true" length of the string."
 *
 * Note: Perform the operation in place.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    // get input string, and true length
    int trueLength = atoi(argv[2]);
    char *inputString = argv[1];

    // make sure the input string is null terminated
    strcat(inputString, "\0");

    // build the new string
    char outputString[trueLength];

    int index;
    int writeIndex = 0;
    size_t inputStringLength = strlen(argv[1]);
    for(index=0; index<inputStringLength; index++)
    {
        if (inputString[index] == ' ')
        {
            outputString[writeIndex] = '%';
            outputString[++writeIndex] = '2';
            outputString[++writeIndex] = '0';
            writeIndex++;
        }
        else
        {
            char currentChar = inputString[index];
            outputString[writeIndex] = currentChar;
            writeIndex++;
        }
    }

    printf("URLified string is:  %s", outputString);
}
