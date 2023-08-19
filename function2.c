#include "main.h"
/**
*pased_arguments - function that passes arguments
*@line: pointer that takes a string containing text and tokenize it
*Return: arguments
*/
char **pased_arguments(char *line)
{
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	char *token = strtok(line, " \t\n");
	int arg_index = 0;
	int i;

	if (!arguments)
	{
		perror("error memory allocation");

		for (i = 0; i < arg_index; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		arguments[arg_index] = strdup(token);
		arg_index++;

		if (arg_index >= MAX_ARGUMENTS - 1)
		{
			fprintf(stderr, "too many arguments\n");

			for (i = 0; i < arg_index; i++)
			{
				free(arguments[i]);
			}
			free(arguments);
			break;
		}
		token = strtok(NULL, " \t\n");
	}
	arguments[arg_index] = NULL;
	free(arguments[i]);
	free(arguments);
	return (arguments);
}
/**
*recreated_getenv - function that recreates the use of the command "getenv"
*@name: name of the environ
*Return: NULL or environ
*/
char *recreated_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0)
		{
			if (environ[i][strlen(name)] == '=')
			return (environ[i] + strlen(name) + 1);
		}
	}
	return (NULL);
}
