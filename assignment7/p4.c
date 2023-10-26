#include <stdio.h>
#include <string.h>
void replaceAll(const char *string, char *target, char *replacement, char *destination);

int main()
{
	char inputString[100];
	char target[100];

	printf("Enter a string: ");
	scanf("%99[^\n]", inputString);
	getchar();

	printf("Enter the target: ");
	scanf("%99s", target);

	char replacement[100];
	printf("Enter the replacement: ");
	scanf("%99s", replacement);

	char final[100];
	replaceAll(inputString, target, replacement, final);

	printf("Output: %s\n", final);

	return 0;
	


}

void replaceAll(const char *string, char *target, char *replacement, char *destination)
{
	int inputLen = strlen(string);
	int targetLen = strlen(target);
	int replaceLen = strlen(replacement);

	int l = 0;

	for (int i = 0;  i < inputLen; i++)
	{
		if (strncmp(&string[i], target, targetLen) == 0)
		{
			for (int j = 0; j < replaceLen; j++)
			{
				destination[l] = replacement[j];
				l++;

			}
			i += targetLen - 1;
		}
		else
		{
			destination[l] = string[i];
			l++;
		}
	}

	destination[l] = '\0';

}
