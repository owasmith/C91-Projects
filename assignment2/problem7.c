#include <stdio.h>

int main()
{
	int radius;
	printf("Input the radius: ");
	scanf("%d", &radius);

	float pi = 3.14; //Establishes pi as 3.14
	int diameter = (2 * radius); //calculates diameter, can leave as an integer
	float area = (float) pi * (radius * radius); //parses to float value bc of pi
	float circum = (float) pi * 2 * radius; //calculates circumference

	printf("The diameter of a circle with a radius of %d is %d\n", radius,diameter);
	printf("The area of a circle with a radius of %d is %.2f\n", radius, area);
	printf("The circumference of a circle with a radius of %d is %.2f\n", radius, circum); //Use % decimal two f so it only goes to two decimal places
	return 0;
}

