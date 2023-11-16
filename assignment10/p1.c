#include <stdio.h>

int main()
{
	printf("Enter an integer: ");
	int input;
	scanf("%d", &input);

	int count = 0;
	int tmp = input;

	while (tmp)
	{
		count += tmp & 1;
		tmp >>= 1;
	}

	printf("The number of bits set to 1 in the binary representation of %d is %d\n", input, count);
	printf("The binary representation of %d is ", input);

	for (int i = 7; i >= 0; i--)
	{
		printf("%d", (input >> i) & 1);
		if (i == 0)
		{
			printf("\n");
		}
	}

}
