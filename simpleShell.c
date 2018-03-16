#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
void *_realloc(void *ptr, unsigned int new_size)
{
	void *ret = 0;
	char *write, *read;

	if (new_size > 0 || ptr == 0)
	{
		ret = malloc(new_size);
		if (ret == 0)
			return (0);
	}
	if (new_size > 0 && ptr != 0)
	{
		write = ret;
		read = ptr;
		while (new_size)
		{
			new_size--;
			*write++ = *read++;
		}
	}
	free(ptr);
	return (ret);
}
int main (void)
{
	int i = 0;
	char **argv;
	char *command = NULL;
	char *token;
	size_t n = 1;
	while(i == 0)
	{
		if(fork() == 0)
		{

			printf("my super simple shell ");
	        	getline(&command,&n,stdin);
			argv = malloc(sizeof(char *));
			token = strtok(command, " \n");
			while (token != NULL)
			{
				argv[i] = token;
				argv = _realloc(argv,++n * sizeof(char *));
				token = strtok(NULL, " \n");
				i++;
			}
			argv[i] = NULL;
			execve(argv[0],argv,NULL);
		}
		else
		{
			wait(NULL);
		}
	}

	free(argv);
	return(0);
}
