# **C Simple Shell Project**
<div align="center">
  <a href="https://holbertonschool.uy">
    <img src="https://ml.globenewswire.com/Resource/Download/a08e6c28-55be-44c8-8461-03544f094b38" align="center" height="250" width="650" />
  </a>
</div>

This is a simple UNIX command interpreter based off bash and sh. The shell allows users to interact with the operating system by entering commands.

## Resources:
- Unix shell
- Thompson shell
- Ken Thompson
- "Everything you need to know to start coding your own shell" concept page

## Libraries used:
- #include <stdio.h>
- #include <stdlib.h>
- #include <unistd.h>
- #include <string.h>
- #include <sys/wait.h>

## Commands used
- <a href="https://man7.org/linux/man-pages/man3/printf.3.html" target="_blank">printf</a>
- <a href="https://man7.org/linux/man-pages/man3/fprintf.3p.html" target="_blank">fprintf</a>
- <a href="https://man7.org/linux/man-pages/man3/sprintf.3p.html" target="_blank">sprintf</a>
- <a href="https://man7.org/linux/man-pages/man3/perror.3.html" target="_blank">perror</a>
- <a href="https://man7.org/linux/man-pages/man3/fflush.3.html" target="_blank">fflush</a>
- <a href="https://man7.org/linux/man-pages/man3/malloc.3p.html" target="_blank">malloc</a>
- <a href="https://man7.org/linux/man-pages/man3/free.3.html" target="_blank">free</a>
- <a href="https://man7.org/linux/man-pages/man3/getline.3.html" target="_blank">getline</a>
- <a href="https://man7.org/linux/man-pages/man3/exit.3.html" target="_blank">exit</a>
- <a href="https://man7.org/linux/man-pages/man3/access.3.html" target="_blank">access</a>
- <a href="https://man7.org/linux/man-pages/man3/fork.3.html" target="_blank">fork</a>
- <a href="https://man7.org/linux/man-pages/man3/excev.3.html" target="_blank">excev</a>
- <a href="https://man7.org/linux/man-pages/man3/isatty.3.html" target="_blank">isatty</a>
- <a href="https://man7.org/linux/man-pages/man3/strlen.3.html" target="_blank">strlen</a>
- <a href="https://man7.org/linux/man-pages/man3/strtok.3.html" target="_blank">strtok</a>
- <a href="https://man7.org/linux/man-pages/man3/strdup.3.html" target="_blank">strdup</a>
- <a href="https://man7.org/linux/man-pages/man3/strchr.3.html" target="_blank">strchr</a>
- <a href="https://man7.org/linux/man-pages/man3/strcmp.3.html" target="_blank">strcmp</a>
- <a href="https://man7.org/linux/man-pages/man3/strncmp.3.html" target="_blank">strncmp</a>
- <a href="https://man7.org/linux/man-pages/man3/strcspn.3.html" target="_blank">strcspn</a>
- <a href="https://man7.org/linux/man-pages/man3/waitpid.3.html" target="_blank">waitpid</a>

## Code Organization

1. `main.h`: Header file containing function declarations and necessary includes.
2. `function1.c`: This file contains the display_prompt and read_command functions.
3. `function2.c`: This file contains the functions passed_arguments and recreated_getenv
4. `function3.c`: This file contains the find_executable_path, execute_command and print_environment functions.
5. `mainbucle.c`: Implements the main loop of the shell, parsing user input, and executing commands.

## What's the purpose of each function:

*display_prompt* - This function displays the prompt symbol ("$") on standard output, indicating that the program is ready to receive user commands.

*read_command* - This function reads the command line typed by the user from standard input and stores it in a buffer.

*passed_arguments* - This function takes the command line entered by the user and splits it into individual arguments.

*recreated_getenv* - This function searches the environment for the value associated with a specific variable whose name is passed as an argument, and if found, it returns the value of the variable. If it isn't found it returns NULL.

*find_executable_path* - This function looks up the full path of the executable of the given command in a PATH environment variable. If it finds the executable, it returns its full path; otherwise, it returns NULL.

*execute_command* - This function executes the command passed by the user, handles both commands with absolute paths and commands in the system PATH.

*print_environment* - This function prints all environment variables to standard output.

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

## Contact & help
For any bugs or doubts you can contact both creators through our contacts:
- Iamara Barrios
    - Gmail: 6753@holbertonstudents.com
    - <a href="https://www.linkedin.com/in/iamara-barrios-6216b026a/">Linkedin Profile</a>

- Marcos Bremermann
    - Gmail: 6746@holbertonstudents.com
    - <a href="https://www.linkedin.com/in/marcos-bremermann-71839423a/">Linkedin Profile</a>
