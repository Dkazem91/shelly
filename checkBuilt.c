#include "shell.h"
int checkBuilt(int ac, char **argv)
{
	extern char **environ;
	int i = 0;

	if(_strcmp(argv[0],"exit"))
	{
		exit(1);
	}

	if(_strcmp(argv[0],"setenv"))
	{
		if(ac == 4)
		{
			int overwrite = argv[3][0] - '0';
			_setenv(argv[1],argv[2],overwrite);
			return (1);
		}
		else
			return(0);
	}
	if(_strcmp(argv[0],"unset"))
	{
		_unsetenv(argv[1]);
		return(1);
	}
	if(_strcmp(argv[0],"printenv"))
	{
		while(environ[i])
		{
			write(STDIN_FILENO,environ[i],_strLen(environ[i]));
			i++;
		}
	}
	if(_strcmp(argv[0],"history"))
		return(2);
	return (0);
	if(_strcmp(argv[0],"showPID"))
	{
		return(3);
	}
}
