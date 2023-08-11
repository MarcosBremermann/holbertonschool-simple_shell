# **C Simple Shell Project**
This is a simple UNIX command interpreter based off bash and sh. The shell allows users to interact with the operating system by entering commands.

## Resources:
- Unix shell
- Thompson shell
- Ken Thompson
- "Everything you need to know to start coding your own shell" concept page

## man or help:
sh (Run sh as well)


## Libraries used:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

## Code Organization

1. `main.h`: Header file containing function declarations and necessary includes.
2. `shellfuncional.c`: Contains functions for displaying the prompt, reading commands, and executing them.
3. `mainbucle.c`: Implements the main loop of the shell, parsing user input, and executing commands.


## Installation:
To use this shell, follow this steps:
1. Copy/Download all the files in this github repository into your own personal directory.
2. Compile them all using the following compiler: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
3. Run the shell using "./hsh" and now you're ready to go!

## Output:
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

*Example of error with sh:*

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

*Same error with your program hsh:*

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

## Testing:

*Your shell should work like this in interactive mode:*

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

*But also in non-interactive mode:*

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
