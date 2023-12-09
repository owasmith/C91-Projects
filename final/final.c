//This code was written collaborativley by Owain Smith and Cole Wilson, for C91. Per the assignment instructions, ChatGPT was briefly used for debugging and improving the code, but no code was directly copied. ChatGPT is cited whenever used, in accordance with the courses policy on academic honesty.
//Video Link: https://youtu.be/WooslxLn-Kg?si=DPfvMR-kB4ZyBywj
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player{
	char name[50];
	char cityName[51];
	float score;
};

void instructions(); //Tutorial
void list_scores(); //Lists scores
void sort_players(); //Sorts scores in descending order
void load_save(FILE *file); //Loads the data from a file so scores can be listed
void play_game(); //Plays the game

struct Player *players = NULL;
int numPlayers = 0;

int main()
{
	FILE *filename = fopen("scores.txt", "r"); //Loading file in read mode, r+ causes problems
	printf("=============== City Builder ===============\n");
	printf("Welcome to City Builder\n");

	players = (struct Player *)malloc(numPlayers * sizeof(struct Player)); //allocates proper memory for the players

	int option = -1;

	while (option == -1) //Making a while loop for the menu, easily repeatable
	{
		printf("Select an option:\n");
		printf("1. New Save\n");
		//printf("2. Load Scores\n");
		printf("2. List Scores\n");
		printf("3. Instructions\n");
		printf("4. Exit\n");

		scanf("%d", &option);
		if (option < 0 || option > 4)
		{
			printf("Error: Invalid option, try again\n");
			option = -1;
		}
	

		switch(option)
		{
			case 1:
				printf("Making new save...\n");
				play_game();
				option = -1;
				break;
			/*
			 This used to be a seperate option, but we found it to be redundant. Instead load_Save is now called with list scores
			case 2:
				printf("Loading saves...\n");
				load_save(filename);
				option = -1;
				break;
			*/
			case 2:
				printf("Showing scores...\n");
				load_save(filename);
				sort_players();
				list_scores();
				option = -1;
				break;
			case 3:
				printf("Loading tutorial...\n");
				instructions();
				option = -1;
				break;
	
			case 4:
				printf("Saving and exiting game...\n");
				exit(0);
		}
	}

}

