#include <stdio.h>
#include <stdbool.h>

bool isMarried();
int calculateTax(int annualIncome);

int main(){

	char employeeType;
	int monthlySalary = -1;
	int monthlyOT = -1;
	int productsSold = -1;

	printf("What type of Employee? \nA for Administrator\nS for Staff\nE for Salesperson\nP for Part-time\nH for Hourly\n");

	scanf(" %c", &employeeType);
	printf("You have selected: %c\n", employeeType);

	if (employeeType == 'A')
	{
		while (monthlySalary < 0)
		{
			printf("What is your monthly salary?\n");
			scanf("%d", &monthlySalary);

			if (monthlySalary < 0)
			{
				printf("Salary cannot be negative\n");
			}
		}

		int annualIncome = (monthlySalary * 12);
		int afterTax = calculateTax(annualIncome);
		printf("your annual income before tax  is: %d | your annual income after tax is: %d\n",annualIncome, afterTax);
	}

	else if (employeeType == 'S')
	{
		while (monthlySalary<0)
		{

			printf("What is your monthly salary?\n");
			scanf("%d", &monthlySalary);

			if (monthlySalary < 0)
			{
				printf("Salary cannot be negative\n");
			}
		}

		while (monthlyOT < 0 || monthlyOT > 10)
		{
			printf("How many hours of overtime did you work?\n");
			scanf("%d", &monthlyOT);
			if (monthlyOT<0 || monthlyOT > 10)
			{
				printf("You have entered an invalid number\n");
			}

		}

		int dailyWage = (monthlySalary/20);
		int hourlyWage = (dailyWage/8);
		int hourlyOTWage = (1.5 * hourlyWage);

		int monthlyOvertimeWage = (monthlyOT * hourlyOTWage);
		int annualOvertimeWage = (monthlyOvertimeWage * 12);

		int annualIncome = ((monthlySalary * 12) + annualOvertimeWage);
		int afterTax = calculateTax(annualIncome);
		printf("your annual income before tax is: %d | your annual income after tax is: %d\n", annualIncome, afterTax);



	}
	else if (employeeType == 'E')
	{
		int monthlySalary = -1;
		while (monthlySalary < 0)
		{
			printf("What is your monthly salary?\n");
			scanf("%d", &monthlySalary);

			if (monthlySalary < 0 )
			{
				printf("Salary cannot be negative\n");
			}
		}

		while (monthlyOT < 0 || monthlyOT > 20) //max of one hour per day, works for twenty days max
		{
			printf("How many hours of overtime did you work? (Max of one hour per day)\n");
			scanf("%d", &monthlyOT);
			if (monthlyOT < 0 || monthlyOT > 20)
			{
				printf("Invalid input, please enter a num in the range\n");
			}
		}
		bool vacation;
		char vacChoice;
		while (vacChoice != 'Y' &&  vacChoice != 'N')
		{
			printf("Did you go on vacation, Y or N\n");
			scanf(" %c", &vacChoice);

			if (vacChoice != 'Y' &&  vacChoice != 'N')
			{
				printf("Please enter a valid input\n");
			}

			if (vacChoice == 'Y')
			{
				vacation = true;
			}
			else if (vacChoice == 'N')
			{
				vacation = false;
			}
		}

		while (productsSold < 0)
		{
			printf("How many products did you sell?\n");
			scanf("%d", &productsSold);

			if (productsSold <0)
			{
				printf("Please enter a positive number\n");
			}

		}

		int dailyWage = (monthlySalary/20);
		int hourlyWage = (dailyWage/8);
		int hourlyOTWage = (hourlyWage * 1.35);

		int monthlyOvertimeWage = (hourlyOTWage * monthlyOT);
		int annualOvertimeWage = (monthlyOT * 12);

		int productEarnings = (productsSold * 600);

		int annualIncome;

		if (vacation == true)
		{
			annualIncome = (monthlySalary * 11) + (monthlySalary/2) + productEarnings + (monthlyOvertimeWage * 11);

		}
		else
		{
			annualIncome = (monthlySalary * 12) + productEarnings + annualOvertimeWage;

		}

		int afterTax = calculateTax(annualIncome);
		printf("your annual income before tax is: %d | your income after tax is %d\n", annualIncome, afterTax); 




	
	}
	else if (employeeType == 'P')
	{
		int weeklySalary = -1;

		while (weeklySalary < 0)
		{

			printf("What is your weekly salary?\n");
			scanf("%d", &weeklySalary);

			if (weeklySalary < 0)
			{
				printf("Salary cannot be negative, enter a valid input\n");
			}
		}

		int weeklyOT;

		while (weeklyOT < 0 || weeklyOT > 10)
		{
			printf("How many hours of overtime do you work in a week?\n");
			scanf("%d", &weeklyOT);

			if (weeklyOT < 0 || weeklyOT > 10)
			{
				printf("Invalid input, please enter a number in your range\n");
			}


		}

		
		while (productsSold < 0)
		{
			printf("How many products did you sell?\n");
			scanf("%d", &productsSold);

			if (productsSold < 1)
			{
				printf("Please input a positive number\n");
			}
		}

		int monthlySalary = (weeklySalary * 4);
		int dailySalary = (weeklySalary/5);
		int hourlyWage = (dailySalary/8);

		int weeklyOTWage = (weeklyOT * hourlyWage);
		int monthlyOTWage = (weeklyOTWage * 4);
		int annualOTWage = (monthlyOTWage * 12);

		int productEarning = productsSold * 600;

		int annualIncome = (productsSold + annualOTWage + (monthlySalary * 12));
		int afterTax = calculateTax(annualIncome);
		printf("your annual income is: %d | your income after tax is: %d\n",annualIncome, afterTax);

	}

	else if (employeeType == 'H')
	{
		int hourlySalary = -1;
		while (hourlySalary < 0)
		{
			printf("What is your hourly salary?\n");
			scanf("%d", &hourlySalary);
			if (hourlySalary < 0)
			{
				printf("Your salary cannot be negative, please enter a valid input");
			}
		}

		int numofHours = -1;
		while (numofHours < 0 || numofHours > 20)
		{
			printf("How many hours do you work each week?\n");
			scanf("%d", &numofHours);
			if (numofHours<0 || numofHours > 20)
			{
				printf("Your number of hours worked cannot be negative or exceed 20 per week\n"); //twenty hours a week, ten basic then ten overtime
			}
		}

		int overtimeHourlyWage = (hourlySalary * 1.25);
		if (numofHours > 10)
		{
			int OTHours = numofHours - 10;
			int yearlyHours = (40 * 12);
			int yearlyOTHours = (OTHours * 4 * 12);
			int annualIncome = (yearlyHours * hourlySalary) + (yearlyOTHours * overtimeHourlyWage);
			int afterTax = calculateTax(annualIncome);
			printf("your annual income is: %d | income after tax is: %d\n", annualIncome, afterTax);
		}
		else
		{
			int yearlyHours = (numofHours * 4) * 12;
			int annualIncome = (yearlyHours * hourlySalary);
			int afterTax = calculateTax(annualIncome);
			printf("your annual income is: %d | your income after tax is: %d\n", annualIncome, afterTax);

		}


	
	
	}
	else
	{
		printf("That is not a valid input\n");
	}



}

bool isMarried()
{
	bool married;
	char marriedInput;

	while (marriedInput != 'Y' && marriedInput != 'N')
	{
		printf("Are you married? Y or N\n");
		scanf(" %c", &marriedInput);

		if (marriedInput != 'Y' && marriedInput != 'N')
		{
			printf("Not a valid input, please select Y or N\n");
		}
	}

	if (marriedInput == 'Y')
	{
		married = true;
	}
	else if (marriedInput == 'N')
	{
		married = false;
	}

	return married;

}

int calculateTax(int annualIncome)
{
	int afterTax;
	bool marriageStatus = isMarried();
	if(marriageStatus)
	{
		if (annualIncome > 32000)
		{
			afterTax = (annualIncome - (annualIncome * .25));
			
		}
		else
		{
			afterTax = (annualIncome - (annualIncome * .10));
		}
	}
	else
	{
		if (annualIncome > 64000)
		{
			afterTax = (annualIncome - (annualIncome * .25));
		}
		else
		{
			afterTax = (annualIncome - (annualIncome * .10));
		}
	}

	return afterTax;
}
