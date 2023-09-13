#include <stdio.h>

int main()
{
	int startingNum = -1;

	while (startingNum < 1)
	{
		printf("Please input a starting integer: \n");
		scanf("%d", &startingNum);

		if (startingNum < 1)
		{
			printf("Number must be more than 0");
		}

	}

	for (int i = startingNum; i > 0; i--)
	{
		if ((i % 3 == 0) &&( i % 5 ==0))
		{
			printf("Fizz-Buzz ");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz ");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz ");
		}
		else
		{
			printf("%d\n",i);
		}
	}
}
