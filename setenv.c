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
	char *newEnv, *compare;
	int envLen = 0, same = 0,vaLen = _strLen(value), i = 0, naLen = _strLen(name);

	while(environ[len])
	{
		if (_strcmp(environ[len],name))
			same = envLen;
		envLen++;
	}

	if (same)
	{
		if(overwrite)
		{
			newEnv = str_concat(name,"=");
			newEnv = str_concat(newEnv,value);
			environ[same] = newEnv;
			return(0);
		}
		else
		{
			return(0);
		}

	}
	else
	{
		environ = realloc(environ,envLen + 1);
		newEnv = str_concat(name,"=");
		newEnv = str_concat(newEnv,value);
		environ[envLen + 1] = newEnv;
		return (0);
	}

}
