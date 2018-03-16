#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
	int i = 0;
	char **argv;
	char *command = NULL;
	char *token;
	size_t n = 1;
	while(i == 0)
	{
		if(fork() == 0)
		{

			printf("my super simple shell ");
	        	getline(&command,&n,stdin);
			argv = malloc(sizeof(char *));
			token = strtok(command, " \n");
			while (token != NULL)
			{
				argv[i] = token;
				argv = realloc(argv,++n * sizeof(char *));
				token = strtok(NULL, " \n");
				i++;
			}
			argv[i] = NULL;
			execve(argv[0],argv,NULL);
			free(argv);
		}
		else
		{
			wait(NULL);
		}
	}
}
