#include <stdio.h>

int main(void) {
    char name[100];

    printf("What's your name?\n");
    scanf("%s", name);

    printf("Hello, %s!\n", name);
}