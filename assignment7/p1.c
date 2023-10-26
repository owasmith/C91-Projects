#include <stdio.h>
int* find_max(int *arr, int size);
int* find_min(int *arr, int size);
int find_difference(int *arr, int size);

int main()
{
	int array[10];
	printf("Please enter 10 values for the array:\n");
	for (size_t i = 0; i < 10; i++)
	{
		int input;
		scanf("%d", &input);
		array[i] = input;
	}

	printf("The array you entered is: ");
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}

	int* max = find_max(array, 10);
	printf("\nThe maximum is: %d\n", *max);

	int* min = find_min(array, 10);
	printf("The minimum is: %d\n", *min);

	int difference = find_difference(array, 10);
	printf("The difference is: %d\n", difference);



}

int* find_max(int *arr, int size)
{
	int *max = &arr[0];

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > *max)
		{
			max = &arr[i];
		}

	}

	return max;

}

int* find_min(int *arr, int size)
{
	int *min = &arr[0];

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < *min)
		{
			min = &arr[i];
		}
	}
	return min;
}

int find_difference(int *arr, int size)
{
	int diff;
	int *maxtmp = find_max(arr, size);
	int *mintmp = find_min(arr, size);

	int max = *maxtmp;
	int min = *mintmp;

	diff = max - min;
	return diff;

}
