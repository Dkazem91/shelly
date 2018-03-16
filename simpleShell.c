#include "shell.h"
int main (void)
{
	int i = 0;
	char **argv;
	char *command;
	char *token;
	char *filePath;
	while(i == 0)
	{
		if(fork() == 0)
		{

			printf("my super simple shell ");
	        	command = getLine();
			argv = makeStrtok(command);
			filePath = getPath(argv[0]);
			argv[0] = filePath;
			execve(argv[0],argv,NULL);
		}
		else
		{
			wait(NULL);
		}
	}

	free(argv);
	return(0);
}
