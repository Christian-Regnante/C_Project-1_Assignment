/*
 * Question 2: Control Flow & Repetition
 * Program: Student Grade Management System
 * Demonstrates: data types, if/switch, loops, break/continue,
 *               repeated execution until user exits
 */

#include <stdio.h>

/* Constants */
#define MAX_STUDENTS 10

/* Function prototypes */
void displayMenu(void);
void addGrade(float grades[], int *count);
void viewGrades(const float grades[], int count);
float computeAverage(const float grades[], int count);
char getLetterGrade(float score);
void clearInputBuffer(void);

int main(void) {
    float grades[MAX_STUDENTS];
    int count = 0;
    int choice;
    int running = 1;

    printf("========================================\n");
    printf("   Student Grade Management System\n");
    printf("========================================\n");

    while (running) {
        displayMenu();
        printf("Enter your choice: ");

        /* Validate integer input */
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("[!] Invalid input. Please enter a number.\n\n");
            continue;   /* <-- continue: skip rest of loop body, re-show menu */
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addGrade(grades, &count);
                break;

            case 2:
                viewGrades(grades, count);
                break;

            case 3:
                if (count == 0) {
                    printf("[!] No grades entered yet.\n\n");
                } else {
                    printf("\n  Class Average : %.2f (%c)\n\n",
                           computeAverage(grades, count),
                           getLetterGrade(computeAverage(grades, count)));
                }
                break;

            case 4:
                printf("\nGoodbye! Exiting the program.\n");
                running = 0;   /* will exit while loop naturally */
                break;         /* <-- break: exit switch block */

            default:
                printf("[!] Invalid choice. Please select 1-4.\n\n");
                break;
        }
    }

    return 0;
}

/* Display the main menu */
void displayMenu(void) {
    printf("----------------------------------------\n");
    printf("  1. Add a student grade\n");
    printf("  2. View all grades\n");
    printf("  3. Compute class average\n");
    printf("  4. Exit\n");
    printf("----------------------------------------\n");
}

/* Add a grade to the array */
void addGrade(float grades[], int *count) {
    float score;

    if (*count >= MAX_STUDENTS) {
        printf("[!] Maximum capacity reached (%d students).\n\n", MAX_STUDENTS);
        return;
    }

    printf("Enter score (0 - 100): ");
    if (scanf("%f", &score) != 1 || score < 0 || score > 100) {
        clearInputBuffer();
        printf("[!] Invalid score. Must be between 0 and 100.\n\n");
        return;
    }
    clearInputBuffer();

    grades[*count] = score;
    (*count)++;
    printf("[+] Grade %.2f added. Total students: %d\n\n", score, *count);
}

/* Display all stored grades */
void viewGrades(const float grades[], int count) {
    int i;

    if (count == 0) {
        printf("[!] No grades to display.\n\n");
        return;
    }

    printf("\n  No.  Score  Grade\n");
    printf("  ---  -----  -----\n");

    for (i = 0; i < count; i++) {
        /* Use continue to skip any invalid entry (defensive check) */
        if (grades[i] < 0) {
            continue;   /* <-- continue skips printing this entry */
        }
        printf("  %3d  %5.1f    %c\n", i + 1, grades[i],
               getLetterGrade(grades[i]));
    }
    printf("\n");
}

/* Calculate average of grades */
float computeAverage(const float grades[], int count) {
    float sum = 0.0f;
    int i;
    for (i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (count > 0) ? (sum / count) : 0.0f;
}

/* Map a numeric score to a letter grade */
char getLetterGrade(float score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else                  return 'F';
}

/* Flush leftover characters from stdin */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
