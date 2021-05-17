#ifndef MATRIX_H
#define MATRIX_H



typedef struct matrix{
  unsigned rows;
  unsigned columns;
  double** data;

}Matrix;

Matrix create_matrix(unsigned rows, unsigned columns);
void free_matrix(Matrix matrix);
void print_matrix(Matrix matrix);


#endif
