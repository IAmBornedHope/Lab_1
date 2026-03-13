#pragma once
#include <assert.h>
#include "matrix.h"

/**
 * @brief Запуск одного теста
 * 
 * @param name Название теста
 * @param func Указатель на тест
 */
void run_test(const char* name, void (*func)());

/**
 * @brief Запуск всех тестов
 * 
 */
void run_all_tests();
