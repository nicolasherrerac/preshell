#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_array - Generate an array (av) whit the arguments in a line.
 * Return: An array whit each argument (word) in the line.
 */
char **get_array(char *line)
{
	const char limit[2] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

	/*Count limit char*/
	for(i = 0 ; line[i] != 0; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}

	/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 2));

	/*Full array*/
	array[0] = strtok(line, limit);

	for(i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
	}
	array[i] = NULL;
	return (array);
}

/**
 * main - Testing gen_array function.
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
        size_t len = 0;
	char **av = NULL;
	int i = 0;/*Runner*/

	printf("$ ");

	/*Get line*/
	getline(&line, &len, stdin);

	av = get_array(line);

	/*Print and free each array's elements*/
	for (; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	free(av);
	free(line);
	return (0);
}
