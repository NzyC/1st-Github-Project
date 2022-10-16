#include <stdio.h>

int main(void) {
    int my_number = 1;

    while (my_number != 16) {
        printf("%d\n", my_number);
        my_number *= 2;
    }

}