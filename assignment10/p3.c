#include <stdio.h>

struct Date
{
	unsigned int year : 16;
	unsigned int month: 8;
	unsigned int day : 8;
};


void add_days(struct Date *d, int n);

int main()
{
	struct Date currentDate;
	int year;
	int month;
	int day;

	printf("Enter date (YYYY/MM/DD): ");
	scanf("%d/%d/%d", &year, &month, &day);

	currentDate.year = year;
	currentDate.month = month;
	currentDate.day = day;

	printf("Enter number of days to add: ");
	int numDays;
	scanf("%d", &numDays);

	printf("Input date: %hhu/%hhu/%hu\n", currentDate.month, currentDate.day, currentDate.year);

	add_days(&currentDate, numDays);

	printf("Date after %d days:  %hhu/%hhu/%hu\n", numDays, currentDate.month, currentDate.day, currentDate.year);

}

void add_days(struct Date *d, int n)
{
	while (n > 0)
	{
		if ((n + d->day) <=  30)
		{
			d->day += n;
			break;
		}
		else
		{
			n -= (30 - d->day);
			d->day = 1;

			if (d->month == 12)
			{
				d->month = 1;
				d->year += 1;

			}
			else
			{
				d->month += 1;
			}
		}
	}

}
