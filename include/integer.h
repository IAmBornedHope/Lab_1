#pragma once

#include "TypeInfo.h"

/**
 * @brief Функция для сложения двух целых чисел
 * 
 * @param arg1 Указатель на первое число
 * @param arg2 Указатель на второе число
 * @param result Указатель на место записи результата
 */
void int_add(const void* arg1, const void* arg2, void* result);
/**
 * @brief Функция для умножения двух целых чисел
 * 
 * @param arg1 Указатель на первое число
 * @param arg2 Указатель на второе число
 * @param result Указатель на место записи результата
 */
void int_multiply(const void* arg1, const void* arg2, void* result);

/**
 * @brief Функция для вывода целого числа
 * 
 * @param data
 */
void int_print(const void* data);

/**
 * @brief Функция для инициализации элемента целочисленным нулем
 * 
 * @param data 
 */
void int_init_zero(void* data);
TypeInfo* get_int_typeinfo();

