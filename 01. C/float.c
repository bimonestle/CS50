#include <stdio.h>

int main (void) {
    float price;

    printf("What's the price?\n");
    scanf("%f", &price);

    float afterTax = price * 1.1000;
    // printf("The price is Rp. %f ", afterTax);
    printf("The price is Rp. %.2f\n", afterTax); // 2 digits behind the point
}