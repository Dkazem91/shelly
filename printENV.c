#include "shell.h"
char *navPath(char *string)
{
	extern char **environ;
	char *copy, *token, *compare = "PATH", *full;
	int i = 0;
	struct stat st;
	if(string == NULL)
		return (NULL);
	checkBuilt(string);
	if(stat(string,&st) == 0)
	  return (string);
	else
	{
		free(full);
	}
	while(environ[i])
	{
		if(_strcmp(environ[i],compare))
			break;
		i++;
	}
	copy = _strdup(environ[i]);
	token = strtok(copy, "=:");
	while(token != NULL)
	{
		full = str_concat("/",string);
		full = str_concat(token,full);
		if(stat(full,&st) == 0)
			return(full);
		token = strtok(NULL,"=:");
	}
	free(full);
	free(copy);
	return (NULL);
}
