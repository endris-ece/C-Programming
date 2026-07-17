#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    LOWERCASE=1,
    UPPERCASE,
    NUMBERS,
    SPECIAL_CHAR,
    ALL
} Characters;

int enter_password_length()
{
    int password_length;
    int c;
    int max = 50;

    while(1)
    {
        printf("Enter Password Length: ");
        if(scanf("%d", &password_length) == 1 && password_length >= 1 && password_length <= max)
        {return password_length;}

        printf("Invalid Length! Value should be <= %d\n", max);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

Characters menu()
{
    Characters character;
    int c;

    while(1)
    {
        printf("Select characters to include:\n");
        printf("1. Lowercase letters (a-z)\n");
        printf("2. Uppercase letters (A-Z)\n");
        printf("3. Numbers (0-9)\n");
        printf("4. Special characters (!@#$%^&*)\n");
        printf("5. All characters\n\n");
        printf("Enter Choice: ");
        
        if (scanf("%d", &character) == 1 && character >= LOWERCASE && character <= ALL)
        {
            return character;
        }
        
        printf("Invalid Input!\n\n");
        while((c = getchar()) != '\n' && c != EOF);
    }
}

char generate_password(Characters character)
{
    char c;
    switch(character)
    {
        case LOWERCASE:
        c = rand() % 26 + 97;
        break;

        case UPPERCASE:
        c = rand() % 26 + 65;
        break;
        
        case NUMBERS:
        c = rand() % 10 + 48;
        break;

        case SPECIAL_CHAR:
        int random_for_char = rand() % 3;
        if (random_for_char == 0)
        {
            c = rand() % 16 + 32;
        }
        else if(random_for_char == 1)
        {
            c = rand() % 7 + 58;
        }
        else{c = rand() % 6 + 91;}
        break;

        case ALL:
        c = rand() % 94 + 33;
        break;

        default:
            break;
    }
    return c;

}

int generate_again()
{
    int choice;
    int c;

    while(1)
    {
        printf("Generate Another Password?\n");
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
    int password_len;
    char c;
    char password[51] = "\0";
    Characters character;

    printf("====================================\n");
    printf("Password Generator\n");
    printf("====================================\n");

    while(1)
    {
        password_len = enter_password_length();
        character = menu();
        for(int i=0; i < password_len; i++)
        {
            c = generate_password(character);
            password[i] = c;
        }
        password[password_len]='\0';
        printf("====================================\n");
        printf("Generated Password:\n");
        printf("%s\n", password);
        printf("====================================\n");

        int again = generate_again();
        if(again == 2){break;}
    }

    return 0;
}