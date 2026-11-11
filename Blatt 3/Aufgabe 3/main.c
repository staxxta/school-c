#include <stdio.h>
#include <stdbool.h>

double area_of_rectangle(double width, double height);

void process_input(bool *running);

void show_options();

double get_area();

int main() {
    printf("Welcome to my Calculator Program for Rectangles!\n");
    bool running = true;
    while (running) {
        process_input(&running);
    }
    return 0;
}

void show_options(){
    printf("Press Enter to Start!\n");
    printf("Press X to Stop!\n");
}


void process_input(bool *running) {
    show_options();
    char input = scanf("%s", &input);
    switch (input) {
        case '\n':
            printf("%lf", get_area());
            break;
        case 'X': case 'x':
            running = false;
            break;
        default:
            printf("Error: Faulty input!");
            break;
    }
}
double get_area() {
    double width;
    double height;
    printf("Enter your width: \n");
    scanf("%lf", &width);
    printf("Enter your height: \n");
    scanf("%lf", &height);
    double area = area_of_rectangle(width, height);
    return area;
}
double area_of_rectangle(double width, double height) {
    return width * height;
}
