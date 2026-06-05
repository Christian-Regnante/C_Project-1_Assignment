#include <stdio.h>

/**
 * add - adds two integers
 *
 * Return: sum of the 2 numbers
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * main: perform add operation on input
 *
 * Return: 0
 */
int main ()
{
	int a, b, result;
	printf("Enter two numbers to operate on: ");
	scanf("%d %d", &a, &b);
	
	result = add(a, b);

	printf("The sum of the 2 integers(%d & %d) you input is: %d\n", a, b, result);

	return (0);
}
