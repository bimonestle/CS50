#include <stdio.h>

int main (void) {
    int number;

    printf("Enter a number:");
    scanf("%i", &number);
    
    if(number % 2 == 0) {
        printf("The number %i is even", number);
    } else {
        printf("The number %i is odd", number);
    }
}