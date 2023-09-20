#include <stdio.h>
int isPerfectNumber(int num);
int decision;

int main()
{
	int input = -1;

	while (input < 0)
	{
		printf("Please input a number to check if it's a perfect number: \n");
		scanf("%d", &input);

		if (input < 0)
		{
			printf("Number must be positive");
		}
	}

	isPerfectNumber(input);

	if (decision == 1)
	{
		printf("%d is a perfect num\n", input);
	}
	else
	{
		printf("%d is not a perfect num\n", input);

	}

	

}

int isPerfectNumber(int num)
{
	int sum = 1;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
			if (i != num / i)
			{
				sum += num /i;
			}
		}
	}

	if( sum == num)
	{
		decision = 1;
	}
}
