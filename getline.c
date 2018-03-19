#include "shell.h"
char *getLine(void)
{
	char *line = NULL;
	ssize_t read;
	size_t len = 0;

	printf("my super simple shell ");
	if(getline(&line, &len,stdin) == -1)
		exit(-1);
	return(line);
}
