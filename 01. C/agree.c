#include <stdio.h>

int main (void) {
    char a [4];
    printf("Do you agree? ");
    scanf("%s", a);

    if (*a == 'y' || *a == 'Y') {
        printf("Agreed\n");
    } else if (*a == 'n' || *a == 'N') {
        printf("Not agreed.\n");
    }
}