#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}
/**
 * main - simple shell instance
 *
 * Return: 0
 */
int main (void)
{
  char *buffer = NULL, **args = NULL, *real_arg = NULL;
  size_t size = 0;
	struct stat st;
	int r = 0, i = 1;

	while (1)
	{
		write(STDOUT_FILENO, "shell$ ", 8);
		buffer = getline_func(buffer, size);
		if (buffer == NULL)
			continue;
		args = tokenizer(buffer);
		if(args == NULL)
			return (-1);
		real_arg = args[0];
		if (builtins(args, buffer) == -1)
		{
			if(stat(args[0], &st) == 0)
				r = run_command(args);
			else if(stat(args[0], &st) == -1)
			{
				args[0] = pathfinder(args[0]);
					if(args[0] == NULL)
					  {
					    error_msg(real_arg, i);
					    i++;
					  }
					  else
					  r = run_command(args);
			}
		if (r == -1)
		  {
		    error_msg(real_arg, i);
		    i++;
		  }
		free(args);
		args = NULL;
		free(buffer);
		buffer = NULL;
		}
	}
	return (0);
}

void error_msg(char *real_arg, int i)
{
  write(STDOUT_FILENO,real_arg, _strlen(real_arg));
  write(STDOUT_FILENO,": ", 2);
  _putchar(i + '0');
  write(STDOUT_FILENO,": ", 2);
  write(STDOUT_FILENO, "Not found",10);
  _putchar('\n');  
}
