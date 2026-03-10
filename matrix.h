#pragma once

#include "define.h"
#include "TypeInfo.h"
#include "errors.h"

typedef struct {
    u_int size;
    void* data;
    TypeInfo* info;
} Matrix;

void* get_elem(const Matrix* mx, u_int row, u_int col);
Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* operation_result);
void free_matrix(Matrix* mx);
MatrixErrors print_matrix(Matrix* mx);
MatrixErrors set_elem(Matrix* mx, u_int i, u_int j, void* value);

MatrixErrors matrix_on_scalar(Matrix* matrix, const void* scalar, Matrix* result);
MatrixErrors reset_matrix(const Matrix* mx);
MatrixErrors matrix_add(Matrix* a, Matrix* b, Matrix* result);
MatrixErrors matrix_multiply(Matrix* a, Matrix* b, Matrix* result);
Matrix* scalar_multiply(Matrix* a, void* scalar);


