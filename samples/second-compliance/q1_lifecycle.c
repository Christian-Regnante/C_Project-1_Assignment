/*
 * Question 1: C Program Lifecycle and Compilation
 * Program: Circle Area and Circumference Calculator
 * Demonstrates: formatted output, math operations, preprocessor macros
 */

#include <stdio.h>
#include <math.h>   /* for M_PI */

/* Preprocessor macro — replaced during preprocessing stage */
#define APP_VERSION "1.0"

/* Function prototype — declared before main */
double calculateArea(double radius);
double calculateCircumference(double radius);
void printSeparator(void);

int main(void) {
    double radius;
    double area;
    double circumference;

    printf("==============================\n");
    printf("  Circle Calculator v%s\n", APP_VERSION);
    printf("==============================\n\n");

    printf("Enter the radius of the circle: ");
    if (scanf("%lf", &radius) != 1 || radius <= 0) {
        fprintf(stderr, "Error: Please enter a positive number.\n");
        return 1;
    }

    area = calculateArea(radius);
    circumference = calculateCircumference(radius);

    printSeparator();
    printf("  Radius        : %10.4f units\n", radius);
    printf("  Area          : %10.4f sq. units\n", area);
    printf("  Circumference : %10.4f units\n", circumference);
    printSeparator();

    return 0;
}

/* Calculate area of circle: A = pi * r^2 */
double calculateArea(double radius) {
    return M_PI * radius * radius;
}

/* Calculate circumference: C = 2 * pi * r */
double calculateCircumference(double radius) {
    return 2.0 * M_PI * radius;
}

/* Print a visual separator line */
void printSeparator(void) {
    printf("------------------------------\n");
}
