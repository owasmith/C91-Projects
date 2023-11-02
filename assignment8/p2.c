#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Enter the number of elements in the array: ");
	int length;
	scanf("%d", &length);


	//Create the array, using malloc to allocate memory
	int *array;
	array = (int *)malloc(length * sizeof(int));
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		printf("Enter element %d: ", i);
		scanf("%d", &array[i]);
		sum += array[i];
	}

	printf("The sum of the array is:  %d\n", sum);

	printf("Enter the amount of elements to add: ");
	int length2;
	scanf("%d", &length2);

	length += length2;

	array = (int *)realloc(array, length * sizeof(int));

	for (int i = length - length2; i < length; i++)
	{
		printf("Enter element %d: ", i);
		scanf("%d", &array[i]);
		sum += array[i];
	}

	printf("The sum of the array is: %d\n", sum);

	free(array);

	return 0;

}
