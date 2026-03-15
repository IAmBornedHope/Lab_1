#include "double.h"

static TypeInfo* double_type_info = NULL;

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
    *(double*)data = 0.0;
}

TypeInfo* get_double_typeinfo() {
    if (double_type_info == NULL) {
        double_type_info = (TypeInfo*)malloc(sizeof(TypeInfo));
        double_type_info->size = sizeof(double);
        double_type_info->add = double_add;
        double_type_info->multiply = double_multiply;
        double_type_info->init_zero = double_init_zero;
        double_type_info->print = double_print;
    }
    return double_type_info;
}