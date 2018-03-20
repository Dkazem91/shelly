#include "shell.h"
int checkBuilt(char **argv)
{
	int found = 0, i = 0;
	while(argv[i])
		i++;
	if(_strcmp(argv[0],"exit"))
	{
		exit(1);
	}

	if(_strcmp(argv[0],"setenv"))
	{
		int overwrite = argv[3][0] - '0';
		_setenv(argv[1],argv[2],overwrite);
		return(1);
	}
	if(_strcmp(argv[0],"unset"))
	{
		_unsetenv(argv[1]);
		return(1);
	}
	return (0);
}
