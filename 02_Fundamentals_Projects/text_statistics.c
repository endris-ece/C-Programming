#include <stdio.h>
#include <string.h>
#include <ctype.h>


void statistics(char statement[])
{
    int length = strlen(statement) - 1;
    int characters = 0;
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int words = 0;
    int uppercase = 0;
    int lowercase = 0;
    for(int i = 0; i < length; i++)
    {
        if(!(isspace(statement[i]))){characters++;}
        if(isdigit(statement[i])){digits++;}
        if(isupper(statement[i])){uppercase++;letters++;}
        if(islower(statement[i])){lowercase++;letters++;}
        if(isspace(statement[i])){spaces++;
        if(!(isspace(statement[i+1]))){words++;}}}
        if(!(isspace(statement[0]))){words++;}

    printf("Characters  : %d\n", characters);
    printf("Letters     : %d\n", letters);
    printf("Digits      : %d\n", digits);
    printf("Spaces      : %d\n", spaces);
    printf("Words       : %d\n", words);
    printf("Uppercase   : %d\n", uppercase);
    printf("Lowercase   : %d\n", lowercase);
    
}

int analyze_again()
{
    int choice;
    int c;

    while(1)
    {
        printf("Analyze another sentence?\n");
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
    printf("=================================\n");
    printf("TEXT STATISTICS\n");
    printf("=================================\n");

    char sentence[10001];

    while (1)
    {
        printf("Enter a sentence:\n> ");
        fgets(sentence, sizeof(sentence), stdin);
        printf("=================================\n");
        printf("Statistics\n\n");
        statistics(sentence);
        printf("=================================\n");
        if(analyze_again() == 2){break;}
    }
    
    return 0;
}