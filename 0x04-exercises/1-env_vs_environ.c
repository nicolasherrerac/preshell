#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;

	printf("Direction of env %p\n", *env);
	printf("Direction of environt %p\n", *environ);

	return (0);
}
