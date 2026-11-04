#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//Ohm's Law Calculator

double calculateVoltage(double resistance, double current);

double calculateResistance(double current, double voltage);

double calculateCurrent (double voltage, double resistance);

void showOptions();

char *read_line();

char return_last_char(char *input[]);

void processInput(char *input[], float *resistance, float *voltage, float *current);

int main() {
    char validUnits[] = {'U', 'u', 'R', 'r', 'V', 'v'};
    printf("Welcome to my OHMS LAW CALCULATOR!\n");
    showOptions();
    float resistance, voltage, current;
    char *text = read_line();
    if (text == NULL) return 1;
    char *lines[] = {text, NULL};
    processInput(lines, &resistance, &voltage, &current);

    if (isnan(voltage)) {
        printf("U = %g V\n", calculateVoltage(resistance, current));
    } else if (isnan(current)) {
        printf("I = %g A\n", calculateCurrent(voltage, resistance));
    } else if (isnan(resistance)) {
        printf("R = %g Ohm\n", calculateResistance(current, voltage));
    } else {
        printf("All three values given, nothing to calculate.\n");
    }

    free(text);
    return 0;
}

void processInput(char *input[], float *resistance, float *voltage, float *current) {
    *resistance = NAN;
    *voltage = NAN;
    *current = NAN;

    if (input == NULL) return;
    //Parse the input for a semi colon
    for (size_t i = 0; input[i] != NULL; i++) {
        char *part = strtok(input[i], ";");

        while (part != NULL) {
            char *end;
            float value = strtof(part, &end);
            if (end == part) {
                printf("Could not the number in \"%s\"\n", part);
            } else {
                while (isspace((unsigned char) *end)) end++;

                switch (*end) {
                    case 'V': case 'v':
                    case 'U': case 'u':
                        *voltage = value;
                        break;
                    case 'I': case 'i':
                    case 'A': case 'a':
                        *current = value;
                        break;
                    case 'R': case 'r':
                        *resistance = value;
                        break;
                    case '\0':
                        printf("Missing unit after %g\n", value);
                        break;
                    default:
                        printf("Unknown unit '%c' in \"%s\"\n", *end, part);
                }
            }
            part = strtok(NULL, ";");
        }
    }
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
    printf("Enter your values with a semicolon to seperate (e.g.: 2V; 3I)\n");
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
