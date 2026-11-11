#include <stddef.h>
#include <stdio.h>

void sort(int input[], size_t length);

int main() {
    int input[] = {54, 102, 78, 2, 20, 12, 1, 35};
    size_t length = sizeof(input) / sizeof(int);
    sort(input, length);
    for(size_t i = 0; i < length; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}

void sort(int input[], size_t length) {
    for(size_t i = 0; i < length; i++) {
        for (size_t j = 0; j + 1 < length - i; j++) {
            if (input[j] > input[j + 1]) {
                input[j] = input[j] ^ input[j + 1];
                input[j + 1] = input[j] ^ input[j + 1];
                input[j] = input[j] ^ input[j + 1];
            }
        }
    }
}

/*
 a = a ^ b;
 b = a ^ b;
 a = a ^ b;
 */
