#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int input[], size_t i, size_t j);

bool is_out_of_order(int left, int right, bool descending);

void sort(int input[], size_t length, bool descending);

void print_list(int input[], size_t length);

bool ask_descending();

int main() {
    int input[] = {54, 102, 78, 2, 20, 12, 1, 35};
    size_t length = sizeof(input) / sizeof(int);

    printf("Unsorted: ");
    print_list(input, length);

    bool descending = ask_descending();
    sort(input, length, descending);

    printf("Sorted:   ");
    print_list(input, length);
    return 0;
}

void swap(int input[], size_t i, size_t j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

bool is_out_of_order(int left, int right, bool descending) {
    if (descending) {
        return left < right;
    }
    return left > right;
}

void sort(int input[], size_t length, bool descending) {
    if (length < 2) return;

    for (size_t i = 0; i < length - 1; i++) {
        bool swapped = false;

        for (size_t j = 0; j < length - 1 - i; j++) {
            if (is_out_of_order(input[j], input[j + 1], descending)) {
                swap(input, j, j + 1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void print_list(int input[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
}

bool ask_descending() {
    char choice[16];
    while (true) {
        printf("Sort ascending (a) or descending (d)? ");
        if (scanf("%15s", choice) != 1) return false;
        if (choice[0] == 'a' || choice[0] == 'A') return false;
        if (choice[0] == 'd' || choice[0] == 'D') return true;
        printf("Error: Faulty input!\n");
    }
}
