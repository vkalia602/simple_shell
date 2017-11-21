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
		if(execve(args[0], args, NULL) == -1)
			return (-1);
	}
	else
		child_pid = wait(&status);
	return (0);
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
  if (x  == EOF)
    {
      free(buffer);
      write(STDOUT_FILENO, "\n", 1);
      exit(0);
    }
  if(x == 1 || x == -1 || buffer == NULL)
    {
      free(buffer);
      return(NULL);
    }
  return(buffer);
} 
