#include <stdio.h>

int main(void)
{
    int age = 20;
    float voltage = 3.3f;
    double frequency = 50.123456;
    char grade = 'A';

    printf("Integer: %d\n", age);
    printf("Float: %.2f\n", voltage);
    printf("Double: %.6lf\n", frequency);
    printf("Character: %c\n\n", grade);


    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));

    return 0;
}