void load_save(FILE *file)
{
	//FILE *file = fopen(filename, "r");
	
	free(players); //Freeing players, this function is called multiple times so needs it
	//numPlayers = 0; //Remove if not working

	if (file == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	int maxPlayers = 100;
	int buffer = 10;

	players = (struct Player *)malloc(maxPlayers * sizeof(struct Player)); //Allocating memory

	fseek(file, 0, SEEK_SET); //Needed to use ChatGPT to debug this function, and it recommended I added fseek(). This sets the position back to the beginning and ensures all data is read

	while (fscanf(file, "%s %s %f", players[numPlayers].name, players[numPlayers].cityName ,&players[numPlayers].score) == 3)
	{
		numPlayers++;
		if (numPlayers >= maxPlayers)
		{
			printf("Max number of players has been reached, reallocating memory\n");
			maxPlayers += buffer;
			struct Player *tmp = realloc(players, maxPlayers * sizeof(struct Player)); //Reallocates memory if the max number of players is reached
	
			if (tmp == NULL)
			{
				printf("Memory reallocation failed\n");
			}
			players = tmp;
		}

	}

	fclose(file);
	printf("Player records\n");
}

void sort_players()
{
	//Using bubble sort to sort players by score
	for (int i = 0; i < numPlayers; i++)
	{
		for (int j = 0; j < numPlayers - i - 1; j++)
		{
			if (players[j].score < players[j+1].score)
			{
				struct Player tmp = players[j];
				players[j] = players[j+1];
				players[j+1] = tmp;
			}
		}
	}

}

void list_scores()
{
	if (numPlayers == 0)
	{
		printf("No players available\n");
	}
	else
	{
		printf("=============== SCOREBOARD ===============\n");
		printf("%-20s %-20s %-10s", "Name: ", "City Name: ", "Score:\n");
		printf("--------------------------------------------------------\n");

		for (int i = 0; i < numPlayers; i++)
		{
			printf("%-20s %-20s %-10.2f\n", players[i].name, players[i].cityName, players[i].score);
		}

		printf("===========================================\n");
	}

}

void instructions()
{
	printf("=============== TUTORIAL ===============\n");
	printf("Welcome to the Sustainable City Builder. In this game, you must build a city based on a given budget.\nYour goal is to create a city with the highest population, happiness, and sustainability within 10 turns. Your final score is calculated from these stats.\nEvery turn you will have the option to either build a structure, declare a law, or research. \nSome options need a higher research level, which takes more turns but provide increased bonuses.\nEach choice you make will either increase or decrease a stat, so you must choose the best decision for your city.\nThis game is based around the UN goal of affordable and clean energy, as well as sustainable cities and communities\n");
	printf("========================================\n");
}

void play_game()
{
	char cityName[50];
	char playerName[51];
	float score = 0;

	int turnNum = 1;
	int happiness = 50;
	int population = 0;
	int budget = 5000000;
	int sustainability = 50;
	int researchLevel = 1;
	int exitFlag = 0;

	printf("Enter player name: ");
	scanf("%s", playerName);

	printf("Enter a name for your city: ");
	scanf(" %s", cityName);

	while (turnNum <= 10)
	{
		if (turnNum == 0)
		{
			printf("Welcome to the city builder!\n");

		}
		int menuOption = 0;
		while (menuOption < 1)
		{
			printf("===================================\n");
			printf("City: %s\n", cityName);
			printf("Turn: %d\n", turnNum);
			printf("Budget: %d\n", budget);
			printf("Research Level: %d\n", researchLevel);
			printf("Population: %d\n", population);
			printf("Happiness: %d\n", happiness);
			printf("Sustainability: %d\n", sustainability);
			printf("===================================\n");

		
			printf("Select an option: \n");
			printf("1. Build Structures\n");
			printf("2. Declare Law\n");
			printf("3. Research and Development\n");
			printf("4. Exit\n");

			scanf("%d", &menuOption);
			if (menuOption < 1 || menuOption > 5)
			{
				menuOption = 0;
			}

			switch(menuOption)
			{
				//Turn Num is only for testing, take it out when functions are expanded upon
				case 1:
					printf("Build Structures selected\n");
					int buildMenuOption = 0;
					while (buildMenuOption < 1)
					{
						printf("Select what you would like to build (All cost one turn):\n");
						printf("1. Build Houses (Cost: 250000, Population: +100, Happiness: +10\n");
						printf("2. Build Apartments (Cost: 500000, Population: +500, Sustainability: +10, Happiness: -5)\n");
						printf("3. Build Factories (Cost: 1000000, Population: +2000, Sustainability: -15)\n");
						printf("4. Build Stores (Cost: 750000, Happiness: +20)\n");
						printf("5. Go back\n");
						scanf("%d", &buildMenuOption);

						if (buildMenuOption < 1 || buildMenuOption > 5)
						{
							printf("Not a valid option\n");
							buildMenuOption = 0;
						}
						switch(buildMenuOption)
						{
							case 1:
								if (budget >= 250000)
								{
									budget -= 250000;
									population += 100;
									happiness += 10;
									turnNum++;

 									break;
								}
								else
								{
									printf("Error: not enough money\n");
									buildMenuOption = 0;
									break;
								}
							case 2:
								if (budget >= 500000)
								{
									budget -= 500000;
									population += 500;
									sustainability += 10;
									happiness -= 5;
									turnNum++;
									break;
								}
								else
								{
									printf("Error, not enough money\n");
									buildMenuOption = 0;
									break;
								}
							case 3:
								if (budget >= 1000000)
								{
									budget -= 1000000;
									population += 2000;
									sustainability -= 15;
									turnNum++;
									break;
								}
								else
								{
									printf("Error: not enough money\n");
									buildMenuOption = 0;
									break;
								}
							case 4:
								if (budget >= 750000)
								{
									budget -= 750000;
									happiness += 20;
									turnNum++;
									break;
								}
								else
								{
									printf("Error: not enough money\n");
									buildMenuOption = 0;
									break;
								}
							case 5:
								break;

						}

					}
					break;
				case 2: //
					printf("Declare Law selected\n");
					int lawMenuOption = 0;
					while (lawMenuOption < 1)
					{
						printf("Select an ordinance: \n");
						printf("1. Plant Tress (1 Turn, +10 Sustainability +5 Happiness)\n");
						printf("2. Reduce Carbon Emissions (1 Turn, +20 Sustainability, -5 Happiness)\n");
						printf("3. Use Solar Energy (Research Level 2 Required, 1 Turn, +30 Sustainability)\n");
						printf("4. Use Nuclear Energy (Research Level 3 Required, 2 Turns, +50 Sustainability)\n");
						printf("5. Go back\n");
						scanf("%d", &lawMenuOption);

						if (lawMenuOption < 1 || lawMenuOption > 5)
						{
							printf("Not a valid option\n");
							lawMenuOption = 0;
						}
						switch(lawMenuOption)
						{
							case 1:
								printf("Planted Trees\n");
								turnNum += 1;
								sustainability += 10;
								happiness += 5;
								break;
							case 2:
								printf("Reduced Carbon Emissions\n");
								turnNum += 1;
								sustainability += 20;
								happiness += 5;
								break;
							case 3:
								if (researchLevel > 1)
								{
									printf("Building Solar\n");
									sustainability += 30;
									turnNum++;
								}
								else
								{
									printf("Your Research Level is not high enough\n");
									lawMenuOption = 0;
								}
								break;
							case 4:
								if (researchLevel > 2)
								{
									if (turnNum <= 8)
									{
										printf("Building Nucelear Plant\n");
										sustainability += 50;
										turnNum += 2;
									}
									else
									{
										printf("Error, not enough turns left\n");
										lawMenuOption = 0;
									}
								}
								else
								{
									printf("Your Research Level is not high enough\n");
									lawMenuOption = 0;
								}
								break;
							case 5:
								break;

						}
					}
					break;
				case 3: //Research
					printf("Research selected\n");
					if (researchLevel == 1)
					{
						printf("Research Level Increased to 2\n");
						researchLevel++;
						turnNum++;
						break;

					}
					else if (researchLevel == 2)
					{
						if (turnNum <= 8)
						{
							printf("Research Level Increased to 3\n");
							researchLevel++;
							turnNum += 2;
							break;
						}
						else
						{
							printf("Error, you do not have enough turns left.");
							break;
						}
					}
					else if (researchLevel >= 3)
					{
						printf("Max Research Level Achieved, select a different option\n");
						menuOption = 0;
						break;
						
					}
				case 4:
					printf("Warning: Once you exit this save your score will be caculated, and you will not be able to re-enter this save\n");
					exitFlag = 1;
					turnNum = 11;
					break;

			}
		} 

	}
	
	//Calculating score after ten turns
	if (turnNum > 10)
	{
		score = (sustainability * (happiness + (population/100))); //Equation for score. Emphasis on sustainability
	
		struct Player newPlayer;

		//In my code, I originally used newPlayer.name = playerName, but it was giving errors. To debug this, I used ChatGPT to explain why the error was happening, and then came up with my own solution. The reason for the error was I was using incompatible types, but this fixes it by removing the null character 
		strncpy(newPlayer.name, playerName, sizeof(newPlayer.name) - 1);
		newPlayer.name[sizeof(newPlayer.name) -1] = '\0';
		newPlayer.score = score;

		strncpy(newPlayer.cityName, cityName, sizeof(newPlayer.cityName) -1);
		newPlayer.cityName[sizeof(newPlayer.cityName)-1] = '\0';

		//Used ChatGPT to debug this part, I was originally getting errors because I was using "w" instead of "a". Using "w" rewrote from the beginning of the file, when I just needed it to be appended.

		FILE* scoresFile = fopen("scores.txt", "a");

		if (scoresFile == NULL)
		{
			printf("Error: Cannot open score file\n");
			return;
		}
		else
		{
			fprintf(scoresFile, "%s %-10s %-10.2f\n", newPlayer.name, newPlayer.cityName, newPlayer.score);
		}
		fclose(scoresFile);

		numPlayers++;
		//players = realloc(players, numPlayers * sizeof(struct Player));
		
		//Used ChatGPT to debug this. Data types could not take in the string directly and was getting errors. To fix this, it recommended I use strcpy, which I then implemented myself
		strcpy(players[numPlayers-1].name, newPlayer.name);
		strcpy(players[numPlayers-1].cityName, newPlayer.cityName);
		players[numPlayers-1].score = newPlayer.score;


		printf("Your Score: %.2f\n", score);


	}

}
