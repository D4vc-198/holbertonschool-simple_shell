#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */

char *_which(char *str, char **env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0, f = 0, t = 0;

	pth = get_env("PATH", env);
	i = 1;
	while (pth[i] != '\0')
	{
		if (pth[i - 1] == ':')
		{
			if (pth[i] == ':')
				t = 1;
			else if (i == 1)
				t = 1;
		}
		i++;
	}

	if (t == 1)
	{
		cat = getcwd(cat, 0);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free(pth);
			return (cat);
		}
		free(cat);
	}
	toks = _strtok(pth, ":");
	free(pth);
	i = 0;
	while (toks[i] != NULL)
	{
		cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			while (toks[f] != NULL)
			{
				free(toks[f]);
				f++;
			}
			free(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	while (toks[f] != NULL)
	{
		free(toks[f]);
		f++;
	}
	free(toks);
	return (str);
}
