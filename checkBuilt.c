#include "shell.h"
void checkBuilt(char *string)
{
	if(_strcmp(string,"exit"))
	{
		exit(0);
	}
}
