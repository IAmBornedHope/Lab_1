#include <locale.h>
#include <windows.h>
#include "matrix.h"
#include "output.h"

int main() {

    setlocale(LC_ALL, "C.UTF8");
    SetConsoleOutputCP(CP_UTF8);

    u_int type = 0, size = 0, mode = 0;
    TypeInfo* info;
    MatrixErrors error = MATRIX_OPERATION_OK;
    int int_value;
    double double_value;

    puts("Программа запущена. Выберите режим работы:\n");
    puts("[1] - Работа с целыми числами\n[2] - Работа с вещественными числами");
    scanf("%u", &type);
    puts("Введите размер квадратной матрицы от 1 до 10000 включительно: ");
    scanf("%u", &size);
    if (size > 10000) {
        puts("Некорректный размер матрицы");
        return 1;
    }

    if (type == 1) info = get_int_typeinfo();

    if (type == 2) info = get_double_typeinfo();
    
    Matrix* first_matrix = create_matrix(size, info, &error);
    if (!first_matrix) {
        print_error(error);
        return 1;
    }

    puts("Введите матрицу поэлементно:");

    if (type == 1) {
        int value;
        for (u_int row = 0; row < size; ++row) {
            for (u_int col = 0; col < size; ++col) {
                printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                scanf("%d", &value);
                set_elem(first_matrix, row, col, &value, &error);
            }
        }
    }
    else {
        double value;
        for (u_int row = 0; row < size; ++row) {
            for (u_int col = 0; col < size; ++col) {
                printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                scanf("%lf", &value);
                set_elem(first_matrix, row, col, &value, &error);
            }
        }
    }

    puts("Вы ввели матрицу:");
    print_matrix(first_matrix);
    puts("Выберите операцию: ");
    puts("[1] - Сложение матриц\n[2] - Умножение матриц\
        \n[3] - Умножение матрицы на скаляр\n[4] - Прибавление к строке линейной комбинации других строк");
    scanf("%u", &mode);

    switch (mode) {
        case 1: {
            Matrix* second_matrix = create_matrix(size, info, &error);
            Matrix* result_matrix = create_matrix(size, info, &error);
            if (!second_matrix || !result_matrix) {
                print_error(error);
                return 1;
            }
            puts("Введите вторую матрицу поэлементно:");

            if (type == 1) {
                int value;
                for (u_int row = 0; row < size; ++row) {
                    for (u_int col = 0; col < size; ++col) {
                        printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                        scanf("%d", &value);
                        set_elem(second_matrix, row, col, &value, &error);
                    }
                }
            }
            else {
                double value;
                for (u_int row = 0; row < size; ++row) {
                    for (u_int col = 0; col < size; ++col) {
                        printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                        scanf("%lf", &value);
                        set_elem(second_matrix, row, col, &value, &error);
                    }
                }
            }
            matrix_add(first_matrix, second_matrix, result_matrix, &error);
            print_matrix(first_matrix);
            print_matrix(second_matrix);
            print_matrix(result_matrix);
            free_matrix(second_matrix);
            free_matrix(result_matrix);
            break; }
        case 2: {
            Matrix* second_matrix = create_matrix(size, info, &error);
            Matrix* result_matrix = create_matrix(size, info, &error);
            if (!second_matrix || !result_matrix) {
                print_error(error);
                return 1;
            }
            puts("Введите вторую матрицу поэлементно:");

            if (type == 1) {
                int value;
                for (u_int row = 0; row < size; ++row) {
                    for (u_int col = 0; col < size; ++col) {
                        printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                        scanf("%d", &value);
                        set_elem(second_matrix, row, col, &value, &error);
                    }
                }
            }
            else {
                double value;
                for (u_int row = 0; row < size; ++row) {
                    for (u_int col = 0; col < size; ++col) {
                        printf("Введите %d-ый элемент %d-ой строки: \n", col+1, row+1);
                        scanf("%lf", &value);
                        set_elem(second_matrix, row, col, &value, &error);
                    }
                }
            }
            matrix_multiply(first_matrix, second_matrix, result_matrix, &error);
            print_matrix(first_matrix);
            print_matrix(second_matrix);
            print_matrix(result_matrix);
            free_matrix(second_matrix);
            free_matrix(result_matrix);
            break; }
        case 3: {
            puts("Введите скаляр для умножения: ");
            Matrix* result_matrix = create_matrix(size, info, &error);
            if (!result_matrix) {
                print_error(error);
                return 1;
            }

            if (type == 1) {
                int scalar;
                scanf("%d", &scalar);
                matrix_on_scalar(first_matrix, &scalar, result_matrix, &error);
            }
            else {
                double scalar;
                scanf("%lf", &scalar);
                matrix_on_scalar(first_matrix, &scalar, result_matrix, &error);
            }
            print_matrix(result_matrix);
            free_matrix(result_matrix);
            break;
        }
        case 4: {
            u_int target_row;
            puts("Введите строку, к которой необходимо прибавить линейную комбинацию: ");
            scanf("%d", &target_row);
            if (target_row > size) {
                puts("Некорректный индекс целевой строки");
                return 1;
            }
            target_row--;
            u_int element_size = first_matrix->info->size;
            void* alphas = malloc(size * element_size);
            char* base = (char*)alphas;
            if (!alphas) {
                puts("Ошибка выделения памяти");
                return 1;
            }

            for (u_int index = 0; index < size; ++index) {
                if (index == target_row) continue;
                    printf("Введите коэффициент для %u-й строки:\n", index + 1);
                if (element_size == sizeof(int)) {
                    int value;
                    scanf("%d", &value);
                    memcpy(base + index * sizeof(int), &value, sizeof(int));
                }
                else if (element_size == sizeof(double)) {
                    double value;
                    scanf("%lf", &value);
                    memcpy(base + index * sizeof(double), &value, sizeof(double));
                }
                
            }

            Matrix* result_matrix = add_linear_combination(first_matrix, target_row, alphas, &error);
            print_matrix(first_matrix);
            print_matrix(result_matrix);
            free(alphas);
            free_matrix(result_matrix);
            break;
        }
    
    }
    puts("Работа завершена. Статус программы: ");
    print_error(error);
    return 0;
}
