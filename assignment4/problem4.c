#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int rollDice();
int getSum(int a, int b);
int checkCraps(int score);
int throwNum = 0;
int point;

int main()
{
	char input;
	bool wonGame = false;

	printf("Welcome to Craps\n");
	while (wonGame ==false)
	{
		printf("Please type 'R' or 'r' to roll the dice\n");
		scanf("%c",&input);

		if (input == 'R' || input == 'r')
		{
			printf("Rolling Dice\n");

			int firstRoll = 0;
			firstRoll = rollDice();
			printf("First roll is: %d\n", firstRoll);

			int secondRoll = 0;
			secondRoll = rollDice();
			printf("Second roll is %d\n", secondRoll);

			int sum = getSum(firstRoll, secondRoll);
			printf("Sum is: %d\n", sum);

			int result = checkCraps(sum);

			if (result == 1)
			{
				wonGame = true;
			}
			else if (result == 2)
			{
				break;
			}
			else if (result == 0)
			{
				printf("Reroll\n");
			}

		}
		

	}


}


int rollDice(void)
{
	srand(time(NULL));
	int result  = (rand() % 6) + 1;
	return result;

}

int getSum(int a, int b)
{
	return (a+b);

}

int checkCraps(int score)
{
	throwNum += 1;
	if (throwNum == 1)
	{
		if (score == 7 || score == 11)
		{
			printf("You won\n");
			return 1;
		}
		else if (score == 2 || score == 3 || score == 12)
		{
			printf("House wins\n");
			return 2;
		}
		else
		{
			point = score;
			return 0;
			
		}
	}
	else
	{
		if (score == 7 || score == 11)
		{
			printf("House wins\n");
			return 2;
		}
		else if (score == point)
		{
			printf("You won\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	

}
