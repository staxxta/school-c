#include <stdio.h>
#include <stdbool.h>
//Ohm's Law Calculator

double calculateVoltage(double resistance, double current);

double calculateResistance(double current, double voltage);

double calculateCurrent (double voltage, double resistance);

void showOptions();

int main() {
    printf("Welcome to my OHMS LAW CALCULATOR!\n");
    bool running = true;
    while(running) {
        int choice;
        double values[2];
        showOptions();
        scanf("%d", &choice);
        switch (choice) {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                running = false;
                break;
            default:
                printf("ERROR: False Input\n");
        }
    }
    return 0;
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
