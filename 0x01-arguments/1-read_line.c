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

	printf("$ ");
	returnvalue = getline(&line, &len, stdin);
	if (returnvalue == -1)
        {
                printf("ERROR: %d\n", returnvalue);
        }
        else
                printf("%s", line);
	free(line);
	return (0);
}
