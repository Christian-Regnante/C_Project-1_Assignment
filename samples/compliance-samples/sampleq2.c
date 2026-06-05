#include <stdio.h>
#include <stdbool.h>

int main () {
	int num1;
	int num2;
	int choice;
	bool flag = true;

	do {
		printf("\n---- Menu for calculator ----\n");
		printf("1. Add\n");
		printf("2. Subtract\n");
		printf("3. Multiply\n");
		printf("4. Divide\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		if (choice == 0)
		{
			printf("Exiting calculator...\n");
			flag = false;
			continue;
		}

		printf("Enter two numbers: ");
		scanf("%d %d", &num1, &num2);

		switch (choice) {
			case 1:
				printf("%d\n", num1 + num2);
				break;
			case 2:
				printf("%d\n", num1 - num2);
				break;
			case 3:
				printf("%d\n", num1 * num2);
				break;
			case 4:
				if (num2 == 0)
				{
					printf("Oops! Cannot divide by zero.\n");
					continue;
				}
				printf("%d\n", num1 / num2);
				break;
			default:
				printf("Error! Invalid choice chosen.\n");		 
		}
	}
	while (flag);
	
	return (0);
}

