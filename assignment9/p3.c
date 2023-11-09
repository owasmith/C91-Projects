#include <stdio.h>
#include <string.h>

typedef struct{
	int num;
	char streetName[100];
	char streetType[100];
} Address;

typedef struct{
	char stud_name[100];
	Address address;
} Student;

void sortStudents(Student students[], int n);


int main()
{
	printf("/*How many student records do you want to enter?*/\n");

	printf("Enter limit: ");
	int n;
	scanf("%d", &n);
	Student students[n];

	for (int i = 0; i < n; i++)
	{
		printf("Enter Student-%d Details\n", i+1);
		printf("--------------------\n");
		printf("Enter name  : ");
		scanf("%99s", students[i].stud_name);

		printf("Address\n");
		printf("Number      : ");
		scanf("%d", &students[i].address.num);

		printf("Street Name : ");
		scanf("%99s", students[i].address.streetName);

		printf("Street Type : ");
		scanf("%99s", students[i].address.streetType);
		printf("\n");
	}


	printf("     Data before arrangement     \n");
	printf("---------------------------------\n");
	printf("Student Name     Address\n");
	printf("---------------------------------\n");

	for (int i = 0; i < n; i++)
	{
		printf("%-15s %-10d %-10s %-10s\n", students[i].stud_name, students[i].address.num, students[i].address.streetName, students[i].address.streetType);
	}

	sortStudents(students, n);

	printf("     Data after arrangement    \n ");
	printf("--------------------------------\n");
	printf("Student Name     Address\n");
	printf("--------------------------------\n");


	for (int i = 0; i < n; i++)
	{
		printf("%-15s %-10d %-10s %-10s\n", students[i].stud_name, students[i].address.num, students[i].address.streetName, students[i].address.streetType);
	}

	

}

void sortStudents(Student students[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n- i - 1; j++)
		{
			if (strcmp(students[j].stud_name, students[j+1].stud_name) > 0)
			{
				Student tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
			}
		}
	}

}
