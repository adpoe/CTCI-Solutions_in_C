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
    printf("\n\n\n");


    /////////////////////////////
    ///// ROTATE THE MATRIX /////
    /////////////////////////////
    int dimension = matrixDimension;
    int outputMatrix[dimension][dimension];

    // IDEA:
    // row1 = colN
    // row2 = colN-1
    // .
    // .
    // .
    // Until N=0
    int fromRow = 0;
    int fromCol = 0;
    int toRow = 0;
    int toCol = dimension-1;

    while(toCol>-1)
    {
        // fill in the nth column
        for(toRow=0; toRow<dimension; toRow++) {
            //printf("fromCol = %d\n", fromCol);
            //printf("fromRow = %d\n\n", fromRow);
            //printf("fromCol = %d\n", toCol);
            //printf("fromRow = %d\n\n", toRow);

            outputMatrix[toRow][toCol] = myMatrix[fromRow][fromCol];
            fromCol++;
        }

        fromCol=0;
        fromRow++;
        toCol -= 1;
    }

    // print the matrix
    //int i;
    //int j;
    for(i=0;i<dimension; i++){
        printf("\n");
        for(j=0; j<dimension; j++){
            printf("%d", outputMatrix[i][j]);
            printf("\t");
        }
    }
}
