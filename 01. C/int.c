#include <stdio.h>

int main (void) {
    int age;

    printf("What's your age?\n");
    scanf("%i", &age);
    int days = age * 365;
    
    printf("Your age is %i years old and %i days old\n", age, days);
    // printf("Your age is %i years old and %i days old\n", age, age * 365);
}