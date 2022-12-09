#include "shell.h"

/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive -
 * @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int status = 0;
	pid_t pid = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = _getline(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _strtok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		token = NULL;
		token = _strtok(n_line[n], " ");
		if (built_in(token, env))
		{
			n++;
			continue;
		}
		pid = fork();
		if (pid == 0)
			_execve(token, env);
		else
		{
			wait(&status);
			n++;
			free_double_ptr(token);
		}
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(0);
}
