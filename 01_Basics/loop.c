#include <stdio.h>

int main(void){

    float voltage;
    while (1){
        printf("Enter the value of voltage\n:");
        int result = scanf("%f", &voltage);
        if (result == 1){
            if (voltage > 5){
                printf("Over voltage!\n");
            }
            else if (voltage < 0){
                printf("Invalid!\n");
            }
            else if (voltage == -999){
                break;
            }
            else{
                printf("Normal!\n");
            }
        }
        else{
            printf("Invalid input, insert only a numeric!\n");
        }

    }

    return 0;
}