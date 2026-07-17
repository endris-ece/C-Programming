#include <stdio.h>

int main(void)
{
    int temperature;
    int option;


    printf("Enter temperature: ");
    scanf("%d", &temperature);


    if(temperature > 30)
    {
        printf("Hot\n");
    }
    else if(temperature > 15)
    {
        printf("Normal\n");
    }
    else
    {
        printf("Cold\n");
    }


    if(temperature >= 20 && temperature <= 30)
    {
        printf("Comfortable temperature\n");
    }


    printf("\nChoose option:\n");
    printf("1. Voltage\n");
    printf("2. Current\n");
    printf("3. Resistance\n");

    scanf("%d", &option);


    switch(option)
    {
        case 1:
            printf("Voltage selected\n");
            break;

        case 2:
            printf("Current selected\n");
            break;

        case 3:
            printf("Resistance selected\n");
            break;

        default:
            printf("Invalid option\n");
    }


    return 0;
}