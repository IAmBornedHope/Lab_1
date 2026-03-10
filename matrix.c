#include "matrix.h"
#include "errors.h"
#include "define.h"

Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* operation_result) {
    if (matrix_size <= 0) {
        *operation_result = WRONG_MATRIX_SIZE;
        return NULL;
    }
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

    // for (u_int i = 0; i < matrix_size; ++i) {
    //     for (u_int j = 0; j < matrix_size; ++j) {
    //         mx->info->init_zero(get_elem(mx, i, j));
    //     }
    // }
    
    *operation_result = MATRIX_OPERATION_OK;
    return mx;

}

MatrixErrors reset_matrix(const Matrix* mx) {
    u_int size = mx->size;
    for (u_int i = 0; i < size; ++i) {
        for (u_int j = 0; j < size; ++j) {
            mx->info->init_zero(get_elem(mx, i, j));
        }
    }
    return MATRIX_OPERATION_OK;
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
    u_int size = mx1->size;
    for (u_int i = 0; i < size; ++i) {
        for (u_int j = 0; j < size; ++ j) {
            mx1->info->add(get_elem(mx1, i, j), get_elem(mx2, i, j), get_elem(result, i, j));
        }
    }
    return MATRIX_OPERATION_OK;
}

MatrixErrors matrix_multiply(Matrix* mx1, Matrix* mx2, Matrix* result) {
    //Ошибки
    u_int size = mx1->size;
    for (u_int row = 0; row < size; ++row) {
        for (u_int col = 0; col < size; ++col) {
            void* res_elem = get_elem(result, row, col);
            for (u_int i = 0; i < size; ++ i) {
                void* first_elem = get_elem(mx1, row, i);
                void* second_elem = get_elem(mx2, i, col);

                char temp[result->info->size];

                result->info->multiply(first_elem, second_elem, temp);
                result->info->add(res_elem, temp, res_elem);



            }
        }
    }
    return MATRIX_OPERATION_OK;
}


MatrixErrors matrix_on_scalar(Matrix* matrix, const void* scalar, Matrix* result) {
    //Ошибки

    u_int size = matrix->size;
    for (u_int row = 0; row < size; ++row) {
        for (u_int col = 0; col < size; ++col) {
            matrix->info->multiply(get_elem(matrix, row, col), scalar, get_elem(result, row, col));
        }
    }
    return MATRIX_OPERATION_OK;
}