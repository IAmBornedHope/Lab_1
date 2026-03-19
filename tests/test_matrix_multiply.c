#include <math.h>
#include <float.h>
#include "testing.h"
#include "matrix.h"

TEST(test_int_matrix_multiply) {
    puts("ТЕСТ 4.1");
    puts("Тестируемая функция - matrix_multiply. Умножение целочисленных матриц в общем случае (элементы больше и меньше нуля, равны нулю)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int out_value;

    Matrix* matrix_1 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);


    set_elem(matrix_2, 0, 0, &val_4, &result);
    set_elem(matrix_2, 0, 1, &val_3, &result);
    set_elem(matrix_2, 1, 0, &val_2, &result);
    set_elem(matrix_2, 1, 1, &val_1, &result);


    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 2);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == -8);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == -4);
    
    assert(expect == result);
    
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_double_matrix_multiply) {
    puts("ТЕСТ 4.2");
    puts("Тестируемая функция - matrix_multiply. Умножение вещественных матриц в общем случае (элементы больше и меньше нуля, равны нулю)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double out_value;

    Matrix* matrix_1 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);


    set_elem(matrix_2, 0, 0, &val_4, &result);
    set_elem(matrix_2, 0, 1, &val_3, &result);
    set_elem(matrix_2, 1, 0, &val_2, &result);
    set_elem(matrix_2, 1, 1, &val_1, &result);


    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 2 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - (-8) < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - (-4) < DBL_EPSILON);
    
    assert(expect == result);
    
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_int_zero_matrix_multiply) {
    puts("ТЕСТ 4.3");
    puts("Тестируемая функция - matrix_multiply. Умножение целочисленной матрицы на нулевую матрицу");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int out_value;
    Matrix* matrix_1 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == 0);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_double_zero_matrix_multiply) {
    puts("ТЕСТ 4.4");
    puts("Тестируемая функция - matrix_multiply. Умножение вещественной матрицы на нулевую матрицу");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double out_value;
    Matrix* matrix_1 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - 0 < DBL_EPSILON);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_int_identity_matrix_multiply) {
    puts("ТЕСТ 4.5");
    puts("Тестируемая функция - matrix_multiply. Умножение целочисленной матрицы на единичную матрицу");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    int val_1 = 1, val_2 = 2, val_3 = 0, val_4 = -4;
    int one = 1;
    int out_value;
    Matrix* matrix_1 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, INT_MATRIX, &result);

    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);

    set_elem(matrix_2, 0, 0, &one, &result);
    set_elem(matrix_2, 1, 1, &one, &result);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value == 1);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value == 2);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value == 0);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value == -4);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_double_identity_matrix_multiply) {
    puts("ТЕСТ 4.6");
    puts("Тестируемая функция - matrix_multiply. Умножение вещественной матрицы на единичную матрицу");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_OPERATION_OK;
    double val_1 = 1.0, val_2 = 2.0, val_3 = 0.0, val_4 = -4.0;
    double one = 1.0;
    double out_value;
    Matrix* matrix_1 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(2, DOUBLE_MATRIX, &result);

    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    set_elem(matrix_1, 0, 0, &val_1, &result);
    set_elem(matrix_1, 0, 1, &val_2, &result);
    set_elem(matrix_1, 1, 0, &val_3, &result);
    set_elem(matrix_1, 1, 1, &val_4, &result);

    set_elem(matrix_2, 0, 0, &one, &result);
    set_elem(matrix_2, 1, 1, &one, &result);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);

    get_value(matrix_result, 0, 0, &out_value, &result);
    assert(out_value - 1.0 < DBL_EPSILON);
    get_value(matrix_result, 0, 1, &out_value, &result);
    assert(out_value - 2.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 0, &out_value, &result);
    assert(out_value - 0.0 < DBL_EPSILON);
    get_value(matrix_result, 1, 1, &out_value, &result);
    assert(out_value - (-4) < DBL_EPSILON);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_different_types_multiply) {
    puts("ТЕСТ 4.7");
    puts("Тестируемая функция - matrix_multiply. Умножение матриц разных типов");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INCOMPATIBLE_MATRIX_TYPES;
    Matrix* matrix_1 = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_int_different_size_multiply) {
    puts("ТЕСТ 4.8");
    puts("Тестируемая функция - matrix_multiply. Умножение целочисленных матриц разного размера");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = DIFFERENT_MATRIX_SIZES;
    Matrix* matrix_1 = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, INT_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);

    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_double_different_size_multiply) {
    puts("ТЕСТ 4.9");
    puts("Тестируемая функция - matrix_multiply. Умножение вещественных матриц разного размера");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = DIFFERENT_MATRIX_SIZES;
    Matrix* matrix_1 = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(2, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);

    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);
    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_mult_int_incompatible_result_type) {
    puts("ТЕСТ 4.10");
    puts("Тестируемая функция - matrix_multiply. Две целочисленных матрицы корректны, результирующая - вещественная");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INCOMPATIBLE_MATRIX_TYPES;
    Matrix* matrix_1 = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);
    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_mult_double_incompatible_result_type) {
    puts("ТЕСТ 4.11");
    puts("Тестируемая функция - matrix_multiply. Две вещественных матрицы корректны, результирующая - целочисленная");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = INCOMPATIBLE_MATRIX_TYPES;
    Matrix* matrix_1 = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, INT_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    assert(matrix_result != NULL);
    matrix_multiply(matrix_1, matrix_2, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(matrix_result);
}

TEST(test_mult_first_matrix_not_defined) {
    puts("ТЕСТ 4.12");
    puts("Тестируемая функция - matrix_multiply. Первый множитель не определен (NULL)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    Matrix* matrix = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    matrix_multiply(NULL, matrix, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_mult_second_matrix_not_defined) {
    puts("ТЕСТ 4.13");
    puts("Тестируемая функция - matrix_multiply. Второй множитель не определен (NULL)");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    Matrix* matrix = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_result = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix != NULL);
    assert(matrix_result != NULL);
    matrix_multiply(matrix, NULL, matrix_result, &result);
    assert(expect == result);

    free_matrix(matrix);
    free_matrix(matrix_result);
}

TEST(test_mult_int_result_matrix_not_defined) {
    puts("ТЕСТ 4.14");
    puts("Тестируемая функция - matrix_multiply. Умножение целочисленных матриц, результирующая матрица не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    Matrix* matrix_1 = create_matrix(3, INT_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(3, INT_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    matrix_multiply(matrix_1, matrix_2, NULL, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
}

TEST(test_mult_double_result_matrix_not_defined) {
    puts("ТЕСТ 4.15");
    puts("Тестируемая функция - matrix_multiply. Умножение вещественных матриц, результирующая матрица не определена");
    MatrixErrors result = MATRIX_OPERATION_OK;
    MatrixErrors expect = MATRIX_NOT_DEFINED;
    Matrix* matrix_1 = create_matrix(3, DOUBLE_MATRIX, &result);
    Matrix* matrix_2 = create_matrix(3, DOUBLE_MATRIX, &result);
    assert(matrix_1 != NULL);
    assert(matrix_2 != NULL);
    matrix_multiply(matrix_1, matrix_2, NULL, &result);
    assert(expect == result);

    free_matrix(matrix_1);
    free_matrix(matrix_2);
}

