
#include "integer.h"

static TypeInfo* INT_TYPE_INFO = NULL;

void int_add(const void* arg1, const void* arg2, void* result) {
    *(int*)result = *(int*)arg1 + *(int*)arg2;
}

void int_multiply(const void* arg1, const void* arg2, void* result) {
    *(int*)result = *(int*)arg1 * *(int*)arg2;
}

void int_print(const void* number) {
    printf("%d", *(const int*)number);
}

void int_init_zero(void* data) {
    *(int*)data = 0;
}

TypeInfo* get_int_typeinfo() {
    if (INT_TYPE_INFO == NULL) {
        INT_TYPE_INFO = (TypeInfo*)malloc(sizeof(TypeInfo));
        INT_TYPE_INFO->size = sizeof(int);
        INT_TYPE_INFO->add = int_add;
        INT_TYPE_INFO->multiply = int_multiply;
        INT_TYPE_INFO->init_zero = int_init_zero;
        INT_TYPE_INFO->print = int_print;
    }
    return INT_TYPE_INFO;
}