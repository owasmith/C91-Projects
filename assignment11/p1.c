#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("input.txt", "r");

	if (file == NULL)
	{
		printf("Unable to open file\n");
		return 1;
	}

	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);

	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;

	for (long j = 0; j < size; j++)
	{
		char ch = fgetc(file);

		if (ch == 'a' || ch == 'A')
		{
			a++;
		}
		else if (ch == 'e' || ch == 'E')
		{
			e++;
		}
		else if (ch == 'i' || ch == 'I')
		{
			i++;
		}
		else if (ch == 'o' || ch == 'O')
		{
			o++;
		}
		else if (ch == 'u' || ch == 'U')
		{
			u++;
		}

	}

	printf("Count of A: %d\n", a);
	printf("Count of E: %d\n", e);
	printf("Count of I: %d\n", i);
	printf("Count of O: %d\n", o);
	printf("Count of U: %d\n", u);

	fclose(file);


}
