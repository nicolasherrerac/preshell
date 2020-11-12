#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_array - Generate an array (av) whit the arguments in a line.
 * Return: An array whit each argument (word) in the line.
 */
char **get_array(void)
{
	char *line = NULL;
	size_t len = 0;
	char *word;
	const char limit[2] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

	/*Get line*/
	getline(&line, &len, stdin);

	/*Count limit char*/
	for(i = 0 ; line[i] != 0; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}

	/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 1));

	/*Full array*/
	array[0] = strtok(line, limit);

	for(i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
	}

	free(line);

	return (array);
}

/**
 * main - Testing gen_array function.
 * Return: Always 0.
 */
int main(void)
{
	char **av = NULL;
	int i = 0;/*Runner*/

	printf("$ ");

	av = get_array();

	/*Print and free each array's elements*/
	for (; av[i] != NULL; i++)
	{
		printf("Indice %d palabra %s\n", i, av[i]);
	}
	free(av);

	return (0);
}
