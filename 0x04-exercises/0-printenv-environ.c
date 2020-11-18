#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	unsigned int j;

	for (j = 0; environ[j]; j++)
		printf("%d: %s\n", j, environ[j]);

	return (0);
}
