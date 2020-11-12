#include <stdio.h>
#include <string.h>

int main(void)
{
	char lline[] = "ugly calculadora mani";
	const char limit[2] = " ";
	int j = 0, i = 0, lenw = 0, contsp = 0;
	char **array = NULL;
	char *word = NULL, *line = &lline;

	for(j = 0; line[j] != '\0'; j++)
	{
		if (line[j] == limit[0])
			contsp++;
	}

	array = malloc(sizeof(char *)*(contsp + 1));
	word = strtok(line, limit);
	array[i] = strdup(word);

	for(i = 1; i <= contsp; i++)
	{
		word = strtok(NULL, limit);
		array[i] = strdup(word);
	}
	/*
	    for(i = 0; i <= contsp; i++)
	    {
	    printf("%s\n", array[i]);
	    free(array[i]);
	    }
	    free(array);
	*/
	return 0;
}
