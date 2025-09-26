#include <stdio.h>
#include "matrix_utils.h"

int main() {
    int rows1;
    int cols1;
    int **matrix1;

    int rows2;
    int cols2;
    int **matrix2;

    matrix1 = create_empty_matrix("first", &rows1, &cols1);
    if (matrix1 == NULL) return 1;

    matrix2 = create_empty_matrix("second", &rows2, &cols2);
    if (matrix2 == NULL) return 1;

    if (cols1 != rows2) {
        printf("Error: Incompatible dimensions for multiplication.\n");
        return 2;
    }

    printf("Enter elements of first matrix: ");
    read_matrix(matrix1, rows1, cols1);

    printf("Enter elements of second matrix: ");
    read_matrix(matrix2, rows2, cols2);

    print_matrix(matrix1, rows1, cols1);

    return 0;
}