#include <stdio.h>

void cough(int loop);

int main(void) {
    cough(8);
}

void cough(int loop) {
    for(int i = 0; i < loop; i++) {
        printf("Cough\n");
    }
}