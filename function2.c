#include "main.h"
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
*recreated_getenv - recreated
*@name: char
*Return: NULL or environ
*/
char *recreated_getenv(const char *name)
{
	extern char **environ;
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
