#include "main.h"
/**
 *display_prompt - print symbol $
 */
void display_prompt(void)
{
	fprintf(stdout, "$ ");
}

#define MAX_ARGUMENTS 64

/**
 *read_command - read command  write for the user
 *
 *Return: line or NULL
 */
char *read_command()
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	characters_read = getline(&line, &bufsize, stdin);

	if (characters_read == -1)
	{
		free(line);
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';

	return (line);
}
/**
 *execute_command - execute command write for the user
 *@command: char
 */
void execute_command(char *command)
{
	pid_t pid;

	if ((pid = fork()) == 0)
	{
		char *envp[] = {NULL};
		char *args[2];

		args[0] = command;
		args[1] = NULL;

		if (execve(command, args, envp) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
	perror("Error");
	}
	else
	{
	waitpid(pid, NULL, 0);
	}
}

