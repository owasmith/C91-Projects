#include <stdio.h>

int bitwise_multiply(int a, int b);

int main()
{
	printf("Enter the first number: ");
	int input1;
	scanf("%d", &input1);

	printf("Enter the second number: ");
	int input2;
	scanf("%d", &input2);

	int result;
	result = bitwise_multiply(input1, input2);

	printf("Result: %d\n", result);
}

int bitwise_multiply(int a, int b)
{
	int product = 0;

	while (b != 0) //Iterates through b. b will be dividedd by two in the right shift
	{
		if ((b % 2) != 0) //Checks if b is odd, if it is then it will add a to the product.
		{
			product = product + a;
		}

		a = a << 1; //Left shifts a, multiplies by two, continues multiplying until product is given
		b = b >> 1; //Right shifts a, divides by two
	}


	return product;
}
