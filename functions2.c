#include "main.h"
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
			{
				return (environ[i] + strlen(name) + 1);
			}
		}
	}
	return (NULL);
}
/**
*find_executable_path - path
*@command: char
*@path: char
*Return: command_path or result
*/
char *find_executable_path(const char *command, const char *path)
{
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char command_path[1024];
	char *result = NULL;

	while (token != NULL)
	{
		sprintf(command_path, "%s/%s", token, command);

		if (access(command_path, X_OK) == 0)
		{
			result = strdup(command_path);
			break;
		}

		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (result);
}
