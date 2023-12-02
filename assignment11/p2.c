#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Invalid amount of arguments\n");
		return 1;
	}

	FILE *inputFile;
	FILE *oddOutputFile;
	FILE *evenOutputFile;

	int num = 0;
	int oddCount = 0;
	int evenCount = 0;

	inputFile = fopen(argv[1], "r");
	if (inputFile == NULL)
	{
		printf("Error opening input file\n");
		return 1;
	}

	oddOutputFile = fopen(argv[2], "w");
	if (oddOutputFile == NULL)
	{
		printf("Error opening odd output file\n");
		fclose(inputFile);
		return 1;
	}

	evenOutputFile = fopen(argv[3], "w");
	if (evenOutputFile == NULL)
	{
		printf("Error opening even output file\n");
		fclose(inputFile);
		fclose(oddOutputFile);
		return 1;
	}

	while (fscanf(inputFile, "%d", &num) == 1)
	{
		if (num % 2 == 0)
		{
			//fprintf(outputEvenFile, "%d\n", num);
			evenCount++;
		}
		else
		{
			//fprintf(outputOddFile, "%d\n", num);
			oddCount++;
		}
	}

	fprintf(oddOutputFile, "This file contains a list of %d odd numbers\n", oddCount);
	fprintf(evenOutputFile, "This file contains a list of %d even numbers\n", evenCount);

	fseek(inputFile, 0, SEEK_SET);

	while (fscanf(inputFile, "%d", &num) == 1)
	{
		if (num %2 == 0)
		{
			fprintf(evenOutputFile, "%d\n", num);
		}
		else
		{
			fprintf(oddOutputFile, "%d\n", num);
		}
	}



	fclose(inputFile);
	fclose(oddOutputFile);
	fclose(evenOutputFile);


	
	
}
