#include <stdio.h>

int main(void)
{
    int integer_value = 5;
    int divisor = 2;

    float result1;
    float result2;

    result1 = integer_value / divisor;

    result2 = (float)integer_value / divisor;


    printf("Without casting: %.2f\n", result1);
    printf("With casting: %.2f\n", result2);

    return 0;
}