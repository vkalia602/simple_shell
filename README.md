# Custom Shell

This project is a simpler rendition of the actual SHELL which was built as a project in Holberton School.

## Getting Started

This repository can be cloned using the https link given below.

>https://github.com/vkalia602/simple_shell.git

The executable of this repo was compiled using the following flags.

> gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Using the -o flag, the executable program is renamed hsh and can be executed using >./hsh 
command.

### Repository Contents

|  **File Name**  |   **Description**   |
| --------------- | ------------------- |
| builtins.c | This file consists functions like builtins, printenv, exitfunc and initialized struct for the built-ins |
| pathfinder.c | File contains findpath, fix token, and pathfinder functions. |
| run_command.c| File contains functions like run_command and getline_func |
| shell.h| Library file for all the functions used in the project include the defined struct for the builtins.|
| simple_shell.c | This file contains the main function which is the entry point for the arguments and contains function to print error messages.|
| string_funcs.c | File contains string manipulations function like strcmp, strlen, strdup, strcpy and putchar. All the functions are custom made in C. |
| tokenizer.c | File contains tokenizing function that parses string into tokens |

### List of Functions
| Function Name | Description |
|---------------- | -----------|
|[findpath](https://github.com/vkalia602/simple_shell/blob/master/pathfinder.c)   | Searches the environment for PATH. |
|[fix_token](https://github.com/vkalia602/simple_shell/blob/master/pathfinder.c) | Function concatenats directory with the input command. |
|[pathfinder](https://github.com/vkalia602/simple_shell/blob/master/pathfinder.c) | Function finds the directory a command is located in and returns the command concatenated with the directory |
|[builtins](https://github.com/vkalia602/simple_shell/blob/master/builtins.c) | Functions contains list of built-in commands and determines if the argument recieved is a built in. |
|[printenv](https://github.com/vkalia602/simple_shell/blob/master/builtins.c) | Function prints the environment using the double pointer **environ global variable. |
|[exitfunc](https://github.com/vkalia602/simple_shell/blob/master/builtins.c) | Function exits out of the shell. |
|[run_command](https://github.com/vkalia602/simple_shell/blob/master/run_command.c) | Function creates a child process and executed the appropriate command |
|[getline_func](https://github.com/vkalia602/simple_shell/blob/master/run_command.c) | Function uses getline function to read input from the user. | 
|[_strcmp](https://github.com/vkalia602/simple_shell/blob/master/string_funcs.c) | Compares two strings |
|[_strdup](https://github.com/vkalia602/simple_shell/blob/master/string_funcs.c) | Duplicates a string.|
|[_strlen](https://github.com/vkalia602/simple_shell/blob/master/string_funcs.c) | Function returns length of a string. |
|[_strcpy](https://github.com/vkalia602/simple_shell/blob/master/string_funcs.c) | Function copies string from source into destination and returns the string |
|[_putchar](https://github.com/vkalia602/simple_shell/blob/master/string_funcs.c) | Writes a char to the stdout |
|[tokenizer](https://github.com/vkalia602/simple_shell/blob/master/tokenizer.c) | Function parses the string into tokens. |

### Example

```
$ ./hsh
shell$ ls -l
total 40
-rw-rw-r-- 1 vagrant vagrant 1098 Nov 20 22:09 builtins.c
-rw-rw-r-- 1 vagrant vagrant 1323 Nov 20 22:26 man_page
-rw-rw-r-- 1 vagrant vagrant 1936 Nov 20 23:53 pathfinder.c
-rw-rw-r-- 1 vagrant vagrant 3813 Nov 21 04:21 #README.md#
-rw-rw-r-- 1 vagrant vagrant 1804 Nov 21 03:47 README.md
-rw-rw-r-- 1 vagrant vagrant  855 Nov 21 00:22 run_command.c
-rw-rw-r-- 1 vagrant vagrant  902 Nov 20 23:41 shell.h
-rw-rw-r-- 1 vagrant vagrant 1347 Nov 21 02:41 simple_shell.c
-rw-rw-r-- 1 vagrant vagrant 1229 Nov 20 21:50 string_funcs.c
-rw-rw-r-- 1 vagrant vagrant  444 Nov 20 22:16 tokenizer.c


```
### Return Value

Shell will exit with a status of 0 on the >exit< command. On error, shell will print the error with a new command line.

### Authors

Sue Kalia and Jerel Henderson