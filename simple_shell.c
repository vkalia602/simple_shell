#include "shell.h"


/**
 * main - simple shell instance
 *
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL, **args = NULL;
	size_t size = 0;
	struct stat st;
	int r;

	while (1)
	{
		write(STDOUT_FILENO, "s_hell$ ", 9);
		if (getline(&buffer, &size, stdin) == EOF)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
		}
		buffer = getline_func(buffer, size);
		if (buffer == NULL)
			break;
		args = tokenizer(buffer);
		if (args == NULL)
			return (-1);
		if (builtins(args, buffer) == -1)
		{
			if (stat(args[0], &st) == 0)
				r = run_command(args);
			else if (stat(args[0], &st) == -1)
			{
				args[0] = pathfinder(args[0]);
					if (args[0] == NULL)
						perror("Error");
					else
						r = run_command(args);
			}
		if (r == -1)
			perror("Error:");

		free(args);
		args = NULL;
		free(buffer);
		buffer = NULL;
		}
	}
	return (0);
}

/**
 * free_func - frees memory of arg valued space
 *
 * @args: arguments
 */
void free_func(char **args)
{
	int i = 0;

	if (args == NULL)
		return;
	while (args != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * getline_func - reads input from user
 *
 * @buffer: storage space for input
 * @size: size in bytes of input
 */
char *getline_func(char *buffer, size_t size)
{
	int x;

	x = getline(&buffer, &size, stdin);

	if (x == 1 || x == -1 || buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
