#include <stdio.h>

int main(void){

    float voltage;
    float current;
    float resistance;
    printf("Enter the value of voltage\n:");
    int result_A = scanf("%f", &voltage);
    printf("Enter the value of resistance\n:");
    int result_B = scanf("%f", &resistance);
    
    
    if (result_A == 1 && result_B == 1)
    {
        current = voltage/resistance;
        printf("Current = %.3f", current);

    }
    else
    {
        printf("Invalid input!\n");
    }

    return 0;
}