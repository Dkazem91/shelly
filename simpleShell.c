#include "shell.h"
int main (int ac, char *argv[])
{
	int i = 0,status,built,freeflag = 0, filePath;
	extern char **environ;
	char **argvs, *command,*token;
	size_t len = 0;
	pid_t child;

	signal(SIGINT,SIG_IGN);
	while(i == 0)
	{
		command = getLine();
		argvs = makeStrtok(command);
		i = 0;
		built = checkBuilt(ac, argvs);
		if(built == 0)
		{
			filePath = navPath(&argvs[0],&freeflag);
		}
		if(filePath != 0)
			errors(argv[0],argvs[0],filePath);
		if(argvs[0] == NULL || built != 0 || filePath != 0)
		{
			free(argvs);
			free(command);
			continue;
		}
		child = fork();
		if(child == 0)
		{
			if(execve(argvs[0],argvs,environ) == -1)
			{
				errors(argv[0],argvs[0],4);
			}
		}
		else
		{
			wait(&status);
		}
		free(argvs);
		free(command);
	}
}
