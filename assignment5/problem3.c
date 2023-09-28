#include <stdio.h>
#include <string.h>
#include <ctype.h>
int charCounter(char array[], char c);
int charChecker(char array[], size_t length, char c);

int main()
{
	char input[100];
	printf("Enter a string of no more than 100 characters: \n");
	scanf("%99[^\n]", input);

	//Make a new char array for each unique letter, if it isn't already in the array, add it
	
	char charArray[27] = " ";

	for (size_t i = 0; i < strlen(input) ; i++)
	{
		char currentChar = tolower(input[i]);
		if ((charChecker(charArray, strlen(charArray), currentChar)) == 0)
		{
		//	printf("Character is not in charArray, adding it: %c\n", currentChar);
			charArray[strlen(charArray)] = currentChar;
		}

	}

	for (size_t i = 0; i <strlen(charArray); i++)
	{
		int count = (charCounter(input, charArray[i]));
		if (charArray[i] == ' ')
		{
			printf("Spaces: %d\n", count);
		}
		else
		{
			printf("%c : %d\n", charArray[i], count);
		}
	}

}

int charCounter(char array[], char c)
{
	int count = 0;
	for (size_t i = 0; i < 100; i++)
	{
		if (array[i] == c)
		{
			count++;
		}
	}
	return count;

}

int charChecker(char array[], size_t length,  char c)
{
	for (size_t i = 0; i < length; i++)
	{
		if (c == array[i])
		{
			return 1;
		}
	}
	return 0;
}
