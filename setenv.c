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
	char *newEnv, *compare,*nameCopy,*valCopy;
	int envLen = 0, same = 0;
	int vaLen, i = 0, naLen;

	valCopy = str_concat(valCopy, value);
	nameCopy = str_concat(nameCopy, name);
	vaLen = _strLen(valCopy);
	naLen = _strLen(nameCopy);
	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],nameCopy))
			same = envLen;
		envLen++;
	}

	if (same)
	{
		if(overwrite)
		{
			newEnv = str_concat(nameCopy,"=");
			newEnv = str_concat(newEnv,valCopy);
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
		environ = realloc(environ,envLen + 2);
		newEnv = str_concat(nameCopy,"=");
		newEnv = str_concat(newEnv,valCopy);
		environ[envLen] = newEnv;
		return (0);
	}

}
int main(void)
{
	_setenv("dog","spike",0);
}
