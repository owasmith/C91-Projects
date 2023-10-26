#include <stdio.h>

int my_strlen(char *str)
{
	int length = 0;
	while (*str != '\0')
	{
		if (*str != '"')
		{
			length++;
		}
		str++;
	}

	return length;

}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		return 1;
	}
	char *str = argv[1];

	int length = my_strlen(str);

	printf("Length of \"%s\" : %d\n", str, length);

	return 0;

}
