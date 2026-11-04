#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//Ohm's Law Calculator

double calculateVoltage(double resistance, double current);

double calculateResistance(double current, double voltage);

double calculateCurrent (double voltage, double resistance);

void showOptions();

char *read_line();

char return_last_char(char *input[]);

int main() {
    char validUnits[] = {'U', 'u', 'R', 'r', 'V', 'v'};
    printf("Welcome to my OHMS LAW CALCULATOR!\n");
    float resistance;
    float voltage;
    float current;
    char *text = read_line();
    return 0;
}

char return_last_char(char *input[]) {
    if (input == NULL || input[0] == NULL) return '\0';

    int i = 0;
    while (input[i + 1] != NULL) {
        i++;
    }

    size_t len = strlen(input[i]);

    if (len == 0) {
        return '\0';
    }
    return input[i][len - 1];
}

char *read_line() {
    size_t capacity = 16;
    size_t length = 0;
    char *buffer = malloc(capacity);
    if (buffer == NULL) return NULL;

    int character;
    while ((character = getchar()) != EOF && character != '\n' ) {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *bigger = realloc(buffer, capacity);
            if (bigger == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = bigger;
        }
        buffer[length++] = (char) character;
    }
    buffer[length] = '\0';
    return buffer;
}


void showOptions() {
    printf("Enter 1 to Calculate for Voltage (V)\n");
    printf("Enter 2 to Calculate for Resistance (R)\n");
    printf("Enter 3 to Calculate for Current (I)\n");
    printf("Enter 4 to Exit\n");
}

double calculateVoltage(double resistance, double current) {
    return current * resistance;
}

double calculateResistance(double current, double voltage) {
    if (current == 0.0) {
        printf("Undefined!");
        return 0;
    } else {
        return voltage / current;
    }
}

double calculateCurrent (double voltage, double resistance) {
    if (resistance == 0.0) {
        printf("Undefined!");
        return 0;
    } else {
        return voltage / resistance;
    }
}
