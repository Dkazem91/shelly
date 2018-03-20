#include "shell.h"
int main (void)
{
	int i = 0,status;
	extern char **environ;
	char **argv, *command,*token,*filePath;
	size_t len = 0;
	pid_t child;

	while(i == 0)
	{
		command = getLine();
		argv = makeStrtok(command);
		filePath = navPath(argv[0]);
		argv[0] = filePath;
		child = fork();
		if(child == 0)
		{
			execve(argv[0],argv,NULL);
			exit(99);
		}
		if(child == -1)
		{
			exit(1);
		}
		wait(&status);
		free(argv[0]);
		free(argv);
	}
}
