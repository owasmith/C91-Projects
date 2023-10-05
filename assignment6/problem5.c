#include <stdio.h>

void printUniqueElements(int elements[], int lenArray);

int main()
{
	int size = 0;
	while (size < 1)
	{
		printf("Please input the size of the array: ");
		scanf("%d", &size);

		if (size < 1)
		{
			printf("Please make sure the array is non-negative and larger than 0\n");
		}
	}

	int numArray[size];

	for (int i = 0; i < size; i++)
	{
		int input;
		printf("Enter a value for the element: ");
		scanf("%d", &input);
		numArray[i] = input;

	}

	int tempArray[size];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (numArray[i] != numArray[i+1])
		{
			tempArray[j] = numArray[i];
			j++;
			
		}
	}
	for (int i = 0; i < j; i++)
	{
		numArray[i] = tempArray[i];
	}

	printUniqueElements(numArray, j);




}

void printUniqueElements(int elements[], int lenArray)
{
	for (int i = 0; i < lenArray;i++)
	{
		printf("%d ", elements[i]);
	}

}
