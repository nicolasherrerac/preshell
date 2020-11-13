#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/home/vagrant/holberton", NULL};

	pid_t child_pid;
	int status;

	int i = 0;
	for (; i < 1; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(NULL);
			printf("Good %d\n", child_pid);
		}
		
	}
	
}