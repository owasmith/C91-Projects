#include <stdio.h>
int sortAscending(int array[], size_t length);
int sortDescending(int array[], size_t length);
void printArray(int array[], size_t length);

int main()
{
	int array[10];
	printf("Please enter 10 inputs for the array\n");
	int input;
	for (size_t i = 0; i < (sizeof(array)/sizeof(int));i++)
	{
		scanf("%d", &input);
		array[i] = input;
	}

	printf("Unsorted Array: \n");
	for (size_t i = 0; i < sizeof(array)/sizeof(int) ; i++)
	{
		printf("%d ", array[i]);

	}

	printf("\nArray Sorted in Ascending Order: ");
	sortAscending(array,10);

	

	printf("\nArray Sorted in Descending Order: ");
	sortDescending(array,10);

}

int sortAscending(int array[], size_t length)
{
	int minIndex;
	int store;

	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (array[j+1] < array[j])
			{
				store = array[j];
				array[j] = array[j+1];
				array[j+1] = store;

			}
		}
		
	}
	printArray(array, length);

}

int sortDescending(int array[], size_t length)
{
	int store;

	for (size_t i = 0; i<length - 1; i++)
	{
		for (size_t j = 0; j< length - i -1; j++)
		{
			if (array[j+1] > array[j])
			{
				store = array[j];
				array[j] = array[j+1];
				array[j+1] = store;


			}
		}
	}
	printArray(array,length);
}

void printArray(int array[], size_t length)
{
	for (size_t i = 0; i< length; i++)
	{
		printf("%d ", array[i]);
	}


}
