#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rollDice(void);
void rollAllDice(int dice[], int diceAMNT);
bool isThreeOfKind(void);
bool isYahtzee(int dice[]);
void displayAllDice(int dice[], int diceAMNT);

int diceAMNT; //Used to store the value of how many dice are being rolled

int score1; 

//This is meant to be a simplified version of Yahtzee

int main()
{
	srand(time(NULL));
	diceAMNT = 5;
	score1 = 0;
	int dice[diceAMNT];

	printf("Welcome to a simplified version of Yahtzee, in this game, you will roll 5 dice and attempt to score as many points as possible to beat your opponent\n");
	printf("In this version, your score will be the total of your rolls, and if you get a YAHTZEE you will get 50 points\n");

	char input; //Static variable, input, used to check what the user entered. If entered R, then will run the game. Doesn't need to be used elsewhere

	printf("Player 1, press 'R' to roll your dice\n");
	scanf("%c", &input);
	if (input == 'R' || input == 'r')
	{
		rollAllDice(dice, diceAMNT);
		displayAllDice(dice, diceAMNT);
		if (isYahtzee(dice))
		{
			printf("Yahtzee\n");
			score1 += 50;

		}

	}

	for (int i = 0; i < diceAMNT; i++)
	{
		score1 += dice[i];
		dice[i] = 0;
	}
	printf("Player 1 score is: %d\n", score1);

	int score2 = 0;



	char input2;

	printf("Player 2, press 'R' to roll your dice\n");
	scanf(" %c", &input2);
	if (input == 'R' || input == 'r')
	{
		rollAllDice(dice, diceAMNT);
		displayAllDice(dice, diceAMNT);
		if (isYahtzee(dice))
		{
			printf("Yahtzee\n");
			score2 += 50;
		}
	}

	for (int i = 0; i < diceAMNT; i++)
	{
		score2 += dice[i];
	}

	printf("Player 2 score is: %d\n", score2);

	if (score2 > score1)
	{
		printf("Player 2 wins\n");
	}
	else if (score1 > score2)
	{
		printf("Player 1 wins\n");
	}
	else
	{
		printf("Tied\n");
	}



}
int rollDie(void) // This will roll the dice, finding a random number from one to six
{
	return rand() % 6 + 1;
}

void rollAllDice(int dice[], int diceAMNT) //This will roll all the dice at once, calling rhe rollDie() function
{
	for (int i = 0; i < diceAMNT; i++)
	{
		dice[i] = rollDie();
	}

}

void displayAllDice(int dice[], int diceAMNT) // This prints the value of all the die, helps for the user
{
	printf("Current dice values: ");
	for (int i = 0; i < diceAMNT; i++)
	{
		printf("%d", dice[i]);
	}
	printf("\n");

}

bool isYahtzee(int dice[]) // This checks if the roll is a Yahtzee, which is when all the rolls are the same. It will simply check if the value is equal to the first, and if it isn't then they arent all the same
{
	for(int i = 1; i < diceAMNT; i++)
	{
		if (dice[i] != dice[0])
		{
			return false;
		}
	}
	return true;

}


