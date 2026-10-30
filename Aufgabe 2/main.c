#include <stdio.h>
#include <stdbool.h>
// This is a Program for USD to EUR conversion and vice versa

void eur_to_usd();

void usd_to_eur();

void showOptions();

int main() {
    bool running = true;
    int currentChoice;
    printf("Hello and Welcome to my Program for EUR/USD conversion\n");
    while (running) {
        showOptions();
        scanf("%d", &currentChoice);
        switch (currentChoice) {
            case 1:
                eur_to_usd();
                break;
            case 2:
                usd_to_eur();
                break;
            case 3:
                return 0;
                break;
            default:
                printf("ERROR: Invalid Entry, please try again or press '3' to exit\n");
        }
    }
}



void showOptions() {
    printf("Please select the option you want below: \n");
    printf("Press 1 for converting from EUR to USD\n");
    printf("Press 2 for converting from USD to EUR\n");
    printf("Press 3 to exit\n");
}

void eur_to_usd() {
    double value;
    printf("Enter your EURO Value:\n");
    scanf("%lf", &value);
    if (value == 0.0) {
        printf("%.2f USD", value);
    } else {
        double usdValue = value * 1.34;
        printf("%.2f USD", usdValue);
    }
}

void usd_to_eur() {
    double value;
    printf("Enter your USD Value:\n");
    scanf("%lf", &value);
    if (value == 0.0) {
        printf("%.2f USD", value);
    } else {
        double eurValue = value / 1.34;
        printf("%.2f EUR", eurValue);
    }
}
