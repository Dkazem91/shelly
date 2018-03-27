#include "shell.h"
int line = 0;
int main (int ac, char *argv[])
{
	int i = 0,status,built,freeflag = 0, filePath = 0,eCode = 0,j;
	char **argvs, *command,*token;
	size_t len = 0;
	pid_t child;

	signal(SIGINT,SIG_IGN);
	envCopy();
	while(i == 0)
	{
		command = getLine(eCode);
		line++;
		argvs = makeStrtok(command);
		for(j = 0;argvs[j];j++)
		built = checkBuilt(j, argvs, argv[0],eCode);
		if(built == 0)
		{
			filePath = navPath(&argvs[0],&freeflag);
			eCode = errors(argv[0],argvs,filePath);
		}
			eCode = built;
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
				errors(argv[0],argvs,4);
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
