#include "shell.h"
int _strLen(char *string)
{
	int len = 0;
	while(string[len])
		len++;
	return len;
}
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char **envCopy;
	char *newEnv, *compare,*nameCopy,*valCopy,*newPath;
	int envLen = 0, same = 0;
	int vaLen, i, naLen;

	if (name == NULL || _findC(name,'='))
		return (-1);
	envCopy = environ;
	valCopy = str_concat(NULL, value);
	nameCopy = str_concat(NULL, name);
	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],nameCopy))
		{
			same = envLen;
		}
		envLen++;
	}

	if (same)
	{
		if(overwrite)
		{
			newEnv = str_concat(nameCopy,"=");
			newPath = str_concat(newEnv,valCopy);
			free(newEnv);
			environ[same] = newPath;
			i = 0;
			free(nameCopy);
			free(valCopy);
			return(0);
		}
		else
		{
			free(nameCopy);
			free(valCopy);
			return(0);
		}

	}
	envCopy = malloc((envLen + 2) * sizeof(char*));
	for(i = 0; i < envLen; i++)
	{
		char *envVar = str_concat(NULL,environ[i]);
		envCopy[i] = envVar;
	}
	int j = 0;
	newEnv = str_concat(nameCopy,"=");
	newEnv = str_concat(newEnv,valCopy);
	envCopy[i] = newEnv;
	envCopy[i + 1] = NULL;
	environ = envCopy;
	i = 0;
	while(environ[i])
	{
		printf("%s\n",environ[i]);
		i++;
	}
	free(nameCopy);
	free(valCopy);
	return (0);

}
int _unsetenv(const char *name)
{
	extern char **environ;
	int envLen = 0, same = -1;

	if (name == NULL || _findC(name,'='))
		return (-1);

	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],name))
		{
			same = envLen;
		}
		envLen++;
	}
	if(same == -1)
		return (0);
	while(environ[same])
	{
		environ[same] = environ[same + 1];
		same++;
	}

}
