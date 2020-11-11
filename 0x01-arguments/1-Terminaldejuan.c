#include <stdio.h>
#include <stdlib.h>
/**
 * main- Program that prints \"$ \", wait for the user to enter a command,
 * prints it on the next line.
 * Return: Always 0.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int returnvalue = 0;

	do
	{
	printf("Terminal de juan: ");
	returnvalue = getline(&line, &len, stdin);
	if (returnvalue == -1)
        {
                printf("ERROR: %d\n", returnvalue);
        }
        else if (*line != 10)
                printf("%s", line);
	} while (returnvalue != -1);
	
	return (0);
}
