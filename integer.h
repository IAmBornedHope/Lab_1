#pragma once

#include "TypeInfo.h"

void int_add(const void* arg1, const void* arg2, void* result);
void int_multiply(const void* arg1, const void* arg2, void* result);
void int_print(const void* data);
TypeInfo* get_int_typeinfo();

