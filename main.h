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
#include <sys/stat.h>

void display_prompt(void);
char *read_command();
char **pased_arguments(char *line);
void execute_command(char *command, char **arguments, char **line);
void print_environment(void);
char *find_executable_path(const char *command, const char *path);
char *recreated_getenv(const char *name);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
extern char **environ;

#endif
