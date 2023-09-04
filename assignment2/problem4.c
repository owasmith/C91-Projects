#include <stdio.h>

int main(){
	int temperature;
	printf("Input temperature in Celcius: ");
	scanf("%d", &temperature);

	if (temperature < -10)
	{
		printf("Freezing\n");
	}
	else if ((temperature >= -10) && (temperature < 10))
	{
		printf("Cold\n");
	}
	else if ((temperature >= 10) && (temperature < 25))
	{
		printf("Moderate\n");
	}
	else
	{
		printf("Hot\n");
	}
	return 0;
}

