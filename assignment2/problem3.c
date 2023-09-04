#include <stdio.h>

int main(void)
{
	int day;
	int month;
	int year;
	int birthyear;

	printf("\n Enter the day: ");
	scanf("%d", &day);

	printf("\n Enter the month: ");
	scanf("%d", &month);

	printf("\n Enter the year: ");
	scanf(" %d", &year);

	printf("\n Enter your birth year:  ");
	scanf("%d", &birthyear);

	int age = year - birthyear;

	printf("\n Today is %d/%d/%d, and you are %d years old",month, day, year, age);

	
}
	
