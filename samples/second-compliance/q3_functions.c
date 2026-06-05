/*
 * Question 3: Functions & Recursion
 * Program: Mathematical Utilities – Factorial, Fibonacci, Power
 * Demonstrates: multiple functions, recursion, function reuse,
 *               clear base cases
 */

#include <stdio.h>

/* -------------------------------------------------------
 * FUNCTION PROTOTYPES
 * ------------------------------------------------------- */
void printHeader(const char *title);
void printSeparator(void);

/* Recursive functions */
long factorialRecursive(int n);
long fibonacciRecursive(int n);

/* Iterative counterparts (for comparison / reuse) */
long factorialIterative(int n);
void printFibonacciSeries(int terms);

/* Utility used by multiple sections */
double powerOf(double base, int exponent);

/* -------------------------------------------------------
 * MAIN
 * ------------------------------------------------------- */
int main(void) {
    int n;

    printHeader("Mathematical Utilities Program");

    /* --- Factorial --- */
    printSeparator();
    printf("FACTORIAL (Recursive vs Iterative)\n");
    printSeparator();
    for (n = 0; n <= 10; n++) {
        printf("  %2d! = %10ld (recursive)   %10ld (iterative)\n",
               n,
               factorialRecursive(n),
               factorialIterative(n));
    }

    /* --- Fibonacci --- */
    printSeparator();
    printf("FIBONACCI SERIES (first 10 terms, recursive)\n");
    printSeparator();
    printFibonacciSeries(10);

    /* --- Power --- */
    printSeparator();
    printf("POWER FUNCTION (reused by other calculations)\n");
    printSeparator();
    printf("  2^10 = %.0f\n",  powerOf(2.0, 10));
    printf("  3^5  = %.0f\n",  powerOf(3.0, 5));
    printf("  1.5^4 = %.4f\n", powerOf(1.5, 4));

    printSeparator();
    return 0;
}

/* -------------------------------------------------------
 * UTILITY FUNCTIONS (reused throughout the program)
 * ------------------------------------------------------- */

void printHeader(const char *title) {
    printf("\n========================================\n");
    printf("  %s\n", title);
    printf("========================================\n\n");
}

void printSeparator(void) {
    printf("----------------------------------------\n");
}

/* -------------------------------------------------------
 * RECURSIVE FACTORIAL
 *   Base case : n == 0  ->  return 1
 *   Recursive : n! = n * (n-1)!
 * ------------------------------------------------------- */
long factorialRecursive(int n) {
    if (n < 0)  return -1;          /* error sentinel */
    if (n == 0) return 1;           /* BASE CASE */
    return (long)n * factorialRecursive(n - 1);  /* RECURSIVE CALL */
}

/* -------------------------------------------------------
 * ITERATIVE FACTORIAL (same result, no call stack growth)
 * ------------------------------------------------------- */
long factorialIterative(int n) {
    long result = 1;
    int i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/* -------------------------------------------------------
 * RECURSIVE FIBONACCI
 *   Base cases : n == 0 -> 0,  n == 1 -> 1
 *   Recursive  : fib(n) = fib(n-1) + fib(n-2)
 * ------------------------------------------------------- */
long fibonacciRecursive(int n) {
    if (n < 0)  return -1;
    if (n == 0) return 0;           /* BASE CASE 1 */
    if (n == 1) return 1;           /* BASE CASE 2 */
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2); /* RECURSIVE */
}

/* -------------------------------------------------------
 * PRINT FIBONACCI SERIES — reuses fibonacciRecursive()
 * ------------------------------------------------------- */
void printFibonacciSeries(int terms) {
    int i;
    printf("  ");
    for (i = 0; i < terms; i++) {
        printf("%ld", fibonacciRecursive(i));
        if (i < terms - 1) printf(", ");
    }
    printf("\n");
}

/* -------------------------------------------------------
 * POWER FUNCTION — reused by factorial display and elsewhere
 *   Iterative implementation (avoids <math.h> dependency)
 * ------------------------------------------------------- */
double powerOf(double base, int exponent) {
    double result = 1.0;
    int i;
    for (i = 0; i < exponent; i++) {
        result *= base;   /* function reuse: simple loop */
    }
    return result;
}
