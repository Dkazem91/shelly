#include "shell.h"
char *getLine(void)
{
	char *line = NULL;
	ssize_t read;
	size_t len = 0;

	getline(&line, &len,stdin);
	return(line);
}
