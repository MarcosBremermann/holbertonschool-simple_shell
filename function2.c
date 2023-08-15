#include "main.h"
/**
*pased_arguments - pasa argumento
*@line: char
*Return: argumento pasado
*/
char **pased_arguments(char *line)
{
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	char *token = strtok(line, " \t");
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
		arguments[arg_index] = token;
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

		token = strtok(NULL, " \t");
	}
	arguments[arg_index] = NULL;
	return (arguments);
}
/**
*recreated_getenv - recreated
*@name: char
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
