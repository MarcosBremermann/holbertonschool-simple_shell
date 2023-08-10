#ifndef MAIN_H
#define MAIN_H
#define MAX_COMMAND_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void display_prompt();
char *read_command();
void execute_command(char *command);

#endif
