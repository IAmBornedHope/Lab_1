#include "matrix.h"
#include "errors.h"
#include "define.h"

Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* operation_result) {
    // if (matrix_size <= 0) {
    //     *operation_result = WRONG_MATRIX_SIZE;
    //     return NULL;
    // }
    Matrix* mx = (Matrix*)malloc(sizeof(Matrix));
    if (!mx) {
        *operation_result = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }


    mx->size = matrix_size;
    mx->info = info;
    mx->data = malloc(matrix_size * matrix_size * info->size);

    if (!mx->data) {
        *operation_result = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    for (u_int i = 0; i < matrix_size; ++i) {
        for (u_int j = 0; j < matrix_size; ++j) {
            mx->info->init_zero(get_elem(mx, i, j));
        }
    }
    
    *operation_result = MATRIX_OPERATION_OK;
    return mx;

}

void* get_elem(const Matrix* mx, u_int row, u_int col) {

    char* base = (char*)mx->data;
    u_int offset = (row * mx->size + col) * mx->info->size;
    return base + offset;
}

MatrixErrors set_elem(Matrix* mx, u_int i, u_int j, void* value) {
    // Проверку сюда
    memcpy(get_elem(mx, i, j), value, mx->info->size);
    return MATRIX_OPERATION_OK;

}





void free_matrix(Matrix* mx) {
    free(mx->data);
    free(mx);
}

    
MatrixErrors print_matrix(Matrix* mx) {
    if (mx == NULL) {
        return MATRIX_NOT_DEFINED;
    }
    if (mx->info->print == NULL) {
        return OPERATION_NOT_DEFINED;
    }
    u_int n = mx->size;

    puts("Matrix:");
    for (u_int i = 0; i < n; ++i) {
        printf("[ ");
        for (u_int j = 0; j < n; ++j) {
            mx->info->print(get_elem(mx, i, j));
            printf(" ");
        }
    puts("]");
        
        
    }
    return MATRIX_OPERATION_OK;
}

MatrixErrors matrix_add(Matrix* mx1, Matrix* mx2, Matrix* result) {
    // проверку ошибок
    u_int n = mx1->size;
    for (u_int i = 0; i < n; ++i) {
        for (u_int j = 0; j < n; ++ j) {
            mx1->info->add(get_elem(mx1, i, j), get_elem(mx2, i, j), get_elem(result, i, j));
        }
    }
    return MATRIX_OPERATION_OK;
}