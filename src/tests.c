#include <assert.h>
#include <math.h>
#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "output.h"


u_int passed = 0;
u_int failed = 0;


void run_test(const char* name, void (*func)()) {
    func();
    printf("[УСПЕШНО]  Тест: %s\n", name);
    passed++;
}

void create_min_size_matrix() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int matrix_size = 1;
    Matrix* matrix = create_matrix(matrix_size, info, &error);
    assert(matrix != NULL);
    assert(matrix->size == 1);
    assert(error == MATRIX_OPERATION_OK);

    free_matrix(matrix);
}

void create_zero_size_matrix() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int matrix_size = 0;
    Matrix* matrix = create_matrix(matrix_size, info, &error);
    assert(error == WRONG_MATRIX_SIZE);
    free_matrix(matrix);
}

void create_negative_size_matrix() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int matrix_size = -1;
    Matrix* matrix = create_matrix(matrix_size, info, &error);
    assert(error == WRONG_MATRIX_SIZE);
    free_matrix(matrix);
}

void create_too_big_matrix() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int matrix_size = 10001;
    Matrix* matrix = create_matrix(matrix_size, info, &error);
    assert(error == WRONG_MATRIX_SIZE);
    free_matrix(matrix);

}

void test_out_matrix_size_upper() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int size = 3;
    Matrix* matrix = create_matrix(size, info, &error);
    int value = 1;

    set_elem(matrix, size, 0, &value, &error);
    assert(error == INDEX_OUT_OF_MATRIX);

    set_elem(matrix, 0, size, &value, &error);
    assert(error == INDEX_OUT_OF_MATRIX);

    free_matrix(matrix);
}

void test_out_matrix_negative_index() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int size = 3;
    Matrix* matrix = create_matrix(size, info, &error);
    int value = 1;

    set_elem(matrix, -1, 0, &value, &error);
    assert(error == INDEX_OUT_OF_MATRIX);

    set_elem(matrix, 0, -1, &value, &error);
    assert(error == INDEX_OUT_OF_MATRIX);

    free_matrix(matrix);

}
void set_first_last_element() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int size = 3;
    Matrix* matrix = create_matrix(size, info, &error);
    int first_value = 10, end_value = 100;
    set_elem(matrix, 0, 0, &first_value, &error);
    assert(error == MATRIX_OPERATION_OK);
    set_elem(matrix, size-1, size-1, &end_value, &error);
    assert(error == MATRIX_OPERATION_OK);
    free_matrix(matrix);
}

void incompatible_matrix_types_addition() {
    TypeInfo* info_1 = get_int_typeinfo();
    TypeInfo* info_2 = get_double_typeinfo();
    MatrixErrors error;
    u_int size = 3;
    Matrix* matrix_1 = create_matrix(size, info_1, &error);
    Matrix* matrix_2 = create_matrix(size, info_2, &error);
    Matrix* result = create_matrix(size, info_1, &error);
    matrix_add(matrix_1, matrix_2, result, &error);
    assert(error == INCOMPATIBLE_MATRIX_TYPES);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void incompatible_matrix_types_multiply() {
    TypeInfo* info_1 = get_int_typeinfo();
    TypeInfo* info_2 = get_double_typeinfo();
    MatrixErrors error;
    u_int size = 3;
    Matrix* matrix_1 = create_matrix(size, info_1, &error);
    Matrix* matrix_2 = create_matrix(size, info_2, &error);
    Matrix* result = create_matrix(size, info_1, &error);
    matrix_multiply(matrix_1, matrix_2, result, &error);
    assert(error == INCOMPATIBLE_MATRIX_TYPES);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void different_matrix_sizes_add() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int size_1 = 3;
    u_int size_2 = 4;
    Matrix* matrix_1 = create_matrix(size_1, info, &error);
    Matrix* matrix_2 = create_matrix(size_2, info, &error);
    Matrix* result = create_matrix(size_1, info, &error);
    matrix_add(matrix_1, matrix_2, result, &error);
    assert(error == DIFFERENT_MATRIX_SIZES);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);

}

