#include "shell.h"
char *getLine(int code)
{
	char *line = NULL;
	ssize_t read;
	size_t len = 0;

	if(isatty(STDIN_FILENO))
		write(1,"#cisfun$ ",10);
	read = getline(&line, &len,stdin);
	if(read  <= 0)
	{
		_exit(code);
	}
	line[read] = '\0';
	return(line);
}
