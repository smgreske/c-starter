#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_DIM 1000

int get_matrix_dimensions(char *matrixName, int *rows, int *cols);
int** create_empty_matrix(int rows, int cols);
int read_matrix(char *matrixName, int **matrix, int rows, int cols);
void multiply_matrix(int **matrix1, int **matrix2, int **matrixProduct, int rows1, int cols1, int cols2);
void print_matrix(int **matrix, int rows, int cols);
void free_memory(int **matrix, int rows);

#endif