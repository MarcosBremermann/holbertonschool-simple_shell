# **Background Context:**
Write a simple UNIX command interpreter.

**Resources:**
Unix shell
Thompson shell
Ken Thompson
Everything you need to know to start coding your own shell concept page

**man or help:**
sh (Run sh as well)

**List of functions and system calls used:**
strcspn
strcmp
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
getline (man 3 getline)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
strtok (man 3 strtok)
waitpid (man 2 waitpid)

**libraries used:**
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

**Compilation:**
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

**Output:**
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

**Testing:**

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

