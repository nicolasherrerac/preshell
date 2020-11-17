#include <unistd.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

/**
 * _strlen - Count the amount of character of a string.
 * @str: String.
 * Return: Number of characters in the string.
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
 * _getenv - Search a value of an enviroment variable.
 * @name: Name of enviroment variable.
 * Return: A pointer to the value.
 */
char *_getenv(char *name)
{
	unsigned int i = 0;/*Runner*/
	char *value = NULL;
	int b = 1;/*Boolean True = 0*/
	unsigned int len = 0;

	if (!name)
		return (NULL);

	len = _strlen(name);

	while (environ[i] != NULL)
	{
		/*Compare*/
		b = strncmp(environ[i], name, len);
		/*If value if found*/
		if (b == 0)
		{
			value = environ[i] + len + 1;
			return (value);
		}
		i++;
	}
	/*If value isn't found*/
	return (NULL);
}

/**
 * main - Print PATH's directories.
 * Return: 0
 */
int main(void)
{
	char *name = NULL;
	char *value = NULL;
	int i = 0;/*Runner*/

	name = "PATH";
	value = _getenv(name);
	if (!value)
	       printf("La variable %s no fue encontrada\n", name);

	for (; value[i] != '\0'; i++)
	{
		if (value[i] == ':')
			putchar('\n');
		else
			putchar(value[i]);
	}
	putchar('\n');

	return (0);
}
