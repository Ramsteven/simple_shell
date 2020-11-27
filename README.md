<h1 align= "center">Kath and Dav's Shell  :computer:</h1>

<p align="center">
<a href ="https://github.com/Ramsteven/simple_shell">
  <img width="300" height="300" src="https://automatedprogrammer.sh/wp-content/uploads/2018/05/Linux-Shell.png">
  </a>
</p>

## Description  :computer:
Kath and Dav's Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C.

## Installation :computer:
Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

```
$ gcc -Wall -Werror -pedantic -o shell *c
```

## Usage :computer:
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.


### Interactive Mode
```
simple_shell$ ./shell
```

### Non-Interactive Mode
```
simple_shell$ echo "ls -ls" | ./shell
```
Our shell has support for the following built-in commands:


| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.|



## Outside Programs :computer:

Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), IF their directory is included in the PATH.

### Examples :computer:

```sh
katydav$ ls -l
total 8
drwxrwxr-x 1 vagrant vagrant Apr 2 13:23 directory_1
drwxrwxr-x 2 vagrant vagrant Apr 2 20:30 directory_2
```

```sh
katydav$ /bin/pwd
/home/vagrant/shell
```

```sh
katydav$ hello world
./hsh: 1: hello: not found
```

## Included Files

#### - Files in the Repository 🖇️

#|Directory|Description
---|---|---
1|[README.md](./README.md)| You are reading it
2|[_which.c](./_which.c)| Function that allow iteration with enviorment variable.
3|[auxiliar_functions.c](./auxiliar_functions.c)| Functions that allow change, count and manipulate the strings literals received of users
4|[auxiliar_functions_2.c](./auxiliar_functions_2.c)| Function for manage built-ins commands.
5|[check_command.c](./check_command.c)| Function that check and define  the command typed.
6|[holberton.h](./holberton.h)| Header file with the structure and the prototypes of the functions
7|[man_1_simple_shell](./man_1_simple_shell)| Man page of our function
8|[manage_error.c](./manage_error.c)| Function that manage type command error.
9|[shell.c](./shell.c)|Main function that read the all things works.


## Credits

All code written by [katgzco](https://github.com/katgzco) and [Ramsteven](https://github.com/Ramsteven).



