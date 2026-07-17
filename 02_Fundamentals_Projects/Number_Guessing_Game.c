#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {
    Easy = 10,
    Medium = 50,
    Hard = 100,
    Exit
} Difficulty;


Difficulty menu()
{
    Difficulty state;
    int c;
    int difficulty;

    while(1){
        printf("=================== Number Guessing Game ===================\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("4. Exit\n\n");
        printf("Choose difficulty\n: ");
        if (scanf("%d", &difficulty) == 1){
            switch (difficulty){
                case 1:
                state = Easy;
                return state;
                case 2:
                state = Medium;
                return state;
                case 3:
                state = Hard;
                return state;
                case 4:
                state = Exit;
                return state;
                default:
                printf("Invalid Input, input shoub be in 1 to 4!\n\n");
            }
        }
        printf("Invalid input.\n\n");

        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int random_number(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int get_guess(int min, int max){
    int value;
    int c;

    while (1)
    {
        printf("Guess the number\n: ");
        if (scanf("%d", &value) == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF);

            if(value >= min && value <= max){
                return value;
            }
            else{
                printf("Number must be between %d and %d\n", min, max);
            }
        }

        printf("Invalid number.\nPress Enter!");

        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void play_game(int computer, int guess, int attempts){
    if(computer > guess ){
        printf("Too Low!\n");
    }
    else if(computer < guess){
        printf("Too High!\n");
    }
    else{printf("Congratulations!\nYou guessed the number in %d attempts!\n", attempts);}}


int play_again()
{
    int choice;
    int c;

    while(1)
    {
        printf("Play Again?\n");
        printf("1. YES\n");
        printf("2. NO\n");

        if(scanf("%d",&choice)==1)
        {
            while((c=getchar())!='\n' && c!=EOF);

            if(choice==1 || choice==2)
                return choice;
        }

        printf("Invalid input\nPress Enter");
        while((c=getchar())!='\n' && c!=EOF);
    }
}

int main(void)
{
    srand(time(NULL));
    int min = 1;
    Difficulty state = menu();
    int generated_number = random_number(min, state);
    while(state != Exit){
        int attempt = 0;
        while(1){
        int guessed_number = get_guess(min, state);
        attempt++;
        play_game(generated_number, guessed_number, attempt);
        if(guessed_number == generated_number){break;}}
    int play = play_again();
    if (play == 2){break;}
    else{
        state = menu();
        if(state == Exit){break;}
        generated_number = random_number(min, state);}}    
    return 0;
}