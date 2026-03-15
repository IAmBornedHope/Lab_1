#include "testing.h"
#include "matrix.h"

TEST(test_int_add_positive) {
    puts("ТЕСТ 7.1");
    puts("Сложение целых чисел. Оба числа положительны (5 случаев)");
    int a, b, result, expect;

    a = 20, b = 30, expect = 50;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 1, b = 2, expect = 3;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 100, b = 234, expect = 334;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 100, b = 200, expect = 300;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 100000000, b = 100000000, expect = 200000000;
    int_add(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_add_negative) {
    puts("ТЕСТ 7.2");
    puts("Сложение целых чисел. Оба числа отрицательны (5 случаев)");
    int a, b, result, expect;

    a = -20, b = -30, expect = -50;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -1, b = -2, expect = -3;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -100, b = -234, expect = -334;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -100, b = -200, expect = -300;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -100000000, b = -100000000, expect = -200000000;
    int_add(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_positive_add_negative) {
    puts("ТЕСТ 7.3");
    puts("Сложение целых чисел. Одно число отрицательно, одно положительно (3 случая)");
    int a, b, result, expect;

    a = -20, b = 30, expect = 10;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -1, b = 1, expect = 0;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = -100, b = 10, expect = -90;
    int_add(&a, &b, &result);
    assert(expect == result);

}

TEST(test_int_add_zero) {
    puts("ТЕСТ 7.4");
    puts("Сложение целых чисел. Сложение с нулем (3 случая)");
    int a, result, expect;
    int b = 0;

    a = -20, expect = -20;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 0, expect = 0;
    int_add(&a, &b, &result);
    assert(expect == result);

    a = 5, expect = 5;
    int_add(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_multiply_positive) {
    puts("ТЕСТ 7.5");
    puts("Умножение целых чисел. Оба числа положительны (5 случаев)");
    int a, b, result, expect;

    a = 20, b = 30, expect = 600;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 1, b = 2, expect = 2;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 100, b = 234, expect = 23400;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 100, b = 200, expect = 20000;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 5, b = 100000000, expect = 500000000;
    int_multiply(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_multiply_negative) {
    puts("ТЕСТ 7.6");
    puts("Умножение целых чисел. Оба числа отрицательны (5 случаев)");
    int a, b, result, expect;

    a = -20, b = -30, expect = 600;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -1, b = -2, expect = 2;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -100, b = -234, expect = 23400;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -100, b = -200, expect = 20000;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -5, b = -100000000, expect = 500000000;
    int_multiply(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_positive_multiply_negative) {
    puts("ТЕСТ 7.7");
    puts("Умножение целых чисел. Одно число отрицательно, одно положительно (3 случая)");
    int a, b, result, expect;

    a = -20, b = 30, expect = -600;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -1, b = 2, expect = -2;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = -100, b = 234, expect = -23400;
    int_multiply(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_multiply_zero) {
    puts("ТЕСТ 7.8");
    puts("Умножение целых чисел. Умножение на ноль (3 случая)");
    int a, result;
    int b = 0, expect = 0;

    a = -20;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 0;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 100;
    int_multiply(&a, &b, &result);
    assert(expect == result);
}

TEST(test_int_multiply_one) {
    puts("ТЕСТ 7.9");
    puts("Умножение целых чисел. Умножение на единицу (3 случая)");
    int a, result, expect;
    int b = 1;

    a = -20, expect = -20;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 0, expect = 0;
    int_multiply(&a, &b, &result);
    assert(expect == result);

    a = 100, expect = 100;
    int_multiply(&a, &b, &result);
    assert(expect == result);
}

