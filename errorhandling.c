#include"shell.h"
char *itos(int digits)
{
	int count, i, absMod, digitTest;
	char *output;

	count = 0;
	digitTest = digits;
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		absMod = digitTest % 10;
		output[i] = absMod + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);
}
/**
 * errors - error handling
 * @source: pass in arg 0 from argv in main
 * @command: pass in your tokenized arguments from getline
 * @code: code to specify the error message
 */
int errors(char * source, char *command, int code)
{
	int atty = isatty(STDIN_FILENO);
	static int i = 0, eCode = 0;
	char *number;
	if(code > 0)
	{
		if(atty == 0)
		{
			number = itos(++i);
			write(2,source,_strLen(source));
			write(2,": ",2);
			write(2,number,_strLen(number));
			write(2,": ",2);
			free(number);
		}
	}
	if (code == 0)
	{
		eCode = 0;
	}
	if (code == 1)
	{
		//command not a file or directory
		write(2,command,_strLen(command));
		write(2,": not a file or directory\n",27);
		eCode = 0;
	}
	if(code == 2)
	{
		//command not a directory? don't have cd
	}
	if (code == 3)
	{
		write(2,command,_strLen(command));
		if(atty == 0)
			write(2,": not found\n",13);
		else
			write(2,": command not found\n",21);
		if(atty == 0)
		        eCode = 127;
		else
			eCode = 0;
	}
	if(code == 4)
	{
		//permission denied
		write(2,command,_strLen(command));
		write(2,": permission denied\n",21);
		eCode = 126;
	}
	if(code == 5)
	{
		//misuse of shell commmands
	}
	if(code == 6)
	{
		write(2,command,_strLen(command));
		write(2,": exit error\n",14);
		eCode = 128;
	}
	return (eCode);
}