void different_matrix_sizes_multiply() {
    TypeInfo* info = get_int_typeinfo();
    MatrixErrors error;
    u_int size_1 = 3;
    u_int size_2 = 4;
    Matrix* matrix_1 = create_matrix(size_1, info, &error);
    Matrix* matrix_2 = create_matrix(size_2, info, &error);
    Matrix* result = create_matrix(size_1, info, &error);
    matrix_multiply(matrix_1, matrix_2, result, &error);
    assert(error == DIFFERENT_MATRIX_SIZES);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void matrix_int_addition() {
   TypeInfo* info = get_int_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   int value = 3;
   int out_value = 0;
   Matrix* matrix_1 = create_matrix(size, info, &error);
   Matrix* matrix_2 = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);

   set_elem(matrix_1, 0, 0, &value, &error);
   set_elem(matrix_1, 0, 1, &value, &error);
   set_elem(matrix_1, 1, 0, &value, &error);
   set_elem(matrix_1, 1, 1, &value, &error);
   set_elem(matrix_2, 0, 0, &value, &error);
   set_elem(matrix_2, 0, 1, &value, &error);
   set_elem(matrix_2, 1, 0, &value, &error);
   set_elem(matrix_2, 1, 1, &value, &error);
   matrix_multiply(matrix_1, matrix_2, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 18);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 18);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 18);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 18);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void matrix_double_addition() {
   TypeInfo* info = get_double_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   double value = 3.0;
   double out_value = 0.0;
   Matrix* matrix_1 = create_matrix(size, info, &error);
   Matrix* matrix_2 = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);

   set_elem(matrix_1, 0, 0, &value, &error);
   set_elem(matrix_1, 0, 1, &value, &error);
   set_elem(matrix_1, 1, 0, &value, &error);
   set_elem(matrix_1, 1, 1, &value, &error);
   set_elem(matrix_2, 0, 0, &value, &error);
   set_elem(matrix_2, 0, 1, &value, &error);
   set_elem(matrix_2, 1, 0, &value, &error);
   set_elem(matrix_2, 1, 1, &value, &error);
   matrix_multiply(matrix_1, matrix_2, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 18.0);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 18.0);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 18.0);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 18.0);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void matrix_int_multiply() {
   TypeInfo* info = get_int_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   int value = 3;
   int out_value = 0;
   Matrix* matrix_1 = create_matrix(size, info, &error);
   Matrix* matrix_2 = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);

   set_elem(matrix_1, 0, 0, &value, &error);
   set_elem(matrix_1, 0, 1, &value, &error);
   set_elem(matrix_1, 1, 0, &value, &error);
   set_elem(matrix_1, 1, 1, &value, &error);
   set_elem(matrix_2, 0, 0, &value, &error);
   set_elem(matrix_2, 0, 1, &value, &error);
   set_elem(matrix_2, 1, 0, &value, &error);
   set_elem(matrix_2, 1, 1, &value, &error);
   matrix_add(matrix_1, matrix_2, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 6);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void matrix_double_multiply() {
   TypeInfo* info = get_double_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   double value = 3.0;
   double out_value = 0.0;
   Matrix* matrix_1 = create_matrix(size, info, &error);
   Matrix* matrix_2 = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);

   set_elem(matrix_1, 0, 0, &value, &error);
   set_elem(matrix_1, 0, 1, &value, &error);
   set_elem(matrix_1, 1, 0, &value, &error);
   set_elem(matrix_1, 1, 1, &value, &error);
   set_elem(matrix_2, 0, 0, &value, &error);
   set_elem(matrix_2, 0, 1, &value, &error);
   set_elem(matrix_2, 1, 0, &value, &error);
   set_elem(matrix_2, 1, 1, &value, &error);
   matrix_add(matrix_1, matrix_2, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 6);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 6);
    free_matrix(matrix_1);
    free_matrix(matrix_2);
    free_matrix(result);
}

void int_scalar_multiply() {
   TypeInfo* info = get_int_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   int value = 3;
   int scalar = 5;
   int out_value = 0;
   Matrix* matrix = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);
   set_elem(matrix, 0, 0, &value, &error);
   set_elem(matrix, 0, 1, &value, &error);
   set_elem(matrix, 1, 0, &value, &error);
   set_elem(matrix, 1, 1, &value, &error);
   matrix_on_scalar(matrix, &scalar, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 15);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 15);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 15);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 15);
    free_matrix(matrix);
    free_matrix(result);
}

void double_scalar_multiply() {
   TypeInfo* info = get_double_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   double value = 3.0;
   double scalar = 5.0;
   double out_value = 0.0;
   Matrix* matrix = create_matrix(size, info, &error);
   Matrix* result = create_matrix(size, info, &error);
   set_elem(matrix, 0, 0, &value, &error);
   set_elem(matrix, 0, 1, &value, &error);
   set_elem(matrix, 1, 0, &value, &error);
   set_elem(matrix, 1, 1, &value, &error);
   matrix_on_scalar(matrix, &scalar, result, &error);
   assert(error == MATRIX_OPERATION_OK);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 15.0);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 15.0);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == 15.0);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == 15.0);
    free_matrix(matrix);
    free_matrix(result);
}

void int_linear_combination() {
   TypeInfo* info = get_int_typeinfo();
   MatrixErrors error;
   u_int size = 3;
   int value = 3;
   int alphas[3] = {0, 10, -5}; // Целевая строка будет пропущена
   int out_value = 0;
   Matrix* matrix = create_matrix(size, info, &error);
   set_elem(matrix, 0, 0, &value, &error);
   set_elem(matrix, 0, 1, &value, &error);
   set_elem(matrix, 0, 2, &value, &error);
   set_elem(matrix, 1, 0, &value, &error);
   set_elem(matrix, 1, 1, &value, &error);
   set_elem(matrix, 1, 2, &value, &error);
   set_elem(matrix, 2, 0, &value, &error);
   set_elem(matrix, 2, 1, &value, &error);
   set_elem(matrix, 2, 2, &value, &error);
   Matrix* result = add_linear_combination(matrix, 1, alphas, &error);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 3);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 3);
   get_value(result, 0, 2, &out_value, &error);
   assert(out_value == 3);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == -12);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == -12);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == -12);
   get_value(result, 2, 0, &out_value, &error);
   assert(out_value == 3);
   get_value(result, 2, 1, &out_value, &error);
   assert(out_value == 3);
   get_value(result, 2, 2, &out_value, &error);
   assert(out_value == 3);
   free(matrix);
   free(result);
}

