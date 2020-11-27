# Kath and Dav's Shell

<div style="width: 50%; text-align:center;
box-shadow: 1px 2px 47px 21px rgba(0,0,0,0.75);"
><img src="https://automatedprogrammer.sh/wp-content/uploads/2018/05/Linux-Shell.png" /></div>


## Description 
Kath and Dav's Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C.

## Installation
Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

```
$ gcc -Wall -Werror -pedantic -o shell *c
```

## Usage
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.


### Interactive Mode
```
simple_shell$ ./shell
```
||

### Non-Interactive Mode
```
simple_shell$ echo "ls -ls" | ./shell
```
Our shell has support for the following built-in commands:


| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.|



#### Outside Programs

Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), IF their directory is included in the PATH.

### Examples

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

### Included Files





