#include <stdio.h>

int calculate(int array[], int firstIndice, int secondIndice, char operator);

int main()
{
	int firstIndice = -1;
	int secondIndice = -1;
	int array[1];
	printf("Enter 10 values for the array: \n");

	for (size_t i = 0; i < 10; i++)
	{
		int input;
		scanf("%d", &input);
		array[i] = input;	
	}

	while (firstIndice < 0)
	{
		printf("Enter the first indice of the subArray: \n");
		scanf("%d", &firstIndice);
		if (firstIndice < 0)
		{
			printf("Not a valid input\n");
		}
	}

	while (secondIndice < firstIndice || secondIndice > 9)
	{
		printf("Enter the second indice of the subArray: \n");
		scanf("%d", &secondIndice);
		if (secondIndice < firstIndice || secondIndice > 9)
		{
			printf("Not a valid input, it should be higher than the first indice\n");
		}
	}

	char operator;

	printf("Please enter an operator: +, -, *, or /\n");

	while (1)
	{
		scanf(" %c", &operator);
		if (operator == '+' || operator == '-' || operator ==  '*' || operator == '/')
		{
			break;
		}
		else
		{
			printf("Error: please enter a valid operaton\n");
		}
	}

	int result = calculate(array,firstIndice,secondIndice,operator);
	printf("Result: %d\n", result);

}


int calculate(int array[], int firstIndice, int secondIndice, char operator)
{
	int newArray[secondIndice - firstIndice];

	for (size_t i = 0; i <= (size_t)(secondIndice - firstIndice); i++)
	{
		newArray[i] = array[firstIndice + i];
	}

	printf("New Array: \n");

	for (size_t i = 0; i <= sizeof(newArray) / sizeof(int); i++)
	{
		printf("%d\n", newArray[i]);
	}

	if (operator == '+')
	{
		int sum = 0;
		printf("Addition selected.\n");
		for (size_t i =0; i<=(sizeof(newArray)/sizeof(int));i++)
		{
			sum += newArray[i];
		}
		return sum;
	}
	else if (operator == '-')
	{
		int diff = newArray[0];
		printf("Subtraction selected. \n");
		for (size_t i = 1; i<=(sizeof(newArray)/sizeof(int));i++)
		{
			diff -= newArray[i];

		}
		return diff;
	}
	else if (operator == '*')
	{
		int multiply = 1;
		printf("Multiplication selected. \n");
		for (size_t i = 0; i<=(sizeof(newArray)/sizeof(int));i++)
		{
			multiply *= newArray[i];
		}
		return multiply;
	}
	else if (operator == '/')
	{
		if (newArray[0] == 0)
		{
			printf("Error: cannot divide by 0");
			return 0;
		}

		int divide = newArray[0];
		printf("Division selected. \n");
		for (size_t i = 0; i<=(sizeof(newArray)/sizeof(int));i++)
		{
			if (newArray[i] == 0)
			{
				printf("Error, cannot divide by 0");
				return 0;
			}
			divide /= newArray[i];
		}
		return divide;
	}


}
