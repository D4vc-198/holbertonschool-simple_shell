#include "shell.h"


void c_exit(char **str)
{
	_exit(0);
}

/**
 * _execve - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * Return: 0 on success
 */
int _execve(char **s, list_t *env)
{
	char *holder;

	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
		{
			perror("Error:");
			c_exit(s);
		}
	}

	else
	{
		holder = _which(s[0], env);
	}
	if (access(holder, F_OK) != 0)
	{
		perror("error");
		c_exit(s);
	}
	else
	{
		if (execve(holder, s, NULL) == -1)
		{
			perror("Error:");
			c_exit(s);
		}
	}
	return (0);
}
