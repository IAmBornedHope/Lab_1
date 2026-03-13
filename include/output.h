#pragma once
#include "errors.h"
#include "matrix.h"
/**
 * @brief Функция для вывода статуса ошибки
 * 
 * @param error
 */
void print_error(MatrixErrors error);
/**
 * @brief Функция для вывода матрицы
 * 
 * @param matrix Указатель на матрицу
 */
void print_matrix(Matrix* matrix);