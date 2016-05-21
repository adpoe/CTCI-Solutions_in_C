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
 * Utility method to malloc a 2D matrix
 */
int** malloc2Dmatrix(int** myMatrix, int rowDim, int colDim)
{
    // allocate the matrix first, with malloc
    myMatrix = malloc(rowDim * sizeof(*myMatrix));
    int i;
      for (i=0; i<rowDim; i++)
      {
        myMatrix[i] = malloc(colDim * sizeof(*myMatrix[i]));
      }
    return myMatrix;
}

/*
 * Utility method to free a 2D matrix
 */
void free2Dmatrix(int** myMatrix, int rowDim, int colDim)
{
    // free the matrix we created, to avoid memory leaks
    int i;
      for (i=0; i<rowDim; i++)
      {
        free(myMatrix[i]);
      }

    free(myMatrix);
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
    int **myMatrix, **trackingMatrix;
    int i,j;

    // allocate the matrix first, with malloc
    myMatrix = malloc2Dmatrix(myMatrix, rowDim, colDim);
    trackingMatrix = malloc2Dmatrix(trackingMatrix, rowDim, colDim);

    // fill the real matrix with 1's,
    // fill tracking matrix with 0's -- meaning 'false'
    for (i=0; i<rowDim; i++) {
        for(j=0; j<colDim; j++) {
            myMatrix[i][j] = 1;
            trackingMatrix[i][j] = 0;
        }
    }

    // add the zero element specified
    // and print resulting matrix
    myMatrix[zeroRow][zeroCol] = 0;
    printMatrix(myMatrix, rowDim, colDim);
    printf("\n\n\n\n");

    // find the zeros
    for(i=0; i<rowDim; i++) {
        for(j=0; j<colDim; j++) {
            if(myMatrix[i][j] == 0) {
                // mark the row/col in our tracking matrix
                trackingMatrix[i][j] = 1;
            } // end-if
        } // end inner-for
    } // end outer-for

    // zero out only the proper rows/cols
    for(i=0; i<rowDim; i++) {
        for(j=0; j<colDim; j++) {
            if(trackingMatrix[i][j] == 1) {
                // zero the row...
                // Using 3 nested for-loops because C is evil,
                // and I'm sick of trying to pass the 2D matrix to a function
                // and having the compiler yell at me.
                int colIndex;
                for(colIndex=0; colIndex<colDim; colIndex++) {
                    myMatrix[i][colIndex] = 0;
                } // end column replacement for

                // zero the col...
                // ditto re: the evilness of C, and its compiler
                // when working with malloc'd 2d-arrays
                int rowIndex;
                for(rowIndex=0; rowIndex<rowDim; rowIndex++) {
                    myMatrix[rowIndex][j] = 0;
                } // end row replacement for

            } // end-if
         } // end inner-for
    } // end outer-for

    // print the matrix again, after our update
    printMatrix(myMatrix, rowDim, colDim);

    // free the matrix, once we're done
    free2Dmatrix(myMatrix, rowDim, colDim);

}
