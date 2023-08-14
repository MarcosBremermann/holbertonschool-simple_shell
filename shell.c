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
*pased_arguments - pasa argumento
*@line: linea pasada
*Return: argumento pasado
*/
char **pased_arguments(char *line)
{
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	char *token = strtok(line, " ");
	int arg_index = 0;

	if (!arguments)
	{
		perror("error memory allocation");
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		arguments[arg_index] = token;
		arg_index++;

		if (arg_index >= MAX_ARGUMENTS - 1)
		{
			fprintf(stderr, "too many arguments\n");
			break;
		}

		token = strtok(NULL, " ");
	}
	arguments[arg_index] = NULL;
	return (arguments);
}
/**
 *execute_command - execute command write for the user
 *@command: char
 *@arguments: char
 */
void execute_command(char *command, char **arguments)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(command, arguments) == -1)
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

