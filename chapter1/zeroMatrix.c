/*
 *---------------------
 *|  CTCI - Chapter 1 |
 *---------------------
 * Problem 1.8: Zero Matrix
 *
 *"Write an algorithm such that if an element in an MxN matrix is zero,
* then its entire ROW and COLUMN are set to zero.""
*
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Utility function to print a 2d matrix
 */
void printMatrix(int** matrix, int numRows, int numCols)
{
    // print the matrix
    int i;
    int j;
    for(i=0;i<numRows; i++){
        printf("\n");
        for(j=0; j<numCols; j++){
            printf("%d", matrix[i][j]);
            printf("\t");
        }
    }
}

/*
 * Main entry point for the program
 */
int main(int argc, char *argv[])
{
    // get dimensions of matrix
    // Usage:  ./zeroVector 4 3 "(2,1)"
    int rowDim = atoi(argv[1]);
    int colDim = atoi(argv[2]);
    int zeroRow = atoi(&argv[3][1]);
    int zeroCol = atoi(&argv[3][3]);

    printf("Row Dim: %d\n", rowDim);
    printf("Col Dim: %d\n", colDim);
    printf("Zero Row: %d\n", zeroRow);
    printf("Zero Col: %d\n", zeroCol);

    // vars needed for the matrix
    int **myMatrix;
    int i,j;

    // allocate the matrix first, with malloc
    myMatrix = malloc(rowDim * sizeof(*myMatrix));
      for (i=0; i<rowDim; i++)
      {
        myMatrix[i] = malloc(colDim * sizeof(*myMatrix[i]));
      }

    // fill the matrix with 1's
    for (i=0; i<rowDim; i++) {
        for(j=0; j<colDim; j++) {
            myMatrix[i][j] = 1;
        }
    }

    // add the zero element specified
    // and print resulting matrix
    myMatrix[zeroRow][zeroCol] = 0;
    printMatrix(myMatrix, rowDim, colDim);

}
