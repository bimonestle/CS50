#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countArgv(int count, char *arg[]);

int main(int argc, char *argv[])
{
    countArgv(argc, &argv[0]);
}

int countArgv(int count, char *arg[]) {
    if (count == 2)
    {
        printf("Success");
        return 1;
    }
    else
    {
        printf("Usage: ./caesar {int key}");
        return 0;
    }
}