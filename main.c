#include "define.h"
#include "integer.h"
#include "matrix.h"
#include "TypeInfo.h"
#include "errors.h"




int main() {

    MatrixErrors operationResult = MATRIX_OPERATION_OK;
    TypeInfo* int_type = get_int_typeinfo();

    Matrix* m1 = create_matrix(2, int_type, &operationResult);
    Matrix* m2 = create_matrix(2, int_type, &operationResult);
    Matrix* result = create_matrix(2, int_type, &operationResult);


    reset_matrix(result);
    int value;
    int value_2;
    value = 1;
    value_2 = 4;

    int scalar;
    scalar = 13;
    
    set_elem(m1, 0, 0, &value);
    set_elem(m1, 0, 1, &value);
    set_elem(m1, 1, 0, &value);
    set_elem(m1, 1, 1, &value_2);


     set_elem(m2, 0, 0, &value_2);
     set_elem(m2, 0, 1, &value_2);
     set_elem(m2, 1, 0, &value_2);
     set_elem(m2, 1, 1, &value_2);

    //matrix_add(m1, m2, result);

     //matrix_multiply(m1, m2, result);
    matrix_on_scalar(m1, &scalar, result);
    
    print_matrix(m1);
    puts("");
    print_matrix(m2);
    

    print_matrix(result);

    return 0;

    
}