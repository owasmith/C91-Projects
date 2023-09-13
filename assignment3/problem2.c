#include <stdio.h>

int main(){

	char firstletter;
	char secondletter;

	for (firstletter = 'a'; firstletter <= 'z'; firstletter++)
	{
		for (secondletter = 'a'; secondletter <= 'z'; secondletter++)
		{
			printf("www.%c%c.com\n",firstletter, secondletter);
		}
	}

	return 0;
}
