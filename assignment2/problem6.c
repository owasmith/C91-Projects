#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("Input a: ");
	scanf("%d", &a);
	printf("Input b: ");
	scanf("%d", &b);

	int sum = a + b;
	int diff = a - b;
	int product = a * b;
	float  div = (float) a/b;
	int remainder = a%b;

	printf("The sum of %d and %d is %d\n",a,b,sum);
	printf("The difference of %d and %d is %d\n", a,b,diff);
	printf("The product of %d and %d is %d\n", a,b,product);
	printf("The division of %d and %d is %.2f\n", a,b,div);
	printf("The remainder of %d and %d is %d\n", a,b,remainder);
			

	return 0;

}
