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

#endif
