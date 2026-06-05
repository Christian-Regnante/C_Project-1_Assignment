#include <stdio.h>
#include <stdbool.h>

/*
 * Question 2: C Program Lifecycle and Compilation
 * Program: Student Grading Program
 */

int main()
{
    int choice;
    char assignmentNames[50][100];
    float grades[50];

    bool checkGrades = false;
    bool condition = true;

    int assignmentCount = 0;

    printf("\n===== MENU-DRIVEN STUDENT GRADING PROGRAM =====\n");

    while (condition)
    {
        printf(
            "\n1. Enter Assignments\n"
            "2. Enter Grades\n"
            "3. Check Report\n"
            "4. Exit Program\n"
            "\nChoose an option: "
        );

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("\n===== Registering Assignments =====\n");

                printf("How many assignments do you want to register? ");
                scanf("%d", &assignmentCount);

                if (assignmentCount <= 0 || assignmentCount > 50)
                {
                    printf("Invalid number of assignments!\n");
                    assignmentCount = 0;
                    break;
                }

                for (int i = 0; i < assignmentCount; i++)
                {
                    printf("Enter Assignment %d Name(No Spaces!): ", i + 1);
                    scanf("%99s", assignmentNames[i]);
                }

                printf("\nAssignments Registered Successfully!\n");

                checkGrades = false;

                break;
            }

            case 2:
            {
                if (assignmentCount == 0)
                {
                    printf("\nPlease register assignments first!\n");
                    continue;
                }

                printf("\n===== Enter Grades =====\n");

                for (int i = 0; i < assignmentCount; i++)
                {
                    printf("Enter grade for %s (0-100): ",
                           assignmentNames[i]);

                    scanf("%f", &grades[i]);

                    if (grades[i] < 0 || grades[i] > 100)
                    {
                        printf("Invalid grade! Please try again.\n");
                        i--;
                        continue;
                    }
                }

                checkGrades = true;

                printf("\nGrades Recorded Successfully!\n");

                break;
            }

            case 3:
            {
                if (!checkGrades)
                {
                    printf("\nPlease enter assignments and grades first!\n");
                    continue;
                }

                printf("\n===== STUDENT REPORT =====\n");

                printf("\nA = 80 - 100\n");
                printf("B = 70 - 79\n");
                printf("C = 60 - 69\n");
                printf("D = 50 - 59\n");
                printf("F = Below 50\n");

                float total = 0;

                for (int i = 0; i < assignmentCount; i++)
                {
                    char letterGrade;

                    if (grades[i] >= 80)
                        letterGrade = 'A';
                    else if (grades[i] >= 70)
                        letterGrade = 'B';
                    else if (grades[i] >= 60)
                        letterGrade = 'C';
                    else if (grades[i] >= 50)
                        letterGrade = 'D';
                    else
                        letterGrade = 'F';

                    printf(
                        "\nAssignment: %s"
                        "\nGrade: %.2f"
                        "\nLetter Grade: %c\n",
                        assignmentNames[i],
                        grades[i],
                        letterGrade
                    );

                    total += grades[i];
                }

                float average = total / assignmentCount;

                printf("\n==============================");
                printf("\nAverage Grade: %.2f", average);

                if (average >= 50)
                    printf("\nStatus: PASS");
                else
                    printf("\nStatus: FAIL");

                printf("\n==============================\n");

                break;
            }

            case 4:
            {
                printf("\nExiting Program...\n");
                condition = false;
                break;
            }

            default:
            {
                printf("\nInvalid Choice! Try Again.\n");
                break;
            }
        }
    }

    return 0;
}
