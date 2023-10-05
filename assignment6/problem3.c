#include <stdio.h>

void swap_grades(int *grade1, int *grade2);
//Using pointers is more efficient than copying the values into new variables because you are using the direct memory where the values are stored, and dont need to use extra memory for temp variables. This is especially important when using data structures that are really large. Furthermore, it can help save execution time
int main()
{
	int grades[3];

	for (size_t i = 0; i < 3; i++)
	{
		int input;
		printf("Please enter the grade: \n");
		scanf("%d", &input);
		grades[i] = input;
	}

	printf("Grades list before swap: ");

	for (size_t i = 0; i < 3; i++)
	{
		printf("%d ", grades[i]);
	}

	printf("\nGrades list after swap: ");
	swap_grades(&grades[0],&grades[2]);

	for (size_t i = 0; i < 3; i++)
	{
		printf("%d ", grades[i]);
	}
}

void swap_grades(int *grade1, int *grade2)
{
	*grade1 += *grade2;
	*grade2 = *grade1 - *grade2;
	*grade1 = *grade1 - *grade2;

}