void double_linear_combination() {
   TypeInfo* info = get_double_typeinfo();
   MatrixErrors error;
   u_int size = 3;
   double value = 3;
   double alphas[3] = {0.0, 10.0, -5.0}; // Целевая строка будет пропущена
   double out_value = 0;
   Matrix* matrix = create_matrix(size, info, &error);
   set_elem(matrix, 0, 0, &value, &error);
   set_elem(matrix, 0, 1, &value, &error);
   set_elem(matrix, 0, 2, &value, &error);
   set_elem(matrix, 1, 0, &value, &error);
   set_elem(matrix, 1, 1, &value, &error);
   set_elem(matrix, 1, 2, &value, &error);
   set_elem(matrix, 2, 0, &value, &error);
   set_elem(matrix, 2, 1, &value, &error);
   set_elem(matrix, 2, 2, &value, &error);
   Matrix* result = add_linear_combination(matrix, 1, alphas, &error);
   get_value(result, 0, 0, &out_value, &error);
   assert(out_value == 3.0);
   get_value(result, 0, 1, &out_value, &error);
   assert(out_value == 3.0);
   get_value(result, 0, 2, &out_value, &error);
   assert(out_value == 3.0);
   get_value(result, 1, 0, &out_value, &error);
   assert(out_value == -12.0);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == -12.0);
   get_value(result, 1, 1, &out_value, &error);
   assert(out_value == -12.0);
   get_value(result, 2, 0, &out_value, &error);
   assert(out_value == 3.0);
   get_value(result, 2, 1, &out_value, &error);
   assert(out_value == 3.0);
   get_value(result, 2, 2, &out_value, &error);
   assert(out_value == 3.0);
   free(matrix);
   free(result);
}

void linear_index_out_of_matrix() {
   TypeInfo* info = get_int_typeinfo();
   MatrixErrors error;
   u_int size = 2;
   int value = 3;
   int alphas[3] = {0, 10}; // Целевая строка будет пропущена
   int out_value = 0;
   Matrix* matrix = create_matrix(size, info, &error);
   set_elem(matrix, 0, 0, &value, &error);
   set_elem(matrix, 0, 1, &value, &error);
   set_elem(matrix, 1, 0, &value, &error);
   set_elem(matrix, 1, 1, &value, &error);
   Matrix* result = add_linear_combination(matrix, 5, alphas, &error);
   assert(error == INDEX_OUT_OF_MATRIX);

   free_matrix(matrix);
   free_matrix(result);
}


void run_all_tests() {
    run_test("1. Создание матрицы нулевого размера", create_zero_size_matrix);
    run_test("2. Создание матрицы 1х1", create_min_size_matrix);
    run_test("3. Создание матрицы отрицательного размера", create_negative_size_matrix);
    run_test("4. Создание матрицы больше допустимого размера", create_too_big_matrix);
    run_test("5. Выход за матрицу (сверху)", test_out_matrix_size_upper);
    run_test("6. Выход за матрицу (отрицательный индекс)", test_out_matrix_negative_index);
    run_test("7. Установка первого и последнего элементов", set_first_last_element);
    run_test("8. Попытка сложить матрицы разных типов", incompatible_matrix_types_addition);
    run_test("9. Попытка умножить матрицы разных типов", incompatible_matrix_types_multiply);
    run_test("10. Попытка сложить матрицы разных размеров", different_matrix_sizes_add);
    run_test("11. Попытка умножить матрицы разных размеров", different_matrix_sizes_multiply);
    run_test("12. Сложение целочисленных матриц", matrix_int_addition);
    run_test("13. Сложение вещественных матриц", matrix_double_addition);
    run_test("14. Умножение целочисленных матриц", matrix_int_multiply);
    run_test("15. Умножение вещественных матриц", matrix_double_multiply);
    run_test("16. Умножение целочисленной матрицы на скаляр", int_scalar_multiply);
    run_test("17. Умножение вещественной матрицы на скаляр", double_scalar_multiply);
    run_test("18. Линейная комбинация строк (целочисленная матрица)", int_linear_combination);
    run_test("19. Линейная комбинация строк (вещественная матрица)", double_linear_combination);
    run_test("20. Некорректный индекс целевой строки при линейной комбинации", linear_index_out_of_matrix);
    puts("=========================ТЕСТИРОВАНИЕ ЗАВЕРШЕНО=========================");

    if (failed > 0) {
        exit(1);
    }
}

int main() {
    run_all_tests();
    return 0;
}