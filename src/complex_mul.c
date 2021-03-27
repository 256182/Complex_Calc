#include "stdlib.h"
#include "complex_calculator.h"

/*num1= a+ib ,num2=c+id */

error_t complex_mul(complex_t* cnum1, complex_t* cnum2, complex_t* cmul){
    if(NULL == cnum1 || NULL == cnum2){
        return ERROR_NULL_PTR;
    }
    else{
    cmul->real=(((cnum1->real)*(cnum2->real))-((cnum1->imaginary)*cnum2->imaginary));/*ac-bd*/ 
    cmul->imaginary=(((cnum1->real)*(cnum2->imaginary))+((cnum1->imaginary)*cnum2->real));/*ac+bd*/
    return SUCCESS;
    }
}