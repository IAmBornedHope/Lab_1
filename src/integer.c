#include "integer.h"

static TypeInfo* int_type_info = NULL;

void int_add(const void* arg1, const void* arg2, void* result) {
    *(int*)result = *(int*)arg1 + *(int*)arg2;
}

void int_multiply(const void* arg1, const void* arg2, void* result) {
    *(int*)result = *(int*)arg1 * *(int*)arg2;
}

void int_print(const void* number) {
    printf("%4d", *(const int*)number);
}

void int_init_zero(void* data) {
    *(int*)data = 0;
}

TypeInfo* get_int_typeinfo() {
    if (int_type_info == NULL) {
        int_type_info = (TypeInfo*)malloc(sizeof(TypeInfo));
        int_type_info->size = sizeof(int);
        int_type_info->add = int_add;
        int_type_info->multiply = int_multiply;
        int_type_info->init_zero = int_init_zero;
        int_type_info->print = int_print;
    }
    return int_type_info;
}