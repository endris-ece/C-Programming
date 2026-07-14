#include <stdio.h>

int main(void){

    float voltage = 15.00;
    float current = 0.35;

    float power = voltage * current;
    float resistance = voltage/current;

    printf("Power = %.3f\n", power);
    printf("Resistance = %.3f\n", resistance);

    int x = 5;
    int y = 2;
    int z = 13;
    float result = x + y/z;
    printf("Result = x + y/z = %f", result);
    return 0;
}