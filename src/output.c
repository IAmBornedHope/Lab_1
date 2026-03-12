#include "output.h"
#include "matrix.h"

void print_error(MatrixErrors error) {
    switch (error) {
        case MATRIX_OPERATION_OK:
            puts("Работа завершена");
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