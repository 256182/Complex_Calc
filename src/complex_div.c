#include "stdlib.h"
#include "complex_calculator.h"


error_t complex_div(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv){
    if(NULL == cnum1 || NULL == cnum2){
        return ERROR_NULL_PTR;
    }
    else if(cnum2->real==0 && cnum2->imaginary==0){
        return ERROR_DIV_BY_ZERO;
    }
    else{
        cdiv->real=(((cnum1->real)*(cnum2->real))-((cnum1->imaginary)*cnum2->imaginary))/((cnum2->real*cnum2->real)+(cnum2->imaginary*cnum2->imaginary));
        cdiv->imaginary=(((cnum1->real)*(cnum2->imaginary))+((cnum1->imaginary)*cnum2->real))/((cnum2->real*cnum2->real)+(cnum2->imaginary*cnum2->imaginary));
        return SUCCESS;
    }

}