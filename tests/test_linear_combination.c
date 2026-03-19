#include "testing.h"
#include "matrix.h"

TEST(test_int_linear_combination_target_start) {
    puts("ТЕСТ 6.1");
    puts("Тестируемая функция - add_linear_combination. Целочисленная матрица, целевой строкой является первая");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int out_value;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int alphas[2] = {0, 10};
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    Matrix* matrix_result = add_linear_combination(matrix, 0, &alphas, &result);
    assert(matrix_result != NULL);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 1);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == -38);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == -4);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_int_linear_combination_target_end) {
    puts("ТЕСТ 6.2");
    puts("Тестируемая функция - add_linear_combination. Целочисленная матрица, целевой строкой является последняя");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int out_value;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int alphas[2] = {5, 10};
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    Matrix* matrix_result = add_linear_combination(matrix, 1, &alphas, &result);
    assert(matrix_result != NULL);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 1);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 2);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 5);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 6);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_double_linear_combination_target_start) {
    puts("ТЕСТ 6.3");
    puts("Тестируемая функция - add_linear_combination. Вещественная матрица, целевой строкой является первая");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double out_value;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double alphas[2] = {5.0, 10.0};
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    Matrix* matrix_result = add_linear_combination(matrix, 0, &alphas, &result);
    assert(matrix_result != NULL);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 1.0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == -38.0);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0.0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == -4.0);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_double_linear_combination_target_end) {
    puts("ТЕСТ 6.4");
    puts("Тестируемая функция - add_linear_combination. Вещественная матрица, целевой строкой является первая");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double out_value;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double alphas[2] = {5.0, 10.0};
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    Matrix* matrix_result = add_linear_combination(matrix, 1, &alphas, &result);
    assert(matrix_result != NULL);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 1.0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 2.0);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 5.0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 6.0);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_int_linear_too_big_index) {
    puts("ТЕСТ 6.5");
    puts("Тестируемая функция - add_linear_combination. Целочисленная матрица, номер целевой строки больше размеров матрицы");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    int alphas[2] = {5, 10};
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, 2, &alphas, &result);
    assert(matrix_result == NULL);
    assert(expect == result);

    free_matrix(matrix);
}

TEST(test_int_linear_negative_index) {
    puts("ТЕСТ 6.6");
    puts("Тестируемая функция - add_linear_combination. Целочисленная матрица, номер целевой строки меньше нуля");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    int alphas[2] = {5, 10};
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, -1, &alphas, &result);
    assert(matrix_result == NULL);
    assert(expect == result);

    free_matrix(matrix);
}

TEST(test_double_linear_too_big_index) {
    puts("ТЕСТ 6.7");
    puts("Тестируемая функция - add_linear_combination. Вещественная матрица, номер целевой строки больше размеров матрицы");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    double alphas[2] = {5.0, 10.0};
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, 2, &alphas, &result);
    assert(matrix_result == NULL);
    assert(expect == result);

    free_matrix(matrix);
}

TEST(test_double_linear_negative_index) {
    puts("ТЕСТ 6.8");
    puts("Тестируемая функция - add_linear_combination. Вещественная матрица, номер целевой строки меньше нуля");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INDEX_OUT_OF_MATRIX;
    double alphas[2] = {5, 10};
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, -1, &alphas, &result);
    assert(matrix_result == NULL);
    assert(expect == result);

    free_matrix(matrix);
}

TEST(test_linear_combination_null_target_matrix) {
    puts("ТЕСТ 6.9");
    puts("Тестируемая функция - add_linear_combination. Исходная матрица не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    int alphas[2] = {5, 10};
    Matrix* matrix_result = add_linear_combination(NULL, 0, &alphas, &result);
    assert(matrix_result == NULL);
    assert(expect == result);
}

TEST(test_int_linear_combination_null_indices) {
    puts("ТЕСТ 6.10");
    puts("Тестируемая функция - add_linear_combination. Целочисленная матрица, массив индексов не определен");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, 0, NULL, &result);
    assert(matrix_result == NULL);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_double_linear_combination_null_indices) {
    puts("ТЕСТ 6.11");
    puts("Тестируемая функция - add_linear_combination. Вещественная матрица, массив индексов не определен");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    Matrix* matrix_result = add_linear_combination(matrix, 0, NULL, &result);
    assert(matrix_result == NULL);
    assert(expect == result);
    free_matrix(matrix);
}
