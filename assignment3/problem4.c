#include <stdio.h>

int main()
{
	int inputNum = -1;

	while (inputNum < 0)
	{
		printf("Enter a number to find the reverse binary represenation: \n");
		scanf("%d", &inputNum);
		if (inputNum < 0)
		{
			printf("Invalid input, try again");
		}
	}


	if (inputNum == 0)
	{
		printf("0");

	}

	int binary = 0;
	int base = 1;

	while (inputNum > 0)
	{
		int remainder = inputNum  % 2;
		binary = binary + remainder * base;
		inputNum = inputNum / 2;
		base = base * 10;
	}

	printf("Binary represenation is %d\n", binary);

	int reversedNum = 0;
	int remainder2;

	while (binary >  0)
	{
		remainder2 = binary % 10;
		printf("%d",remainder2);
		binary /= 10;

	}



	return 0;
}
