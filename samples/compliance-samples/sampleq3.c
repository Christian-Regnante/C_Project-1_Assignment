#include <stdio.h>

/**
 * factorial - calculates factorial of n recursively
 * @n: the number to compute factorial for
 *
 * Return: factorial of n
 */
long factorial(int n)
{
	if (n == 0 || n == 1)
		return (1);
	return (n * factorial(n - 1));
}

/**
 * get_valid_input - prompts user and validates input is non-negative
 * @prompt: message to display to user
 *
 * Return: valid non-negative integer from user
 */
int validate_input(int value)
{
	if (value < 0)
	{
		printf("Please enter a positive number!: ");
		scanf("%d", &value);
		return (validate_input(value));
	}
	return (value);
}

/**
 * display_factorial - prints the result of factorial calculation
 * @n: the input number
 * @fact: the factorial result
 *
 * Return: void
 */
void display_factorial(int n, long fact)
{
	printf("Factorial of %d: %ld\n", n, fact);
}

/**
 * main - entry point, drives the program
 *
 * Return: 0
 */
int main(void)
{
	int number;
	long fact;
	int flag;

	do {
		printf("Enter a positive number: ");
		scanf("%d", &number);
		number = validate_input(number);
		fact = factorial(number);
		display_factorial(number, fact);

		printf("\nCalculate again? (1 = yes, 0 = no): ");
		scanf("%d", &flag);
	} while (flag == 1);

	printf("Goodbye!\n");
	return (0);
}
