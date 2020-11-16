#include <unistd.h>
#include <stdio.h>

extern char **environ;

/**
 * main - prints env and environ address.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * @env: Array of eviroments.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;

	printf("Env address: %p\n", env);
	printf("Environ address: %p\n", environ);

	return (0);
}
