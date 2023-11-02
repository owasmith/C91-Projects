#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 20

int main()
{

	printf("Enter the number of words: ");
	int n;
	scanf("%d", &n);

	//create memory allocation for dynamic array, malloc will return a memory address to this area
	char **words = (char **)malloc(n * sizeof(char *));

	printf("Enter %d words: \n", n);

	for (int i = 0; i < n; i++)
	{
		//Allocate the dynamic memory for each word, we use 21 because there will be a null terminator in addition to a max of 21 chars
		words[i] = (char *)malloc((LENGTH + 1) * sizeof(char));
		scanf("%s", words[i]);
	}

	srand((unsigned)time(NULL));

	printf("Generated sentence:\n");

	for (int i = 0; i < 10; i++)
	{
		int randNum = rand() % n;

		//simple method for checking if it is the first word. If it is, it'll capitalize the first word. If it is the last word, it will add a period

		if (i == 0)
		{
			char tempWord[LENGTH];
			tempWord[0] = toupper(words[randNum][0]);
			strcpy(tempWord+1, words[randNum]+1);
			printf("%s ", tempWord);
		}
		else
		{

			printf("%s", words[randNum]);

			if (i < 9)
			{
				printf(" ");
			}	
			else if (i == 9)
			{
				printf(".\n");
			}
		}
	}

	//Free memory space
	for (int i = 0; i < n; i++)
	{
		free(words[i]);
	}

	free(words);

	return 0;


}
