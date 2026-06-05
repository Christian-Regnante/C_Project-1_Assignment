#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Question 1: C Program Lifecycle and Compilation
 * Program: Multiple Function Programs
 */

/* FUNCTION PROTOTYPES */
void calculatorProgram();
void guessingGame();
void factorialProgram();
int factorial(int n);

/* MAIN FUNCTION */
int main()
{
    int choice;
    bool running = true;

    printf("_____ MULTI APP FUNCTION PROGRAMS _____\n");

    while(running)
    {
        printf("\n----- MAIN MENU -----\n");
        printf("1. Calculator Program\n");
        printf("2. Guessing Game\n");
        printf("3. Factorial Program\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                calculatorProgram();
                break;

            case 2:
                guessingGame();
                break;

            case 3:
                factorialProgram();
                break;

            case 4:
                printf("Goodbye!\n");
                running = false;
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* CALCULATOR FUNCTION */

void calculatorProgram()
{
    float num1, num2;
    char op;

    printf("\n----- CALCULATOR -----\n");

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(op)
    {
        case '+':
            printf("Result = %.2f\n", num1 + num2);
            break;

        case '-':
            printf("Result = %.2f\n", num1 - num2);
            break;

        case '*':
            printf("Result = %.2f\n", num1 * num2);
            break;

        case '/':
            if(num2 == 0)
                printf("Cannot divide by zero!\n");
            else
                printf("Result = %.2f\n", num1 / num2);
            break;

        default:
            printf("Invalid operator!\n");
    }
}

/* GUESSING GAME FUNCTION */

void guessingGame()
{
    int numbers[5] = {3, 7, 12, 18, 25};
    int correctIndex = 2;   /* Correct answer is 12 */

    int guess;
    int lives = 3;

    printf("\n----- GUESSING GAME -----\n");

    printf("Choose the correct number from:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    while(lives > 0)
    {
        printf("\nLives Remaining: %d\n", lives);

        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess == numbers[correctIndex])
        {
            printf("Congratulations! You guessed correctly.\n");

            printf("Factorial of %d is %d\n",
                   guess,
                   factorial(guess));

            return;
        }

        lives--;

        if(lives > 0)
        {
            printf("Wrong guess! Try again.\n");
            continue;
        }
    }

    printf("\nGame Over!\n");
    printf("Correct answer was %d\n",
           numbers[correctIndex]);
}

/* FACTORIAL PROGRAM FUNCTION */

void factorialProgram()
{
    int number;

    printf("\n----- FACTORIAL PROGRAM -----\n");

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if(number < 0)
    {
        printf("Factorial is not defined for negatives.\n");
        return;
    }

    printf("Factorial of %d = %d\n",
           number,
           factorial(number));
}

/* FACTORIAL RECURSIVE FUNCTION */

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}
