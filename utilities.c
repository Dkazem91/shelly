#include "shell.h"
int _strcmp(char *s1, char *s2)
{
        int i = 0;

        while(s2[i])
        {
                if(s1[i] != s2[i])
                        break;
                i++;
        }
        if (s2[i] == '\0')
                return (1);
        return (0);
}
char *_strdup(char *str)
{
        int i;
        int c = 0;
        char *t;

	if (str == NULL)
                return (NULL);

        while (str[c] != '\0')
                c++;

        t = malloc(sizeof(char) * c + 1);

        if (t == NULL)
                return (NULL);

        for (i = 0; i < c; i++)
		t[i] = str[i];

        return (t);

}
char *str_concat(char *s1, char *s2)
{
	int i, len1, len2;
        char *conc;

	i = 0;
        len1 = 0;
	len2 = 0;
	if (s1 == NULL)
		s1 = "";
        if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
        {
                i++;
                len1++;
        }

	i = 0;
        while (s2[i] != '\0')
        {
                i++;
                len2++;
        }
	conc = malloc(sizeof(char) * (len1 + len2 + 1));
        if (conc == NULL)
		return (NULL);

        for (i = 0; i < len1; i++)
        {
		conc[i] = s1[i];
        }

        for (i = 0; i < len2; i++)
	{
                conc[i + len1] = s2[i];
        }
	conc[i + len1] = '\0';
	return (conc);
}
