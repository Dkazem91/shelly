#include "shell.h"
int main (void)
{
	int i = 0;
	extern char **environ;
	char **argv, *command,*token,*filePath;
	size_t len = 0;

	while(i == 0)
	{
		command = getLine();
		argv = makeStrtok(command);
		filePath = navPath(argv[0]);
		argv[0] = filePath;
		if(fork() == 0)
		{
			execve(argv[0],argv,environ);
			printf("error after execute\n");
			i = 1;
		}
		else
		{
			wait(NULL);
		}
		free(command);
	}

	free(argv);
	return(0);
}
