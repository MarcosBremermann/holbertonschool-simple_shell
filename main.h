#ifndef MAIN_H
#define MAIN_H
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void display_prompt();
char *read_command();
char **pased_arguments(char *line);
void execute_command(char *command, char **arguments);
void print_environment();
<<<<<<< HEAD
=======
char *find_executable_path(const char *command, const char *path);
char *recreated_getenv(const char *name);
>>>>>>> b3bc7b77115c278ed5a290a510c70b84730b1d5e

#endif
