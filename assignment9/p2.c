#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float USD;
	float EUR;
	float GBP;
}Price;

int main()
{
	Price price1;
	Price *pricePTR = &price1;

	printf("Enter the price of the product: ");
	float priceInput;
	scanf("%f",&priceInput);

	printf("Enter the currency (USD, EUR, or GBP): ");
	char currencyType[4];
	scanf("%3s", currencyType);

	if (strcmp(currencyType, "USD") == 0)
	{
		pricePTR->USD = priceInput;
		pricePTR->EUR = priceInput * 0.92;
		pricePTR->GBP = priceInput * 0.81;
	}
	else if (strcmp(currencyType, "EUR") == 0)
	{
		pricePTR->USD = priceInput * 1.07;
		pricePTR->EUR = priceInput;
		pricePTR->GBP = pricePTR->USD * 0.81;

	}
	else if (strcmp(currencyType, "GBP") == 0)
	{
		pricePTR->USD = priceInput * 1.23;
		pricePTR->EUR = pricePTR->USD * 0.92;
		pricePTR->GBP = priceInput;
	}
	else
	{
		printf("Invalid currency");
	}
	printf("Price in USD: %.2f\n", pricePTR->USD);
	printf("Price in EUR: %.2f\n", pricePTR->EUR);
	printf("Price in GBP: %.2f\n", pricePTR->GBP);	
}
