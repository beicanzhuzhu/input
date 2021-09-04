#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * input(char[]);

int main(void)
{
    const char * str = input("p\n");
    puts(str);
    getchar();
    getchar();
    return 0;
}

char * input(char msg[])
{
    if (msg)
        printf("%s", msg);

    char *p1 = NULL;
    char *p2 = NULL;
    char a[2];
    int i = 1;
    while((a[0] = getchar()) != '\n')
    {

        if((i % 2) == 1)
        {
            p1 = (char *)malloc((i+1) * sizeof(char));
            if(p1 == NULL)
                printf("warning!");
            if(p2 != NULL)
            {
                strcat(p1, p2);
                free(p2);
            }
            strcat(p1, a);
        }
        else
        {
            p2 = (char *)malloc((i+1) * sizeof(char));
            if(p2 == NULL)
                printf("warning!");
            strcpy(p2, p1);
            free(p1);
            strcat(p2, a);
        }
        i++;
    }
    if((i-1) % 2 == 1)
    {
        return p1;
    }
    else
    {
        return p2;
    }
        
}