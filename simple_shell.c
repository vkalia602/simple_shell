#include "shell.h"

int main (void)
{
	char *buffer = NULL, **args;
	size_t size;
	struct stat st;
	int r;

	while (1)
	{
		write(STDOUT_FILENO, "s_hell$ ", 9);
		if (getline(&buffer, &size, stdin) == -1)
		{
			free(buffer);
			break;
		}
		args = tokenizer(buffer);
		/*if (builtins(args) == -1)*/
		if(stat(args[0], &st) == 0)
		   r = run_command(args);
		if(stat(args[0], &st) == -1)
		{
			args[0] = pathfinder(args[0]);
			if(args[0] == NULL)
				perror("pathfinder error");
			else
				r = run_command(args);
		}
		if (r == -1)
			perror("error: command not found");
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
