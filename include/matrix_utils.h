#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_DIM 1000

int** create_empty_matrix(char *matrixName, int *sizeRows, int *sizeCols);

void read_matrix(int **matrix, int sizeRows, int sizeCols);

void print_matrix(int **matrix, int sizeRows, int sizeCols);

#endif