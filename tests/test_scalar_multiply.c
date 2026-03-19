#include <math.h>
#include <float.h>
#include "testing.h"
#include "matrix.h"

TEST(test_int_scalar_multiply) {
    puts("ТЕСТ 5.1");
    puts("Тестируемая функция - matrix_on_scalar. Умножение целочисленной матрицы на скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int out_value;
    int scalar;
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    assert(expect == result);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);
    assert(expect == result);
    puts("Положительный скаляр");
    scalar = 7;
    matrix_on_scalar(matrix, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 7);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 14);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == -28);
    assert(expect == result);

    puts("Отрицательный скаляр");
    scalar = -2;

    matrix_on_scalar(matrix_result, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == -14);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == -28);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 56);
    assert(expect == result);

    puts("Умножение на ноль");
    scalar = 0;

    matrix_on_scalar(matrix_result, &scalar, matrix_result, &result);
    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 0);
    assert(expect == result);

    
    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_double_scalar_multiply) {
    puts("ТЕСТ 5.2");
    puts("Тестируемая функция - matrix_on_scalar. Умножение вещественной матрицы на скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double out_value;
    double scalar;
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    assert(expect == result);

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);
    assert(expect == result);
    puts("Положительный скаляр");
    scalar = 7.0;
    matrix_on_scalar(matrix, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 7.0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 14.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - (-28) < DBL_EPSILON);
    assert(expect == result);

    puts("Отрицательный скаляр");
    scalar = -2.0;

    matrix_on_scalar(matrix_result, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - (-14) < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - (-28) < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - 56 < DBL_EPSILON);
    assert(expect == result);

    puts("Умножение на ноль");
    scalar = 0.0;

    matrix_on_scalar(matrix_result, &scalar, matrix_result, &result);
    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    assert(expect == result);

    
    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_null_matrix_on_scalar_1) {
    puts("ТЕСТ 5.3");
    puts("Тестируемая функция - matrix_on_scalar. Умножение NULL матрицы на скаляр, целочисленная матрица результата определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    int scalar = 7;
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix_result != NULL);

    matrix_on_scalar(NULL, &scalar, matrix_result, &result);
    assert(expect == result);
    free_matrix(matrix_result);
}

TEST(test_null_matrix_on_scalar_2) {
    puts("ТЕСТ 5.4");
    puts("Тестируемая функция - matrix_on_scalar. Умножение NULL матрицы на скаляр, вещественная матрица результата определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    double scalar = 7.0;
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix_result != NULL);

    matrix_on_scalar(NULL, &scalar, matrix_result, &result);
    assert(expect == result);
    free_matrix(matrix_result);
}

TEST(test_null_matrix_on_scalar_3) {
    puts("ТЕСТ 5.5");
    puts("Тестируемая функция - matrix_on_scalar. Умножение NULL матрицы на скаляр, матрица результата не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    int scalar = 7;

    matrix_on_scalar(NULL, &scalar, NULL, &result);
    assert(expect == result);
}

TEST(test_null_matrix_on_scalar_4) {
    puts("ТЕСТ 5.6");
    puts("Тестируемая функция - matrix_on_scalar. Умножение целочисленной матрицы на скаляр, матрица результата не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int scalar = 7;
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);
    
    matrix_on_scalar(matrix, &scalar, NULL, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_null_matrix_on_scalar_5) {
    puts("ТЕСТ 5.7");
    puts("Тестируемая функция - matrix_on_scalar. Умножение вещественной матрицы на скаляр, матрица результата не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double scalar = 7.0;
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);
    
    matrix_on_scalar(matrix, &scalar, NULL, &result);
    assert(expect == result);
    free_matrix(matrix);
}

TEST(test_int_matrix_multiply_null_scalar) {
    puts("ТЕСТ 5.8");
    puts("Тестируемая функция - matrix_on_scalar. Умножение целочисленной матрицы на неопределенный скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    matrix_on_scalar(matrix, NULL, matrix_result, &result);
    assert(expect == result);
    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_double_matrix_multiply_null_scalar) {
    puts("ТЕСТ 5.9");
    puts("Тестируемая функция - matrix_on_scalar. Умножение вещественной матрицы на неопределенный скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = ZERO_POINTER;
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    int val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;

    set_elem(matrix, 0, 0, &val_1, &result);
    set_elem(matrix, 0, 1, &val_2, &result);
    set_elem(matrix, 1, 0, &val_3, &result);
    set_elem(matrix, 1, 1, &val_4, &result);

    matrix_on_scalar(matrix, NULL, matrix_result, &result);
    assert(expect == result);
    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_scalar_int_incompatible_result) {
    puts("ТЕСТ 5.10");
    puts("Тестируемая функция - matrix_on_scalar. Умножение целочисленной матрицы на скаляр, результирующая - вещественная");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INCOMPATIBLE_MATRIX_TYPES;
    int scalar = 15;
    Matrix* matrix = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    matrix_on_scalar(matrix, &scalar, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);

}

TEST(test_scalar_double_incompatible_result) {
    puts("ТЕСТ 5.11");
    puts("Тестируемая функция - matrix_on_scalar. Умножение вещественной матрицы на скаляр, результирующая - целочисленная");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INCOMPATIBLE_MATRIX_TYPES;
    double scalar = 15.0;
    Matrix* matrix = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    matrix_on_scalar(matrix, &scalar, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_int_zero_scalar_multiply) {
    puts("ТЕСТ 5.12");
    puts("Тестируемая функция - matrix_on_scalar. Умножение целочисленной матрицы на нулевой скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int scalar = 0;
    int value = 4;
    int out_value;
    Matrix* matrix = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    set_elem(matrix, 0, 0, &value, &result);
    set_elem(matrix, 0, 1, &value, &result);
    set_elem(matrix, 1, 0, &value, &result);
    set_elem(matrix, 1, 1, &value, &result);
    assert(expect == result);

    matrix_on_scalar(matrix, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 0);

    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_double_zero_scalar_multiply) {
    puts("ТЕСТ 5.13");
    puts("Тестируемая функция - matrix_on_scalar. Умножение вещественной матрицы на нулевой скаляр");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double scalar = 0.0;
    double value = 4.0;
    double out_value;
    Matrix* matrix = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    set_elem(matrix, 0, 0, &value, &result);
    set_elem(matrix, 0, 1, &value, &result);
    set_elem(matrix, 1, 0, &value, &result);
    set_elem(matrix, 1, 1, &value, &result);
    assert(expect == result);

    matrix_on_scalar(matrix, &scalar, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);

    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);
}