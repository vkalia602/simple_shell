#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct printformat - Struct printformat
 *
 * @form: format specifier
 * @f: function pointer

typedef struct builtins
{
	char *form;
	int (*f)(va_list);
} built_t
*/
char *findpath(void);
char *fix_token(char *argv, char *token);
char *pathfinder(char *argv);
int run_command(char **args);
char **tokenizer(char *buffer);
#endif
