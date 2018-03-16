#include "shell.h"
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
char **makeStrtok(char *string)
{
	int i =0;
	size_t n = 1;
	char * token;
	char **argv;

	argv = malloc(sizeof(char *));
	token = strtok(string," \n");
	while (token != NULL)
	{
		argv = _realloc(argv,++n * sizeof(char *));
		argv[i] = token;
		token = strtok(NULL," \n");
		i++;
	}

	argv[i] = '\0';
	return (argv);
}
