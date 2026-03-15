#pragma once

/**
 * @brief Структура кодов ошибок
 * 
 */
typedef enum {
    MATRIX_OPERATION_OK = 0,
    MEMORY_ALLOCATION_FAILED = 100,
    MATRIX_NOT_DEFINED = 200,
    OPERATION_NOT_DEFINED = 201,
    WRONG_MATRIX_SIZE = 202,
    INDEX_OUT_OF_MATRIX = 203,
    ZERO_POINTER = 204,
    INCOMPATIBLE_MATRIX_TYPES = 300,
    DIFFERENT_MATRIX_SIZES = 301,
} MatrixErrors;

void print_error(MatrixErrors error);

