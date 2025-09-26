#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_utils.h"

int** create_empty_matrix(char *matrixName, int *sizeRows, int *sizeCols) {
    int rows;
    int cols;
    bool validInput = false;

    do {
        printf("Enter rows and columns of %s matrix: ", matrixName);

        if (scanf("%d%d", &rows, &cols) != 2) {
            printf("Invalid input. Exiting program.\n");
            return NULL;
        }
        
        if (rows <= 0 || cols <= 0) {
            printf("Matrix Dimensions must be positive.\n");
        } 
        else if (rows > MAX_DIM || cols > MAX_DIM) {
            printf("Matrix Dimensions must be smaller than %d.\n", MAX_DIM);
        }
        else {
            validInput = true;
        }
    } while (validInput == false);
    
    int **rowsArray = (int**) malloc(rows * sizeof(int*));
    if (rowsArray == NULL) {
        printf("Could not allocate memory. Exiting program.");
        return NULL;
    } 

    for (int i = 0; i < rows; i++) {
        *(rowsArray + i) = (int*) malloc(cols * sizeof(int));
        if (*(rowsArray + i) == NULL) {
            printf("Could not allocate memory. Exiting program.");
            return NULL;
        }
    }

    *sizeRows = rows;
    *sizeCols = cols;

    return rowsArray;
}

// read_matrix()

void read_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;

            scanf("%d", &value);
            *(*(matrix + i) + j) = value;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}