#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0, rest = 0;

	while (s1[i] != 0 && s2[i] != 0) /*&& s1[i] == s2[i])*/
	{
		rest = s1[i] - s2[i];
		if (rest != 0)
			break;
		i++;
	}
	return (rest);
}
char *_getenv(char *name)
{
	int size, i = 0;
	unsigned int n;
	char *retvalue = NULL;

	for (size = 0; name[size] != '\0'; size++)
		;
	while (environ[i])
	{
		n = _strcmp(name, environ[i]);
		if (n == 0)
		{
			retvalue = environ[i];
			break;
		}
		i++;
	}
	return (retvalue);
}
int main(int ac, char **av)
{
	unsigned int i;
	char *retvalue = NULL;

	if (ac < 2)
	{
		printf("Error\n");
		return (0);
	}
	for (i = 1; av[i] != '\0'; i++)
	{
		retvalue = _getenv(av[i]);
		if (retvalue)
			printf("%d: %s\n", i, retvalue);
		else
			printf("The environ variable %s was'n found\n", av[i]);
	}
	return (0);
}
