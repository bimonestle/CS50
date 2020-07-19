#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countArgv(int count);
int readKey(char *arg[]);

int main(int argc, char *argv[])
{
    countArgv(argc);
    readKey(&argv[1]);

}

int countArgv(int count) {
    if (count == 2)
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
    printf("The key is %s", *arg);
    return 1;
}