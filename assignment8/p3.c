#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringConcat(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
	//checks if the amount of arguments is correct, there should be 3, where 2 and 3 are the strings
	if (argc != 3)
	{
		printf("Not correct amount of arguments\n");
		//breaks if not correct amnt
		return 1;
	}
	//calls funtion
	stringConcat(argv[1], argv[2]);

	return 0;
	
}

void stringConcat(const char *str1, const char *str2)
{
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	int totalLength = len1 + 1 + len2;
	//adds length of strings

	char *result = (char *)malloc(totalLength);
	//allocates memory for the char array

	strcpy(result, str1);
	//copies the first string to the array
	result[len1] = ' ';
	strcpy(result + len1 +1, str2);
	//copies the second string after the space in the array
	printf("%s\n", result);

	//frees allocated memory of the result array
	free(result);


}
