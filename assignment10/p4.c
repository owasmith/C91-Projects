#include <stdio.h>

struct RGB
{
	unsigned int red : 8;
	unsigned int green : 8;
	unsigned int blue : 8;
};

int main()
{
	struct RGB color;

	unsigned int redValue, greenValue, blueValue;


	printf("Enter the Red Value (0-255): ");
	scanf("%u", &redValue);

	printf("Enter the Green Value (0-255): ");
	scanf("%u", &greenValue);

	printf("Enter the Blue Value (0-255): ");
	scanf("%u", &blueValue);

	color.red = redValue;
	color.green = greenValue;
	color.blue = blueValue;

	printf("Your color is #%02x%02x%02x\n", color.red, color.green, color.blue);
	return 0;

}
