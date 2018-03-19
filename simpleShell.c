#include "shell.h"
int main (void)
{
	int i = 0;
	char **argv, *command,*token,*filePath;

	while(i == 0)
	{

		printf("my super simple shell ");
		command = getLine();
		argv = makeStrtok(command);
		filePath = navPath(argv[0]);
		argv[0] = filePath;
		if(fork() == 0)
		{
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
