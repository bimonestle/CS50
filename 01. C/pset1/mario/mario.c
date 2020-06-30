#include <stdio.h>

void printHash(void);

int main(void) {
    printHash();
}

void printHash(void) {
    int height;

    do {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height <= 0 || height > 8);

    if (height > 0 && height <=8) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < height; j++) {
                // if (j == i) {
                //     printf("#");
                //     break;
                // }
                // printf("#");
                if (j >= height - 1 - i) {
                    printf("#");
                }
            }
            printf("\n");
        }
    }

}