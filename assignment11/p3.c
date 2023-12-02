#include <stdio.h>
#include <stdlib.h>

struct Student{
	char name[50];
	int id;
	float GPA;
};

struct Student *students = NULL;
int numStudents = 0;

void add_student();
void load_students(char *filename);
void list_students();
void save_students(char *filename);
void search_student();
void delete_student();

int main()
{
	int option = -1;

	students = (struct Student *)malloc(100 * sizeof(struct Student));

	load_students("students.txt");

	while (option == -1)
	{
		printf("Enter an option:\n");
		printf("0. Save student records to file and exit\n");
		printf("1. Add new student to file\n");
		printf("2. Search for existing student record from file\n");
		printf("3. Delete an existing student in file\n");
		printf("4. List all student records\n");
		printf("5. Save a copy of the student records to a file scanned from user\n");

		scanf("%d", &option);

		if (option > 5 || option < 0)
		{
			printf("Not a valid option\n");
			option = -1;
		}

		switch(option)
		{
			case 0:
				printf("Option 0 selected...\n");
				save_students("students.txt");
				free(students);
				exit(0);
			case 1: 
				printf("Option 1 selected...\n");
				add_student();
				option = -1;
				break;
				
			case 2:
				printf("Option 2 selected...\n");
				search_student();
				option = -1;
				break;
			case 3:
				printf("Option 3 selected...\n");
				delete_student();
				option = -1;
				break;
			case 4:
				printf("Option 4 selected...\n");
				list_students();
				option = -1;
				break;
			case 5:
				printf("Option 5 selected...\n");
				printf("Please enter the name of the file you'd like to save to: ");
				char copyName[50];
				scanf("%s", copyName);
				save_students(copyName);
				printf("Records sent saved to %s\n", copyName);
				option = -1;
				break;

		}
	}

}

void add_student()
{
	printf("Enter student name: ");
	scanf(" %s", students[numStudents].name);
	printf("Enter student ID: ");
	scanf(" %d", &students[numStudents].id);
	printf("Enter student GPA: ");
	scanf(" %f", &students[numStudents].GPA);

	numStudents++;

	printf("Successfully added student\n");
}

void load_students(char *filename)
{
	FILE *studentInput =  fopen(filename, "r");

	if (studentInput == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	while(fscanf(studentInput, "%s %d %f", students[numStudents].name, &students[numStudents].id, &students[numStudents].GPA) == 3)
	{
		numStudents++;

		if (numStudents >= 100)
		{
			printf("Max students reached\n");
			break;
		}

	}
	fclose(studentInput);
	printf("%d students loaded from records on file\n", numStudents);
}

void list_students()
{
	if (numStudents == 0)
	{
		printf("There are no students to display, add students then try again\n");
	}
	else
	{
		printf("%-20s %-10s %-10s\n", "Name:", "ID:", "GPA:");
		for (int i = 0; i < numStudents; i++)
		{
			if (students[i].name != NULL)
			{
				printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].GPA);
			}
		}
	}
}

void search_student()
{
	int searchedID;
	int flag = 0;

	if (numStudents == 0)
	{
		printf("No student found\n");
		return;
	}

	printf("Enter the student ID: ");
	scanf("%d", &searchedID);

	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].id == searchedID)
		{
			printf("Student found\n");
			printf("Name: %s, ID: %d, GPA: %.2f\n", students[i].name, students[i].id, students[i].GPA);
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		printf("No student found\n");
	}
}

void delete_student()
{
	int deletedID;

	if (numStudents == 0)
	{
		printf("No student found\n");
		return;
	}

	printf("Enter the ID of the student you wish to delete: ");
	scanf("%d", &deletedID);
	for (int i = 0; i <numStudents; i++)
	{
		if (students[i].id == deletedID)
		{

			for (int j = i; j < numStudents -1; j++)
			{
				students[j] = students[j+1];
			}
			numStudents--;

			students = realloc(students, numStudents * sizeof(struct Student));

			printf("Student has been deleted\n");

			break;
		}
	}

	printf("No student with that ID found\n");
}

void save_students(char *filename)
{
	FILE *fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	for (int i = 0; i < numStudents; i++)
	{
		fprintf(fp, "%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].GPA);
	}

	fclose(fp);
}
