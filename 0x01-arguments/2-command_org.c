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
	int i = 0;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

	printf("$ ");

	/*Get line*/
	getline(&line, &len, stdin);

	/*Count limit char*/
	for(len--; len >= 0; len--)
	{
		if (line[len] == *limit)
			contsp++;
	}

	/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 1));

	/*Full array*/
	word = strtok(line, limit);
	array[i] = strdup(word);

	for(i = 1; i <= contsp; i++)
	{
		word =  strtok(NULL, limit);
		array[i] = strdup(word);
	}

	return (array);
}

/**
 * main - Testing gen_array function.
 * Return: Always 0.
 */
int main(void)
{
	char **av;
	int i = 0;/*Runner*/

	printf("$ ");

	av = get_array();

	/*Print and free each array's elements*/
	for (; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
		free(av[i]);
	}
	free(av[i]);

	return 0;
}
