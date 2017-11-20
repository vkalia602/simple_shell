# Custom Shell

A Shell Within a Shell

## Getting Started

First things first, you'll want to compile the C files

> gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

From there, you can enter the shell from any other shell environment using

> ./hsh

## Work It

The Custom Shell is capable of running both custom builtin commands and their optional flags, along with $PATH commands and their optional flags. You can make use of these commands the same way you would in any other shell environment.

Currently working builtin commands are

> env

> exit

## Work It Harder

Example of a custom shell success

```
s_hell$ echo "qwerty"
qwerty
s_hell$
```

Example of a custom shell error

```
s_hell$ echo "qwerty"
qwerty: not found
s_hell$
```

## Credit

Credit goes to Vasudha (Sue!) Kalia and Jerel Henderson. You can find our repositories [@vkalia602](https://github.com/vkalia602) and [@jerelhenderson](https://github.com/jerelhenderson).
