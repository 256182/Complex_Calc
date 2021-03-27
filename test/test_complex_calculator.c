#include "complex_calculator.h"
#include "unity.h"

static complex_t c1 = {0, 0};
static complex_t c2 = {0, 0};
static complex_t result = {0, 0};
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_zero(void)
{
    // Can ommi the below intialization as it is done at the declaration time
    
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    TEST_ASSERT_EQUAL(ERROR_DIV_BY_ZERO, complex_div(&c1, &c2, &result));
    

}
void test_positive(void)
{
    c1.real = 4;
    c1.imaginary = 2;
    
    c2.real = 2;
    c2.imaginary = 1;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(6, result.real);
    TEST_ASSERT_EQUAL(3, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(2, result.real);
    TEST_ASSERT_EQUAL(1, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(6, result.real);
    TEST_ASSERT_EQUAL(8, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(1, result.real);
    TEST_ASSERT_EQUAL(1, result.imaginary);
}

void test_negative(void)
{
    c1.real = -2;
    c1.imaginary = -1;
    
    c2.real = 4;
    c2.imaginary = 2;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(2, result.real);
    TEST_ASSERT_EQUAL(1, result.imaginary);

    
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-6, result.real);
    TEST_ASSERT_EQUAL(-3, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-6, result.real);
    TEST_ASSERT_EQUAL(-8, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_zero);
    RUN_TEST(test_positive);
    RUN_TEST(test_negative);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
