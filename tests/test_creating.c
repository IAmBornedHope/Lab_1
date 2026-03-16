#include "testing.h"
#include "matrix.h"

TEST(test_int_matrix_creating){
    puts("ТЕСТ 1.1");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы с корректными данными.");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_minimal_matrix_size){
    puts("ТЕСТ 1.2");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы минимального размера (1х1)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(1, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix->size == 1);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_max_matrix_size) {
    puts("ТЕСТ 1.3");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы максимального размера (100х100)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(100, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix->size == 100);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_zero_matrix_size) {
    puts("ТЕСТ 1.4");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы нулевого размера (0х0)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(0, INT_MATRIX, &result);
    assert(matrix == NULL);   
    assert(expect == result);
}

TEST(test_int_too_big_matrix_size) {
    puts("ТЕСТ 1.5");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы слишком большого размера (>100)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(101, INT_MATRIX, &result);
    assert(matrix == NULL);
    assert(expect == result);
}

TEST(test_int_negative_matrix_size) {
    puts("ТЕСТ 1.6");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы отрицательного размера");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(-1, INT_MATRIX, &result);
    assert(matrix == NULL);
    assert(expect == result);
}

TEST(test_int_null_matrix_type) {
    puts("ТЕСТ 1.7");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы с типом NULL");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(4, NULL, &result);
    assert(matrix == NULL);
    assert(expect == result);
}

TEST(test_int_null_error_pointer) {
    puts("ТЕСТ 1.8");
    puts("Тестируемая функция - create_matrix. Создание целочисленной матрицы без указателя на ошибку");
    Matrix* matrix = create_matrix(4, INT_MATRIX, NULL);
    assert(matrix == NULL);
}

TEST(test_double_matrix_creating) {
    puts("ТЕСТ 1.9");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы с корректными данными.");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_minimal_matrix_size) {
    puts("ТЕСТ 1.10");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы минимального размера (1х1)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(1, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix->size == 1);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_max_matrix_size) {
    puts("ТЕСТ 1.11");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы максимального размера (100х100)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    Matrix* matrix = create_matrix(100, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix->size == 100);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_zero_matrix_size) {
    puts("ТЕСТ 1.12");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы нулевого размера (0х0)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(0, DOUBLE_MATRIX, &result);
    assert(matrix == NULL);   
    assert(expect == result);
}

TEST(test_double_too_big_matrix_size) {
    puts("ТЕСТ 1.13");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы слишком большого размера (>100)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(101, DOUBLE_MATRIX, &result);
    assert(matrix == NULL);
    assert(expect == result);
}

TEST(test_double_negative_matrix_size) {
    puts("ТЕСТ 1.14");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы отрицательного размера");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = WRONG_MATRIX_SIZE;
    Matrix* matrix = create_matrix(-1, DOUBLE_MATRIX, &result);
    assert(matrix == NULL);
    assert(expect == result);
}

TEST(test_double_null_error_pointer) {
    puts("ТЕСТ 1.15");
    puts("Тестируемая функция - create_matrix. Создание вещественной матрицы без указателя на ошибку");
    Matrix* matrix = create_matrix(4, DOUBLE_MATRIX, NULL);
    assert(matrix == NULL);
}