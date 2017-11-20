#include "shell.h"


/**
 * run_command - executes given input
 *
 * @args: arguments given
 * Return: 0
 */
int run_command(char **args)
{
	pid_t child_pid;
	int status;

	if (args == NULL)
		return (-1);

	child_pid = fork();
	if (child_pid < 0)
	{
		printf("Error");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			return (-1);
	}
	else
		child_pid = wait(&status);
	return (0);
}
