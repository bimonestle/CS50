#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countArgv(int count, char *arg[]);
int readKey(char *arg[]);
int valKey(char *arg[]);

int main(int argc, char *argv[])
{
    countArgv(argc, &argv[1]);

    return 0;
}

int countArgv(int count, char *arg[]) {
    int valid = valKey(arg);
    
    if (count == 2 && valid > 0)
    {
        printf("Success\n");
        return 1;
    }
    else
    {
        printf("Usage: ./caesar {int key}\n");
        return 0;
    }
}

int readKey(char *arg[]) {
    printf("The key is %s\n", *arg);
    valKey(arg);
    return 1;
}

int valKey(char *arg[]) {
    int length = strlen(*arg);
    int result = 0;
    // printf("ini: %s, %i\n", *arg,length);

    for (int i = 0; i < length; i++)
    {
        int digit = isdigit(arg[0][i]);
        if (digit < 1)
        {
            // printf("Usage: ./caesar {int key}\n");
            return digit;
            break;
        }
    }
    return 1;
}