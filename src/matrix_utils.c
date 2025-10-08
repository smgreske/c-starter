#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_utils.h"

/**
 * @brief This function accepts matrix dimensions from user in the form of rows and columns.
 * @param matrixName the name of the matrix (to be used in prompts)
 * @param rows the number of rows (by reference)
 * @param cols the number of columns (by reverence)
 * @return error code
 */
int get_matrix_dimensions(char *matrixName, int *rows, int *cols) {

    bool validInput = false; // used to determine whether to continue looping (if invalid input has been entered)
    
    do {
        printf("Enter rows and columns of %s matrix: ", matrixName);
        
        // checks whether user has entered two integers
        if (scanf("%d%d", rows, cols) != 2) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }
        
        // checks whether values are positive
        if (*rows <= 0 || *cols <= 0) {                                 
            printf("Matrix Dimensions must be positive.\n");
        } 

        // checks whether values are under a maximum allowed size
        else if (*rows > MAX_DIM || *cols > MAX_DIM) {                      
            printf("Matrix Dimensions must be smaller than %d.\n", MAX_DIM);
        }
        else {
            validInput = true;
        }
    } while (validInput == false);

    printf("\n");
    return 0;
};

/**
 * @brief This function allocates memory for a matrix 
 * @param rows the number of rows
 * @param cols the number of columns
 * @return pointer to the new matrix
 */
int** create_empty_matrix(int rows, int cols) {
    
    // allocates memory for an array of pointers (number of rows)
    int **matrix = (int**) malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Could not allocate memory. Exiting program.");
        return NULL;
    } 

    // allocates memory for each row (number of columns)
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Could not allocate memory. Exiting program.");
            return NULL;
        }
    }
    
    return matrix;
}

/**
 * @brief This function allows user to populate a matrix with integer data
 * @param matrixName the name of the matrix (to be used in prompts)
 * @param matrix the matrix to be populated
 * @param rows the number of rows
 * @param cols the number of columns
 * @return error code
 */
int read_matrix(char *matrixName, int **matrix, int rows, int cols) {
    printf("Enter elements of %s matrix: ", matrixName);

    for (int i = 0; i < rows; i++) {        // loop through matrix rows
        for (int j = 0; j < cols; j++) {    // loop through matrix columns
            int value;
             if (scanf("%d", &value) != 1) {                    // checks whether value entered is an integer
                printf("Invalid input. Exiting program.\n");
                return 1;
            }
            matrix[i][j] = value;
        }
    }
    printf("\n");
    return 0;
}

/**
 * @brief This function accepts two matrices and finds their product
 * @param matrix1 first matrix to be multiplied
 * @param matrix2 second matrix to be multiplied
 * @param matrixProduct matrix to store result of the multiplication
 * @param rows1 the number of rows in the first matrix
 * @param cols1 the number of columns in the first matrix
 * @param cols2 the number of columns in the second matrix
 * @return error code
 */
void multiply_matrix(int **matrix1, int **matrix2, int **matrixProduct, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            matrixProduct[i][j] = 0;

            // algorithm for matrix multiplication
            for (int k = 0; k < cols1; k++) {
                matrixProduct[i][j] = matrixProduct[i][j] + (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
}


/**
 * @brief This function prints a matrix to the screen
 * @param matrix the matrix to be printed
 * @param rows the number of rows
 * @param cols the number of columns
 */
void print_matrix(int **matrix, int rows, int cols) {
    printf("Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief This function frees memory allocated using malloc
 * @param matrix pointer to first element of matrix
 * @param rows the number of rows
 */
void free_memory(int **matrix, int rows) {

    // free memory for each row
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        } 
    // free memory for pointers to each row
    free(matrix);
}
