#include "shell.h"

char **tokenizer(char *buffer)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 5);
	if (tokens == NULL)
		return (NULL);
        token = strtok(buffer, " \n\t");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
