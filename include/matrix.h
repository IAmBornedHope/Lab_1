#pragma once

#include "define.h"
#include "TypeInfo.h"
#include "errors.h"
#include "error.h"

typedef struct {
    u_int size;
    void* data;
    TypeInfo* info;
} Matrix;


Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* operation_result);
void free_matrix(Matrix* mx);

void reset_matrix(const Matrix* matrix, MatrixErrors* error);
Matrix* copy_matrix(Matrix* source, MatrixErrors* error);
void set_elem(Matrix* matrix, u_int row, u_int col, void* value, MatrixErrors* error);
void* get_elem(const Matrix* mx, u_int row, u_int col);

void print_matrix(const Matrix* matrix, MatrixErrors* error);
void matrix_add(Matrix* mx1, Matrix* mx2, Matrix* result, MatrixErrors* error);
void matrix_multiply(Matrix* mx1, Matrix* mx2, Matrix* result, MatrixErrors* error);
void matrix_on_scalar(Matrix* matrix, const void* scalar, Matrix* result, MatrixErrors* error);
Matrix* add_linear_combination(Matrix* matrix, int row_index, void* alphas, MatrixErrors* error);
