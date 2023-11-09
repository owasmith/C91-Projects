#include <stdio.h>

union WeatherData
{
	float temperature;
	float humidity;
	float windSpeed;
	float windDirection;
};

int main()
{
	union WeatherData data;
	printf("What type of data would you like to collect?\n");
	printf("1. Temperature\n");
	printf("2. Humidity\n");
	printf("3. Wind Speed\n");
	printf("4. Wind Direction\n");
	printf("Please select an option (1-4): ");
	int input;
	scanf("%d", &input);

	if (input == 1)
	{
		printf("Enter the temperature: ");
		scanf("%f", &data.temperature);
		printf("Temperature: %.2f\n", data.temperature);

	}
	else if (input == 2)
	{
		printf("Enter the humidity: ");
		scanf("%f", &data.humidity);
		printf("Humidity: %.2f\n", data.humidity);

	}
	else if (input == 3)
	{
		printf("Enter the wind speed: ");
		scanf("%f", &data.windSpeed);
		printf("Wind speed: %.2f\n", data.windSpeed);

	}
	else if (input == 4)
	{
		printf("Enter the wind direction: ");
		scanf("%f", &data.windDirection);
		printf("Wind directoon: %.2f\n", data.windDirection);

	}
	else
	{
		printf("Not a valid input\n");
	}
}
