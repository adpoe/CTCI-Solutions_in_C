/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.7: Rotate a Matrix
 *
 *"Given an image represented by an NxN matrix,
 * where each pixel in the image is 4 bytes,
 * write a method to rotate the matrix by 90 degrees.
 * Can you do this in place?""
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Create an example matrix
    int matrixDimension = atoi(argv[1]);
    int myMatrix[matrixDimension][matrixDimension];

    // populate the matrix
    int i;
    int j;
    for(i=0; i<matrixDimension; i++) {
        int count = 0;
        for(j=0; j<matrixDimension; j++) {
            myMatrix[i][j] = count++;
        }
    }

    // print the matrix
    for(i=0;i<matrixDimension; i++){
        printf("\n");
        for(j=0; j<matrixDimension; j++){
            printf("%d", myMatrix[i][j]);
            printf("\t");
        }
    }

}
