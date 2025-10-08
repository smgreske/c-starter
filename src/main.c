#include <stdio.h>
#include "matrix_utils.h"

/**
 * @brief This program accepts dimensions and values for two matrices from a user. It then performs matrix multiplication and outputs the resulting matrix
 * @return Error code: 1 - Error entering user input, 2 - Matrix dimensions aren't compatible for multiplication, 3 - Unable to allocate memory
 */
int main() {

    int rows1; 
    int cols1;
    int rows2;
    int cols2;

    // get matrix dimensions from user
    if (get_matrix_dimensions("first", &rows1, &cols1)) return 1;
    if (get_matrix_dimensions("second", &rows2, &cols2)) return 1;

    // check whether matrix dimensions are compatible for multiplication
    if (cols1 != rows2) {
        printf("Error: Incompatible dimensions for multiplication.\n");
        return 2;
    }

    // create empty matrices
    int **matrix1 = create_empty_matrix(rows1, cols1);
    if (matrix1 == NULL) return 3;

    int **matrix2 = create_empty_matrix(rows2, cols2);
    if (matrix2 == NULL) return 3;

    int **matrixProduct = create_empty_matrix(rows1, cols2);
    if (matrixProduct == NULL) return 3;

    // get matrix data from user
    if (read_matrix("first", matrix1, rows1, cols1)) return 1;
    if (read_matrix("second", matrix2, rows2, cols2)) return 1;

    multiply_matrix(matrix1, matrix2, matrixProduct, rows1, cols1, cols2);
    print_matrix(matrixProduct, rows1, cols2);

    free_memory(matrix1, rows1);
    free_memory(matrix2, rows2);
    free_memory(matrixProduct, rows1);

    return 0;
}