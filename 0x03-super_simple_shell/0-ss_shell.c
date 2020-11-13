#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

/**
 * _strlen - Count the amount of character of a string.
 * @str: String.
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	if (!str)
		return (0);

	while (str)
		len++;
	return (len);
}

/**
 * prt_stdo - Print simple string with write in the stdo.
 * str - String to print.
 */
ssize_t prt_stdo(char *str)
{
	ssize_t n_chars;
	unsigned int s_len;

	s_len = _strlen(str);
	n_chars = write(STDOUT_FILENO, str, s_len);
	return (n_chars);
}

/**
 * main - Super simple shell
 * @ac: Number of arguments.
 * @av: String of arguments.
 */
int main(int ac, char **argv)
{
	char *line;
	size_t len;
	char **av;

	/*Prompt*/

	while (1)
	{
		prt_stdo("#cisfun$ ");
		getline(&line, &len, stdin);
	}
}
