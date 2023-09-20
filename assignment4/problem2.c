#include <stdio.h>
int findGCD(int num1, int num2);

int main()
{
	int num1 = -1;

	while (num1 < 0)
	{
		printf("Enter the 1st positive number: \n");
		scanf("%d", &num1);

		if (num1 < 0)
		{
			printf("Number is not positive\n");
		}
	}

	int num2 = -1;

	while (num2 < 0)
	{
		printf("Enter the 2nd positive number: \n");
		scanf("%d", &num2);

		if (num2 < 0)
		{
			printf("Number is not positive\n");
		}
	}

	int gcd = findGCD(num1, num2);
	printf("GCD of %d and %d is %d\n",num1,num2,gcd);
}


int findGCD(int num1,int num2)
{
	if (num2 == 0)
	{
		return num1;
	}
	else
	{
		return findGCD(num2, (num1 % num2));
	}

}
