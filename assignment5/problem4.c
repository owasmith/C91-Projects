#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void wordScrambler(int array[], size_t length);


//This game is meant to be a word scramble game, where a word is given, scrambled, and the player must unscramble it.
int main()
{
	char word[] = "migration";

	int shuffle[strlen(word)];

	for (int i = 0; i < strlen(word); i++)
	{
		shuffle[i] = i;
	}

	wordScrambler(shuffle, strlen(word));

	char scrambledWord[strlen(word) + 1];
	for (int i = 0; i< strlen(word); i++)
	{
		scrambledWord[i] = word[shuffle[i]];
	}

	scrambledWord[strlen(word)] = '\0';


	printf("Welcome to the word scrambler, in this game a scrambled word is presented, and you must type the unscrambled word\n");
	printf("Scrambled Word: %s\n", scrambledWord);

	char guessedWord[strlen(word)];

	int valid;
	int loop = 0;

	while (loop != 1)
	{

		printf("Your guess: ");
		scanf("%s", guessedWord);
		valid = 1;
		for (size_t i = 0; i < strlen(word); i++)
		{
			if (guessedWord[i] != word[i])
			{		
				valid = 0;
				break;
			}
			
		}
		if (valid == 0)
		{
			printf("Wrong, try again\n");

		}
		else if (valid == 1)
		{
			printf("Correct, you win\n");
			loop = 1;
		}

	}

}

void wordScrambler(int array[], size_t length)
{
	srand(time(NULL));
	for (size_t i = 0; i < length; i++)
	{
		int j = i + rand() % (length - i);
		char tempChar = array[i];
		array[i] = array[j];
		array[j] = tempChar;
	}

}
