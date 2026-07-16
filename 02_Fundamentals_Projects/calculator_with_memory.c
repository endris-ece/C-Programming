#include <stdio.h>
#include <math.h>
#include <string.h>

enum State  {
        Add = 1, Subtract, Multiply, Divide, Square_Root, Power, Clear_Memory, View_History, Exit
    };

float addition(float current,float value){
    return current + value;
}

float subtraction(float current,float input_value){
    return current - input_value;
}

float multiplication(float current,float input_value){
    return current * input_value;
}

float division(float current,float input_value)
{
    if(input_value == 0)
    {
        printf("Cannot divide by zero\n");
        return current;
    }

    return current / input_value;
}

float power(float current,float input_value)
{
    if(current == 0 && input_value == -1)
    {
        printf("Invalid input!\n");
        return current;
    }

    return pow(current,input_value);
}

float square_root(float current)
{
    if(current < 0)
    {
        printf("Cannot square root negative number\n");
        return current;
    }

    return sqrt(current);
}

enum State menu()
{
    enum State state;
    int c;

    while (1)
    {
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Square_Root\n");
        printf("6. Power\n");
        printf("7. Clear_Memory\n");
        printf("8. View_History\n");
        printf("9. Exit\n");

        printf("Choose an option: ");

        if (scanf("%d", &state) == 1 && state >= Add && state <= Exit)
{
    while ((c = getchar()) != '\n' && c != EOF);
    return state;
}

        printf("Invalid input. Choose from 1-9.\n\n");

        while ((c = getchar()) != '\n' && c != EOF);
    }
}

float get_float()
{
    float value;
    int c;

    while (1)
    {
        if (scanf("%f", &value) == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF);
            return value;
        }

        printf("Invalid number.\n");

        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int main(void)
{

    #define HISTORY_SIZE 10000
    char history[HISTORY_SIZE] = "";
    float current_value = 0;
    float input_value = 0;

    enum State state = menu();

    while(state != Exit){
        switch(state){
        case Add:

        printf("Enter Value: ");
        input_value = get_float();
        current_value = addition(current_value, input_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history), " + %.2f", input_value);
        break;

        case Subtract:
        printf("Enter Value: ");
        input_value = get_float();
        current_value = subtraction(current_value, input_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history), " - %.2f", input_value);
        break;

        case Multiply:
        printf("Enter Value: ");
        input_value = get_float();
        current_value = multiplication(current_value, input_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history), " * %.2f", input_value);
        break;

        case Divide:
        printf("Enter Value: ");
        input_value = get_float();
        current_value = division(current_value, input_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history), " / %.2f", input_value);
        break;

        case Power:
        printf("Enter Value: ");
        input_value = get_float();
        current_value = power(current_value, input_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history),
        " ^ %.2f",
        input_value);
        break;

        case Square_Root:
        current_value = square_root(current_value);
        printf("Current Value = %f\n", current_value);
        sprintf(history + strlen(history),
        " ^1/2");
        break;

        case Clear_Memory:
        current_value = 0;
        history[0] = '\0';
        break;

        case View_History:
        printf("0 %s = %f\n\n", history, current_value);
        break;

        case Exit:
        break;

        default:
        printf("Invalid Input\n");
    }

        state = menu();}

    return 0;
}