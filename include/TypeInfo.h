#pragma once

#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Сигнатура бинарной операции
 * 
 */
typedef void (*BinaryOperator)(const void* arg1, const void* arg2, void* result);

typedef struct {
    u_int size;
    BinaryOperator add;
    BinaryOperator multiply;
    void (*print)(const void*);
    void (*init_zero)(void* data);
} TypeInfo;