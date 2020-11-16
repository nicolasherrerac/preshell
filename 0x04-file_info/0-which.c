#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * _which - Look for files in the current PATH.
 * @file: Names of files.
 */
void _which(char **file)
{
	unsigned int i = 1;
	struct stat buf;

	for (; file[i]; i++)
	{
		if (stat(file[i], &buf) == 0)
			printf("%s was found.\n", file[i]);
		else
			printf("%s was not found.\n", file[i]);
	}
}

/**
 * main - Test function _which.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * Return: 0 if is succes -1 if isn't fail.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	short int found;

	if (ac < 2)
	{
		printf("Error\n");
		return (-1);
	}

	_which(av);

	return (0);
}
