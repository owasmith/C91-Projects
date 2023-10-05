#include <stdio.h>

int main()
{
	int studentDatabase[5][4] = {
		{1111, 13, 9, 90},
		{1222, 14, 9, 65},
		{2222, 15, 10, 85},
		{3333, 16, 11, 82},
		{4444, 18, 12, 75},
	};

	printf("Enter the minumum age of students to filter (-1 to ignore): ");
	int minAge;
	scanf("%d", &minAge);

	printf("Enter the minimum year of students to filter (-1 to ignore): ");
	int minYear;
	scanf("%d", &minYear);

	printf("Enter the minumum grade of students to filter (-1 to ignore): ");
	int minGrade;
	scanf("%d", &minGrade);

	for (size_t i = 0; i < 5; i++)
	{
		int studentID = studentDatabase[i][0];
		int year = studentDatabase[i][2];
		int age = studentDatabase[i][1];
		int grade = studentDatabase[i][3];

		if ((minYear == -1 || year >=  minYear) && (minAge == -1 || age >=  minAge) && (minGrade == -1 || grade >= minGrade))
		{
			printf("Matching student ID found: %d\n", studentID);
		}
	}


}
