#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_diff(complex_t* cnum1, complex_t* cnum2, complex_t* cdiff){
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    else{
    cdiff->real = cnum1->real - cnum2->real;
    cdiff->imaginary = cnum1->imaginary - cnum2->imaginary;

    return SUCCESS;
    }
}