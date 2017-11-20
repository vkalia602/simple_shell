#include "s_hell.h"



/**
 *
 *
 *
 */
int runcmds(char **argv)
{
	int idx;

	idx = 0;

	bin bin_list[] = {
		{"env", hellEnv},
		{"exit", hellEsc},
		{NULL, NULL}
	};

	while (bin_list[idx].sin != NULL)
	{
		printf("loop- %s\n", bin_list[idx].sin);
		if (strcmp(argv[0], bin_list[idx].sin) == 0)
			bin_list[idx].f(argv);
		idx++;
	}
	return (0);
}

int hellEnv(char **argv)
{
	(void) argv;

	int idx;
	int len;

	idx = 0;
	len = 0;

	while (environ[idx] != NULL)
	{
		len = strlen(environ[idx]);
		write(STDOUT_FILENO, environ[idx], len);
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
	return (0);
}

int hellEsc(char **argv)
{
	(void)argv;
	printf("Found function\n");
	return(0);
}
