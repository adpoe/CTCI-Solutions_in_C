/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.9: String Rotation
 *
 * "String Rotation: Assume you have a method isSubstring() which checks if
 * one word is a substring of another. Given two strings, s1 and s2,
 * write code to check if s2 is a rotation of s1 using only one call to
 * isSubstring()."
 *
 * Ex:  "waterbottle" is a rotation of "erbottlwat"
 *
 * Notes: We can use strstr("Longer string", "substring") for this, in C
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // get the command line args
    char *fullString = argv[1];
    char *subString = argv[2];

    // concat the first string with itself
    char concatString[(2*strlen(fullString))];
    strcat(concatString, fullString);
    strcat(concatString, fullString);
    //printf("Confirm string concatted with itself: %s", concatString);

    if (strstr(concatString, subString))
        printf("String Rotation Found\n");
    else
        printf("String rotation NOT found\n");

}
