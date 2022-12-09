#include "shell.h"
/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\nJavi & Diego Shell$ ", 16);

}

/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env)
{
	int i = 0;

	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		free_linked_list(env);
		__exit(token);
		i = 1;
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	/* if user types "cd" , it will chnge directory*/
	else if (_strcmp(token[0], "cd") == 0)
	{
		_cd(token, env);
		i = 1;
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @ac: argument count
 * @av: argument vectors
 * @env: envrionmental variables
 * Return: 0 on success
 */

int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int status = 0;
	pid_t pid = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Javi Diego Shell$ ", 15);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		command = NULL;
		i = 0;
		i = _getline(&command);
		if (i == 0)
		{
			free(command);
			free_linked_list(env);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _strtok(command, " ");
		if (n_command != NULL)
			free(n_command);
		if (built_in(token, env))
			continue;
		pid = fork();
		if (pid == 0)
			_execve(token, env);
		else
		{
			wait(status);
			free_double_ptr(token);
		}
	} while (i > 0);
	return (0);
}
