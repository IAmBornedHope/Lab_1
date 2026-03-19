#pragma once
#include "double.h"
#include "integer.h"
#include "define.h"
#include "matrix_errors.h"


/**
 * @brief Структура матрицы
 * 
 */
typedef struct {
    u_int size;
    void* data;
    TypeInfo* info;
} Matrix;

/**
 * @brief Функция для создания матрицы
 * 
 * @param matrix_size Размер матрицы
 * @param info Тип матрицы (целочисленная/вещественная)
 * @param error Статус ошибки
 * @return Matrix* 
 */
Matrix* create_matrix(u_int matrix_size, TypeInfo* info, MatrixErrors* error);

/**
 * @brief Очистка памяти, выделенной под матрицу и ее содержимое
 * 
 * @param matrix
 */
void free_matrix(Matrix* matrix);

/**
 * @brief Создание копии матрицы
 * 
 * @param source Копируемая матрица
 * @param error Статус ошибки
 * @return Matrix*
 */
Matrix* copy_matrix(Matrix* source, MatrixErrors* error);

/**
 * @brief Установка элемента на определенное значение
 * 
 * @param matrix Указатель на матрицу
 * @param row Номер строки элемента
 * @param col Номер столбца элемента
 * @param value Значение, которое должен принять элемент
 * @param error Статус ошибки
 */
void set_elem(Matrix* matrix, u_int row, u_int col, void* value, MatrixErrors* error);

/**
 * @brief Получение указателя на элемент матрицы
 * 
 * @param matrix Указатель на матрицу
 * @param row Номер строки элемента
 * @param col Номер столбца элемента
 * @return void* 
 */
void* get_elem(Matrix* matrix, u_int row, u_int col);

/**
 * @brief Получения значения элемента матрицы
 * 
 * @param matrix Указатель на матрицу
 * @param row Номер строки элемента
 * @param col Номер столбца элемента
 * @param out_value Указатель на переменную для записи значения
 * @param error Статус ошибки
 */
void get_value(Matrix* matrix, u_int row, u_int col, void* out_value, MatrixErrors* error);

/**
 * @brief Сложение двух квадратных матриц
 * 
 * @param matrix1 Указатель на первую матрицу
 * @param matrix2 Указатель на вторую матрицу
 * @param result Указатель на результирующую матрицу
 * @param error Статус ошибки
 */
void matrix_add(Matrix* matrix1, Matrix* matrix2, Matrix* result, MatrixErrors* error);

/**
 * @brief Умножение двух квадратных матриц
 * 
 * @param matrix1 Указатель на первую матрицу
 * @param matrix2 Указатель на вторую матрицу
 * @param result Указатель на результирующую матрицу
 * @param error Статус ошибки
 */
void matrix_multiply(Matrix* matrix1, Matrix* matrix2, Matrix* result, MatrixErrors* error);

/**
 * @brief Умножение матрицы на скаляр
 * 
 * @param matrix Указатель на матрицу
 * @param scalar Указатель на скаляр
 * @param result Указатель на результирующую матрицу
 * @param error Статус ошибки
 */
void matrix_on_scalar(Matrix* matrix, void* scalar, Matrix* result, MatrixErrors* error);

/**
 * @brief Прибавление к строке линейной комбинации других строк
 * 
 * @param matrix Указатель на матрицу
 * @param row_index Номер целевой строки
 * @param alphas Массив индексов для остальных строк
 * @param error Статус ошибки
 * @return Matrix* 
 */
Matrix* add_linear_combination(Matrix* matrix, u_int row_index, void* alphas, MatrixErrors* error);
