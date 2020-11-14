#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int i;
	int procP = 1;
	pid_t child;
	char *argv[] = {"/bin/ls", "-l", "./", NULL};

	for (i = 0; i < 5; i++)
	{
		if (procP == 1)
		{
			child = fork();
			if (child == 0)
			{
				printf("Soy el proceso hijo: %d del padre: %d \n", getpid(), getppid());
				
				procP = 0;
				if (execve(argv[0], argv, NULL) == -1)
				{
					printf("ERROR: ");
				}
			}
			else
			{
				wait(NULL);
				printf("soy el proceso padre: %d \n", getppid());
			}
		}

	}
	return (0);
}
