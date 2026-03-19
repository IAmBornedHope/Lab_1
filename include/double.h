#pragma once

#include "TypeInfo.h"

/**
 * @brief Функция для сложения двух вещественных чисел
 * 
 * @param arg1 Указатель на первое число
 * @param arg2 Указатель на второе число
 * @param result Указатель на место записи результата
 */
void double_add(const void* arg1, const void* arg2, void* result);

/**
 * @brief Функция для умножения двух целых чисел
 * 
 * @param arg1 Указатель на первое число
 * @param arg2 Указатель на второе число
 * @param result Указатель на место записи результата
 */
void double_multiply(const void* arg1, const void* arg2, void* result);

/**
 * @brief Функция для вывода целого числа
 * 
 * @param data
 */
void double_print(const void* data);

/**
 * @brief Функция для инициализации элемента вещественным нулем
 * 
 * @param data Указатель на нужный элемент
 */
void double_init_zero(void* data);

TypeInfo* get_double_typeinfo();
