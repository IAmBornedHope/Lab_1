#include <math.h>
#include <float.h>
#include "testing.h"
#include "matrix.h"

TEST(test_double_add_positive) {
    puts("ТЕСТ 8.1");
    puts("Сложение вещественных чисел. Оба числа положительны (5 случаев)");
    double a, b, result, expect;

    a = 20.0, b = 30.0, expect = 50.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 1.0, b = 2.0, expect = 3.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0, b = 234.0, expect = 334.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0, b = 200.0, expect = 300.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100000000.0, b = 100000000.0, expect = 200000000.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_add_negative) {
    puts("ТЕСТ 8.2");
    puts("Сложение вещественных чисел. Оба числа отрицательны (5 случаев)");
    double a, b, result, expect;

    a = -20.0, b = -30.0, expect = -50.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -1.0, b = -2.0, expect = -3.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100.0, b = -234.0, expect = -334.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
    a = -100.0, b = -200.0, expect = -300.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100000000.0, b = -100000000.0, expect = -200000000.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_positive_add_negative) {
    puts("ТЕСТ 8.3");
    puts("Сложение вещественных чисел. Одно число отрицательно, одно положительно (3 случая)");
    double a, b, result, expect;

    a = -20.0, b = 30.0, expect = 10.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -1.0, b = 1.0, expect = 0.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100.0, b = 10.0, expect = -90.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

}

TEST(test_double_add_zero) {
    puts("ТЕСТ 8.4");
    puts("Сложение вещественных чисел. Сложение с нулем (3 случая)");
    double a, result, expect;
    double b = 0;

    a = -20.0, expect = -20.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 0.0, expect = 0.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 5.0, expect = 5.0;
    double_add(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_multiply_positive) {
    puts("ТЕСТ 8.5");
    puts("Умножение вещественных чисел. Оба числа положительны (5 случаев)");
    double a, b, result, expect;

    a = 20.0, b = 30.0, expect = 600.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 1.0, b = 2.0, expect = 2.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0, b = 234.0, expect = 23400.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0, b = 200.0, expect = 20000.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 5.0, b = 100000000.0, expect = 500000000.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_multiply_negative) {
    puts("ТЕСТ 8.6");
    puts("Умножение вещественных чисел. Оба числа отрицательны (5 случаев)");
    double a, b, result, expect;

    a = -20.0, b = -30.0, expect = 600.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -1.0, b = -2.0, expect = 2.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100.0, b = -234.0, expect = 23400.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100.0, b = -200.0, expect = 20000.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -5.0, b = -100000000.0, expect = 500000000.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_positive_multiply_negative) {
    puts("ТЕСТ 8.7");
    puts("Умножение целых чисел. Одно число отрицательно, одно положительно (3 случая)");
    double a, b, result, expect;

    a = -20.0, b = 30.0, expect = -600.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -1.0, b = 2.0, expect = -2.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = -100.0, b = 234.0, expect = -23400.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_multiply_zero) {
    puts("ТЕСТ 8.8");
    puts("Умножение вещественных чисел. Умножение на ноль (3 случая)");
    double a, result;
    double b = 0.0, expect = 0.0;

    a = -20.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 0.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

TEST(test_double_multiply_one) {
    puts("ТЕСТ 8.9");
    puts("Умножение вещественных чисел. Умножение на единицу (3 случая)");
    double a, result, expect;
    double b = 1.0;

    a = -20.0, expect = -20.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 0.0, expect = 0.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);

    a = 100.0, expect = 100.0;
    double_multiply(&a, &b, &result);
    assert(result - expect < DBL_EPSILON);
}

