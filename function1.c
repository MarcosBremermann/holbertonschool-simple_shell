#include "main.h"
/**
 *display_prompt - print symbol $
 */
void display_prompt(void)
{
	fprintf(stdout, "$ ");
	fflush(stdout);
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
