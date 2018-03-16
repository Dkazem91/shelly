#include "shell.h"
int _strLen(char *string)
{
	int len = 0;

	while(string[len])
		len++;
	printf("%dLENGTH\n", len);
	return(len);
}
char *_strcat(char *dest, char *src)
{
	int i,j;

	for (j = 0; dest[j] != '\0'; j++)
	{}
	for (i = 0; src[i] != '\0'; i++)
		dest[j + i] = src[i];
	dest[j + i] = '\0';
	return (dest);
}
char *getPath(char *string)
{
	char s1[100] = "/bin/",s2[100] = "./", *p;
	struct stat st;

	if(stat(string, &st) == 0)
		return(string);
    	p = _strcat(s1,string);
	if(stat(p,&st) == 0)
		return(p);
	p = _strcat(s2,string);
	if(stat(p,&st) == 0)
		return(p);

	perror("no path found");
	exit(1);
}
