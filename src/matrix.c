#include "matrix.h"
#include "errors.h"
#include "define.h"

Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* error) {

    if (matrix_size >= MAX_MATRIX_SIZE) {
        *error = WRONG_MATRIX_SIZE;
        return NULL;
    }
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (!matrix) {
        if (error) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    matrix->size = matrix_size;
    matrix->info = info;
    matrix->data = malloc(matrix_size * matrix_size * info->size);

    if (!matrix->data) {
        free(matrix);
        if (error) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    return matrix;

}

void* get_elem(const Matrix* matrix, u_int row, u_int col) {
    
    if (!matrix) return NULL;
    u_int size = matrix->size;
    if (row > size || col > size) return NULL;

    char* base = (char*)matrix->data;
    u_int offset = (row * size + col) * matrix->info->size;
    return base + offset;
}

void reset_matrix(const Matrix* matrix, MatrixErrors* error) {
    if (!matrix) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }
    u_int size = matrix->size;
    for (u_int i = 0; i < size; ++i) {
        for (u_int j = 0; j < size; ++j) {
            matrix->info->init_zero(get_elem(matrix, i, j));
        }
    }
}




void set_elem(Matrix* matrix, u_int row, u_int col, void* value, MatrixErrors* error) {
    if (!matrix) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }
    u_int size = matrix->size;
    if (row >= size || col >= size) {
        if (error) *error = INDEX_OUT_OF_MATRIX;
        return;
    }
    memcpy(get_elem(matrix, row, col), value, matrix->info->size);
}


void free_matrix(Matrix* matrix) {
    if (!matrix || !matrix->data) return;
    free(matrix->data);
    free(matrix);
}

    
void print_matrix(const Matrix* matrix, MatrixErrors* error) {
    if (!matrix) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }

    u_int size = matrix->size;

    puts("Matrix:");
    for (u_int row = 0; row < size; ++row) {
        printf("[ ");
        for (u_int col = 0; col < size; ++col) {
            matrix->info->print(get_elem(matrix, row, col));
            printf(" ");
        }
    puts("]");
        
    }
}

void matrix_add(Matrix* mx1, Matrix* mx2, Matrix* result, MatrixErrors* error) {

    if (!mx1 || !mx2 || !result) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }
    if (mx1->size != mx2->size || mx1->size != result->size) {
        if (error) *error = DIFFERENT_MATRIX_SIZES;
        return;
    }

    if (mx1->info != mx2->info || mx1->info != result->info) {
        if (error) *error = INCOMPATIBLE_MATRIX_TYPES;
        return;
    }

    if (!mx1->info->add) {
        if (error) *error = OPERATION_NOT_DEFINED;
        return;
    }

    u_int size = mx1->size;
    for (u_int row = 0; row < size; ++row) {
        for (u_int col = 0; col < size; ++ col) {
            mx1->info->add(get_elem(mx1, row, col), get_elem(mx2, row, col), get_elem(result, row, col));
        }
    }
}

void matrix_multiply(Matrix* mx1, Matrix* mx2, Matrix* result, MatrixErrors* error) {
    
    if (!mx1 || !mx2 || !result) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }
    if (mx1->size != mx2->size || mx1->size != result->size) {
        if (error) *error = DIFFERENT_MATRIX_SIZES;
        return;
    }

    if (mx1->info != mx2->info || mx1->info != result->info) {
        if (error) *error = INCOMPATIBLE_MATRIX_TYPES;
        return;
    }

    if (!mx1->info->multiply) {
        if (error) *error = OPERATION_NOT_DEFINED;
        return;
    }

    u_int size = mx1->size;
    void* temp = malloc(result->info->size);
    if (!temp) {
        if (error) *error = MEMORY_ALLOCATION_FAILED;
        return;
    }
    for (u_int row = 0; row < size; ++row) {
        for (u_int col = 0; col < size; ++col) {
            void* res_elem = get_elem(result, row, col);
            for (u_int i = 0; i < size; ++i) {
                void* first_elem = get_elem(mx1, row, i);
                void* second_elem = get_elem(mx2, i, col);
                result->info->multiply(first_elem, second_elem, temp);
                result->info->add(res_elem, temp, res_elem);
            }
        }
    }
    free(temp);
}


void matrix_on_scalar(Matrix* matrix, const void* scalar, Matrix* result, MatrixErrors* error) {

    if (!matrix || !result) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return;
    }
    if (!matrix->info->multiply) {
        if (error) *error = OPERATION_NOT_DEFINED;
        return;
    }

    u_int size = matrix->size;
    for (u_int row = 0; row < size; ++row) {
        for (u_int col = 0; col < size; ++col) {
            matrix->info->multiply(get_elem(matrix, row, col), scalar, get_elem(result, row, col));
        }
    }
}

Matrix* copy_matrix(Matrix* source, MatrixErrors* error) {
    if (!source) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return NULL;
    }
    Matrix* copy = create_matrix(source->size, source->info, error);
    if (!copy) {
        if (error) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    memcpy(copy->data, source->data, source->size * source->size * source->info->size);
    return copy;

}

Matrix* add_linear_combination(Matrix* matrix, int row_index, void* alphas, MatrixErrors* error) {
    if (!matrix) {
        if (error) *error = MATRIX_NOT_DEFINED;
        return NULL;
    }

    if (row_index < 0 || row_index >= matrix->size) {
        if (error) *error = INDEX_OUT_OF_MATRIX;
        return NULL;
    }

    if (!matrix->info->add || !matrix->info->multiply) {
        if (error) *error = OPERATION_NOT_DEFINED;
        return NULL;
    }

    Matrix* result = copy_matrix(matrix, error);
    if (!result) return NULL;

    u_int size = matrix->size;
    u_int element_size = matrix->info->size;
    char* array = (char*)alphas;

    for (u_int index = 0; index < size; ++index) {
        if (index == row_index) continue;
        void* beta = array + (index * element_size);

        for (u_int col = 0; col < size; ++col) {
            void* source = get_elem(result, index, col);
            void* target = get_elem(result, row_index, col);

            void* temp = malloc(result->info->size);

            result->info->multiply(source, beta, temp);
            result->info->add(target, temp, target);
        }
    }
    return result;
}

