#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <string.h>

/**
 * _strlen - Count the amount of character of a string.
 * @str: String.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	if (!str)
		return (0);

	while (str[len])
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
	n_chars = write(1, str, s_len);

	return (n_chars);
}

/**
 * _getline - Get a line and remove \n character.
 *
 * Return: A pointer to the line.
 */
int _getline(char **line, size_t *len)
{
	//char *command;
	int n_chars = 0;
	char *lline = NULL;
	int i;

	n_chars = getline(line, len, stdin);
	if (n_chars <= 0)
		return (n_chars);

	/*lline = malloc((n_chars) * sizeof(char));

	strncpy(lline, *line, n_chars - 1);

	free(*line);
	*line = NULL;
	*line = lline;*/

	return (n_chars);
}

/**
 * main - Super simple shell
 * @ac: Number of arguments.
 * @av: String of arguments.
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char *lline = NULL;
	char *prompt = "#cisfun$ ";
	size_t len = 0;
	char **av = NULL;
	int n_chars = 1;

	while(1)
	{
		printf("#cisfun$ ");
		n_chars = _getline(&line, &len);
		if (n_chars == -1)
		{
			printf("EXIT\n");
			break;
		}
		if (n_chars == 0)
		{
			printf("%s\n", line);
		}
		else if (*line != '\n')
		{
			line[n_chars -1] = '\0';
			printf("Executar el comando %s\n", line);
			free(line);
			//execute();
		}
	}

	//free(line);

	return (0);
}
