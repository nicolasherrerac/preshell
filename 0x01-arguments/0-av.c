#include <stdio.h>

/**
 * main - Function that prints all the arguments given, without using ac.
 * @ac: Number of arguments given.
 * @av: Pointer with adrress to pointer to arguments given.
 * Return: Always 0.
 */

int main(__attribute__((unused))int ac, char **av)
{
	unsigned int a;

	for (a = 1; av[a] != 0; a++)
		printf("%s\n", av[a]);
	return (0);
}
