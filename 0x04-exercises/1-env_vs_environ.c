#include <stdio.h>
#include <unistd.h>
/**
 * main -  Argument env vs Global variable environ
 * @ac: No used
 * @av: No used
 * @env: path the environt
 * Description - It is verified that there is no difference between
 * the third argument and the global variable by checking the address
 * of each one.
 * Return: Value 0
 */

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;

	printf("Direction of env %p\n", *env);
	printf("Direction of environt %p\n", *environ);

	return (0);
}
