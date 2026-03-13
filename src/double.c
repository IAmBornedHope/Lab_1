#include "double.h"

static TypeInfo* DOUBLE_TYPE_INFO = NULL;

void double_add(const void* arg1, const void* arg2, void* result) {
    *(double*)result = *(double*)arg1 + *(double*)arg2;
}

void double_multiply(const void* arg1, const void* arg2, void* result) {
    *(double*)result = *(double*)arg1 * *(double*)arg2;
}

void double_print(const void* number) {
    printf("%8.3f", *(const double*)number);
}

void double_init_zero(void* data) {
    *(double*)data = 0;
}

TypeInfo* get_double_typeinfo() {
    if (DOUBLE_TYPE_INFO == NULL) {
        DOUBLE_TYPE_INFO = (TypeInfo*)malloc(sizeof(TypeInfo));
        DOUBLE_TYPE_INFO->size = sizeof(double);
        DOUBLE_TYPE_INFO->add = double_add;
        DOUBLE_TYPE_INFO->multiply = double_multiply;
        DOUBLE_TYPE_INFO->init_zero = double_init_zero;
        DOUBLE_TYPE_INFO->print = double_print;
    }
    return DOUBLE_TYPE_INFO;
}