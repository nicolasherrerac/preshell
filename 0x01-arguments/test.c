#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_array - Generate an array (av) whit the arguments in a line.
 * Return: An array whit each argument (word) in the line.
 */
void get_array(void)
{
	char *line = NULL;
	size_t len = 0;
	const char limit[2] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	/*Get line*/
	getline(&line, &len, stdin);

	/*Count limit char*/
	for(i = 0 ; line[i] != 0; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}

	/*Allocate memory*/
	char *array[contsp + 1];

	/*Full array*/
	array[0] = strtok(line, limit);

	for(i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
	}

	/*Print and free each array's elements*/
	for (i = 0; array[i] != NULL; i++)
	{
		printf("Indice %d palabra %s\n", i, array[i]);
	}

	free(line);

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

	get_array();

	return (0);
}
