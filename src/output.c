#include "output.h"
#include "matrix.h"

void print_error(MatrixErrors error) {
    switch (error) {
        case MATRIX_OPERATION_OK:
            puts("Ошибок нет");
            break;
        case MEMORY_ALLOCATION_FAILED:
            puts("Не удалось выделить память");
            break;
        case MATRIX_NOT_DEFINED:
            puts("Неизвестная матрица");
            break;
        case OPERATION_NOT_DEFINED:
            puts("Операция не определена");
            break;
        case WRONG_MATRIX_SIZE:
            puts("Некорректный размер матрицы");
            break;
        case INDEX_OUT_OF_MATRIX:
            puts("Индекс за пределами матрицы");
            break;
        case INCOMPATIBLE_MATRIX_TYPES:
            puts("Типы матриц не совпадают");
            break;
        case DIFFERENT_MATRIX_SIZES:
            puts("Размеры матриц не совпадают");
            break;
        default:
            puts("Что-то пошло не так");
    }
}

void print_matrix(Matrix* matrix) {
    u_int size = matrix->size;
    puts("Матрица:");
    for (u_int row = 0; row < size; ++row) {
        printf("[ ");
        for (u_int col = 0; col < size; ++col) {
            matrix->info->print(get_elem(matrix, row, col));
            printf(" ");
        }
    puts("  ]");
        
    }
}