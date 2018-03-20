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
	char *newEnv, *compare,*nameCopy,*valCopy;
	int envLen = 0, same = 0;
	int vaLen, i, naLen;

	envCopy = environ;
	valCopy = str_concat(NULL, value);
	nameCopy = str_concat(NULL, name);
	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],nameCopy))
		{
			printf("FOUND A MATCH \n");
			same = envLen;
		}
		envLen++;
	}

	if (same)
	{
		printf("i'm in here!\n");
		if(overwrite)
		{
			printf("I'm in overwrite too!\n");
			newEnv = str_concat(nameCopy,"=");
			newEnv = str_concat(newEnv,valCopy);
			environ[same] = newEnv;
			i = 0;
			while(environ[i])
				printf("%s\n",environ[i++]);
			return(0);
		}
		else
		{
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
	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],name))
		{
			printf("FOUND A DELETE \n");
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
	same = 0;
	while(environ[same])
		printf("%s\n",environ[same++]);

}
int main (void)
{
	_setenv("dog","whatever",0);
	_unsetenv("dog");
}
