#include <stdio.h>

#define TABLE_SIZE 10
#define COLUMN_WIDTH 4

void printHeader();

void printSeparator();

void printRow(int factor);

int main() {
    printf("Welcome to my MULTIPLICATION TABLE!\n\n");
    printHeader();
    printSeparator();
    for (int row = 1; row <= TABLE_SIZE; row++) {
        printRow(row);
    }
    return 0;
}

void printHeader() {
    printf("%*s |", COLUMN_WIDTH, "*");
    for (int column = 1; column <= TABLE_SIZE; column++) {
        printf("%*d", COLUMN_WIDTH, column);
    }
    printf("\n");
}

void printSeparator() {
    for (int i = 0; i < COLUMN_WIDTH; i++) {
        printf("-");
    }
    printf("-+");
    for (int i = 0; i < TABLE_SIZE * COLUMN_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

void printRow(int factor) {
    printf("%*d |", COLUMN_WIDTH, factor);
    for (int column = 1; column <= TABLE_SIZE; column++) {
        printf("%*d", COLUMN_WIDTH, factor * column);
    }
    printf("\n");
}
