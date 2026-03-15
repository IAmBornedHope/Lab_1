#include "testing.h"
#include "matrix.h"

TEST(test_int_index_too_big) {
    puts("ТЕСТ 2.1");
    puts("Тестируемая функция - set_elem. Попытка изменить значение по индексу больше размеров целочисленной матрицы");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    int value = 100;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 5, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 5, &value, &result);
    assert(expect == result);

    set_elem(matrix, 5, 5, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_set_negative_index) {
    puts("ТЕСТ 2.2");
    puts("Тестируемая функция - set_elem. Попытка изменить значение по отрицательному индексу в целочисленной матрице");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    int value = 100;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, -1, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, -1, &value, &result);
    assert(expect == result);

    set_elem(matrix, -1, -1, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_set_max_index) {
    puts("ТЕСТ 2.3");
    puts("Тестируемая функция - set_elem. Изменение элементов целочисленной матрицы с максимальным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int value = 100;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 4, 1, &value, &result);
    assert(expect == result);

    set_elem(matrix, 1, 4, &value, &result);
    assert(expect == result);

    set_elem(matrix, 4, 4, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_set_min_index) {
    puts("ТЕСТ 2.4");
    puts("Тестируемая функция - set_elem. Изменение элементов целочисленной матрицы с минимальным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int value = 100;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 1, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 1, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 0, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_setter) {
    puts("ТЕСТ 2.5");
    puts("Тестируемая функция - set_elem. Изменение элементов целочисленной матрицы с произвольным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int value = 100;
    Matrix* matrix = create_matrix(5, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 2, 3, &value, &result);
    assert(expect == result);

    set_elem(matrix, 3, 2, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 3, &value, &result);
    assert(expect == result);

    set_elem(matrix, 2, 2, &value, &result);
    assert(expect == result);
    
    set_elem(matrix, 3, 4, &value, &result);
    assert(expect == result);

    set_elem(matrix, 1, 2, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_index_too_big) {
    puts("ТЕСТ 2.6");
    puts("Тестируемая функция - set_elem. Попытка изменить значение по индексу больше размеров вещественной матрицы");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    double value = 100.0;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 5, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 5, &value, &result);
    assert(expect == result);

    set_elem(matrix, 5, 5, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_set_negative_index) {
    puts("ТЕСТ 2.7");
    puts("Тестируемая функция - set_elem. Попытка изменить значение по отрицательному индексу в вещественной матрице");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    double value = 100.0;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, -1, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, -1, &value, &result);
    assert(expect == result);

    set_elem(matrix, -1, -1, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_set_max_index) {
    puts("ТЕСТ 2.8");
    puts("Тестируемая функция - set_elem. Изменение элементов вещественной матрицы с максимальным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double value = 100.0;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 4, 1, &value, &result);
    assert(expect == result);

    set_elem(matrix, 1, 4, &value, &result);
    assert(expect == result);

    set_elem(matrix, 4, 4, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_set_min_index) {
    puts("ТЕСТ 2.9");
    puts("Тестируемая функция - set_elem. Изменение элементов вещественной матрицы с минимальным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double value = 100.0;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 1, 0, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 1, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 0, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_setter) {
    puts("ТЕСТ 2.10");
    puts("Тестируемая функция - set_elem. Изменение элементов вещественной матрицы с произвольным индексом");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double value = 100.0;
    Matrix* matrix = create_matrix(5, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 2, 3, &value, &result);
    assert(expect == result);

    set_elem(matrix, 3, 2, &value, &result);
    assert(expect == result);

    set_elem(matrix, 0, 3, &value, &result);
    assert(expect == result);

    set_elem(matrix, 2, 2, &value, &result);
    assert(expect == result);
    
    set_elem(matrix, 3, 4, &value, &result);
    assert(expect == result);

    set_elem(matrix, 1, 2, &value, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_set_null_matrix) {
    puts("ТЕСТ 2.11");
    puts("Тестируемая функция - set_elem. Попытка изменить значение в NULL матрице");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    int value = 100;
    set_elem(NULL, 0, 0, &value, &result);
    assert(expect == result);
}

TEST(test_int_set_null_value) {
    puts("ТЕСТ 2.12");
    puts("Тестируемая функция - set_elem. Попытка изменить значение на NULL в целочисленной матрице");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(3, INT_MATRIX, &result);
    set_elem(matrix, 0, 0, NULL, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_set_null_value) {
    puts("ТЕСТ 2.13");
    puts("Тестируемая функция - set_elem. Попытка изменить значение на NULL в вещественной матрице");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(3, DOUBLE_MATRIX, &result);
    set_elem(matrix, 0, 0, NULL, &result);
    assert(expect == result);
    free_matrix(matrix);
}

