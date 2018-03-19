#include "shell.h"
char *getLine(void)
{
	char *line = NULL;
	ssize_t read;
	size_t len = 0;

	printf("my super simple shell ");
	read = getline(&line, &len,stdin);
	if(read <= 0)
	{
		perror("error");
		exit(99);
	}
	printf("%ld\n", read);
	return(line);
}
