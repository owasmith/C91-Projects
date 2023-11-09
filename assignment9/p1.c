#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Please enter the length (in meters): ");
	float length;
	scanf("%f", &length);

	printf("Please enter the width (in meters): ");
	float width;
	scanf("%f", &width);

	float totalMeters = length * width;

	float *array;
	//array is used to store the amount of waste in each square meter
	
	array = (float *)calloc(totalMeters, sizeof(float));

	printf("Enter the amount of plastic waste found in each square meter: \n");
	for (int i = 0; i < totalMeters; i++)
	{
		printf("Square meter %d: ", i+1);
		scanf("%f", &array[i]);
	}

	int totalWaste;
	for (int i = 0; i < totalMeters; i++)
	{
		totalWaste += array[i];
		
	}

	float average = totalWaste/totalMeters;
	printf("The average amount of plastic waster per sq meter is: %.2f\n", average);

	free(array);
}
