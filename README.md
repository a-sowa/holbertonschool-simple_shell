# Holberton School - C Project - Simple Shell

## What is a shell ?

A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program that is used for entering data into and displaying or printing data from, a computer or a computing system.

## Project's description

This project is a custom implementation of a UNIX Simple Shell, it was made during the software development program of [Holberton School](https://www.holbertonschool.com/).

### Project's requirements

 * All your files will be compiled on `Ubuntu 20.04 LTS`
 * Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * No more than 5 functions per file
 * All your header files should be include guarded
 * This shell should not have any memory leaks

### Allowed functions

* all functions from string.h
* `isatty` (man 3 isatty)
* `malloc` (man 3 malloc)
* `free` (man 3 free)
* `fork` (man 2 fork)
* `execve` (man 2 execve)
* `wait` (man 2 wait)
* `exit` (man 3 exit)
* `strtok` (man 3 strtok)
* `perror` (man 3 perror)
* `printf` (man 3 printf)
* `fprintf` (man 3 fprintf)
* `strlen` (man 3 strlen)
* `strdup` (man 3 strdup)
* `strcpy` (man 3 strcpy)
* `strncmp` (man 3 strncmp)
* `strcmp` (man 3 strcmp)
* `strerror` (man 3 strerror)
* `getline` (man 3 getline)
* `access` (man 2 access)

## hsh Simple Shell's decription

This program is the recreation of the UNIX shell, a command line interpreter, that allows a user to interact with a computer by running commands or programs. The shell parses the commands and sends them to the operating system to perform.

### The shell should do the following:

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines should handle arguments
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Handle the “end of file” condition (Ctrl+D)
* Handle the PATH
* Implement the exit built-in, that exits the shell
* Implement the env built-in, that prints the current environment
* Handles interactive and non-interactive mode

## Installation and compilation
To start using this program, first, clone the repository 
`https://github.com/a-sowa/holbertonschool-simple_shell.git`

and compile in the following way
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## How to use the program
In your terminal, type `./hsh` to run the program. You will see the prompt `($)` which indicates that it is ready to receive the command. 
Currently, this simple shell handles those *built-in* commands:

`exit` - exits the shell<br />
`env` - prints the current environment variables<br />
ctrl+d - This represent EOF(end of files), and it will exit the prompt and return you to the original shell.

They are run right away. However, if the commands are not built-ins, they are searched for in the `PATH` directory and then are executed. If the command is not found or the user does not have the permission to run it, an error message will be printed.

## TESTING

**Example 1**

Interactive mode

```
($) /bin/ls
AUTHORS             env_variables_printer.c  hsh            line_interpreter.c  main.c  man_1_simple_shell  README.md
command-executor.c  free_double_pointer.c    images_readme  line_parser.c       main.h  path_checker.c
($) ls -la
total 64
drwxr-xr-x 16 vscode vscode   512 Dec 20 16:55 .
drwxr-xr-x 15 vscode vscode   480 Dec 20 16:55 ..
-rw-r--r--  1 vscode vscode    94 Dec 19 13:33 AUTHORS
-rw-r--r--  1 vscode vscode   861 Dec 19 13:33 command-executor.c
-rw-r--r--  1 vscode vscode   215 Dec 19 13:33 env_variables_printer.c
-rw-r--r--  1 vscode vscode   465 Dec 19 13:33 free_double_pointer.c
drwxr-xr-x 14 vscode vscode   448 Dec 20 16:46 .git
-rwxr-xr-x  1 vscode vscode 18336 Dec 19 13:33 hsh
drwxr-xr-x  4 vscode vscode   128 Dec 20 16:54 images_readme
-rw-r--r--  1 vscode vscode   474 Dec 19 13:33 line_interpreter.c
-rw-r--r--  1 vscode vscode  1054 Dec 19 13:33 line_parser.c
-rw-r--r--  1 vscode vscode   853 Dec 19 13:33 main.c
-rw-r--r--  1 vscode vscode   489 Dec 19 13:33 main.h
-rwxr--r--  1 vscode vscode  1424 Dec 20 13:25 man_1_simple_shell
-rw-r--r--  1 vscode vscode   963 Dec 19 13:33 path_checker.c
-rw-r--r--  1 vscode vscode  2414 Dec 20 17:13 README.md
```
**Example 2**

Interactive mode will display the same output as the interactive one

```
echo "/bin/ls" | ./hsh
AUTHORS             env_variables_printer.c  hsh            line_interpreter.c  main.c  man_1_simple_shell  README.md
command-executor.c  free_double_pointer.c    images_readme  line_parser.c       main.h  path_checker.c
```

## MAN PAGE

To display the program's man page, run this command :
`man ./man_1_simple_shell`

## VALGRIND

![Valgrind's output](/images_readme/valgrind_output.png)

## FLOWCHARTS

![hsh Simple Shell's flowchart](/images_readme/flowchart_simple-shell.png)