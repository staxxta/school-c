#include <stdio.h>
#include <stdbool.h>

#define MIN_HEIGHT 3
#define MAX_HEIGHT 40

void showOptions();

int readHeight();

void printSpaces(int count);

void printStar(int height);

void printLeaf(int row, int column);

void printTree(int height);

void printTrunk(int height);

void printGround(int height);

int main() {
    bool running = true;
    int currentChoice;
    printf("Welcome to my CHRISTMAS TREE GENERATOR!\n");
    while (running) {
        showOptions();
        if (scanf("%d", &currentChoice) != 1) {
            while (getchar() != '\n');
            currentChoice = 0;
        }
        switch (currentChoice) {
            case 1: {
                int height = readHeight();
                if (height != 0) {
                    printf("\n");
                    printStar(height);
                    printTree(height);
                    printTrunk(height);
                    printGround(height);
                    printf("\n");
                }
                break;
            }
            case 2:
                running = false;
                break;
            default:
                printf("ERROR: Invalid Entry, please try again or press '2' to exit\n");
        }
    }
    return 0;
}

void showOptions() {
    printf("Please select the option you want below: \n");
    printf("Press 1 to generate a christmas tree\n");
    printf("Press 2 to exit\n");
}

int readHeight() {
    int height;
    printf("Enter the height of your tree (%d - %d):\n", MIN_HEIGHT, MAX_HEIGHT);
    if (scanf("%d", &height) != 1) {
        while (getchar() != '\n');
        printf("ERROR: Not a number\n");
        return 0;
    }
    if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
        printf("ERROR: Height must be between %d and %d\n", MIN_HEIGHT, MAX_HEIGHT);
        return 0;
    }
    return height;
}

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printStar(int height) {
    printSpaces(height);
    printf("*\n");
}

void printLeaf(int row, int column) {
    if ((row + column) % 4 == 0) {
        printf("o");
    } else if (row % 3 == 2 && column % 4 == 2) {
        printf("i");
    } else {
        printf("^");
    }
}

void printTree(int height) {
    for (int row = 0; row < height; row++) {
        printSpaces(height - row - 1);
        printf("/");
        for (int column = 0; column < 2 * row + 1; column++) {
            printLeaf(row, column);
        }
        printf("\\\n");
    }
}

void printTrunk(int height) {
    int trunkWidth = height / 4 * 2 + 1;
    int trunkHeight = height / 5 + 1;
    for (int row = 0; row < trunkHeight; row++) {
        printSpaces(height - trunkWidth / 2);
        for (int column = 0; column < trunkWidth; column++) {
            printf("#");
        }
        printf("\n");
    }
}

void printGround(int height) {
    for (int i = 0; i < 2 * height + 1; i++) {
        printf("~");
    }
    printf("\n");
}
