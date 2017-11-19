#include "shell.h"

extern char **environ;
char *findpath(void)
{
	char *token, *copy;
	char keyword[] = "PATH";
	int i = 0;

	while (environ[i] != NULL)
	{
		copy  = strdup(environ[i]);
		if(copy == NULL)
		{
			free(copy);
			return (NULL);
		}
		token = strtok(copy, "=");
		if (strcmp(token, keyword) == 0)
		{
			free(copy);
			return (environ[i]);
		}
		i++;
	}
	free(copy);
	return (NULL);
}

char *fix_token(char *argv, char *token)
{
	char *new_token;
	int i = 0, j = 0, total_strlen = 0;

	total_strlen = (strlen(argv)) + (strlen(token));
	new_token = malloc(total_strlen * sizeof(char) + 2);
	if (new_token == NULL)
	{
		free(new_token);
		return (NULL);
	}
	while(token[i] != '\0')
	{
		new_token[i] = token[i];
		i++;
	}
	new_token[i] = '/';
	while(argv[j] != '\0')
	{
		new_token[i + 1] = argv[j];
		j++;
		i++;
	}
	new_token[i + 1] = '\0';
	return(new_token);
}

char *pathfinder(char *args)
{
	char *dir;
	char *token, *new_token, *holder_token;
	struct stat st;

	dir = findpath();
	dir = strdup(dir);
	if (dir == NULL)
	{
		free(dir);
		return(NULL);
	}
	token = strtok(dir, "=:");
	while (token != NULL)
	{
		holder_token = token;
		new_token = fix_token(args, holder_token);
		if(new_token == NULL)
		{
			free(dir);
			free(new_token);
			return (NULL);
		}
		if(stat(new_token, &st) == 0)
		{
			free(dir);
			return (new_token);
		}
		token = strtok(NULL, "=:");
	}
	free(dir);
	return (NULL);
}
