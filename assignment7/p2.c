#include <stdio.h>
double taxOne(double income);
double taxTwo(double income);
double taxThree(double income);


int  main()
{
	printf("Please enter your income: ");
	double income = 0.0;
	scanf("%lf", &income);

	double (*calculate)(double);

	double incomeTaxed = 0;

	if (income < 20000)
	{
		printf("Tax Bracket 1\n");
		calculate = taxOne;
	}
	else if (income >= 20000 && income <= 80000)
	{
		printf("Tax Bracket 2\n");
		calculate = taxTwo;
	}
	else if (income > 80000)
	{
		printf("Tax Bracket 3\n");
		calculate = taxThree;
	}
	else
	{
		printf("Not valid income range\n");
	}

	double tax = 0;

	if (income > 20000)
	{
		tax += taxOne(20000);
		income -= 20000;
	}
	else
	{
		tax += taxOne(income);
		income = 0;
	}

	if (income > 0)
	{
		if (income > 60000)
		{
			tax += taxTwo(60000);
			income -= 60000;
		}
		else
		{
			tax+= taxTwo(income);
			income = 0;
		}
	}

	if (income > 0)
	{
		tax += taxThree(income);
	}

	printf("Your tax is: %.2lf\n", tax);


}

double taxOne(double income)
{
	return (0.1 * income);
}
double taxTwo(double income)
{
	return (0.25 * income);
}
double taxThree(double income)
{
	return (0.4 * income);
}
