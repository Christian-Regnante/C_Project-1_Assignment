# include <stdio.h>

/*
 * Question 1: C Program Lifecycle and Compilation
 * Program: Rectangle Area calculator
 */

int main()
{
    float length;
    float width;
    float area;
    printf("_____ Rectangle Area Calculator Program _____\n\n");

    printf("Please enter length and width number to calculate the Area: \n");
    scanf("%f%f", &length, &width);

    area = length * width;

    printf("\nThe Answer:\n");
    printf("The Area with the length of %.2f and width of %.2f is -- %.2f --\n", length, width, area);

    return 0;
}
