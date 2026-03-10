#pragma once

#include "TypeInfo.h"

void double_add(const void* arg1, const void* arg2, void* result);
void double_multiply(const void* arg1, const void* arg2, void* result);
void double_print(const void* data);
void double_init_zero(void* data);
TypeInfo* get_double_typeinfo();
