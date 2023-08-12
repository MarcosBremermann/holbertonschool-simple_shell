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
*Return: command_path or null
*/
char *find_executable_path(const char *command, const char *path)
{
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char command_path[1024];

	while (token != NULL)
	{
		sprintf(command_path, "%s/%s", token, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(command_path));
		}

		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 *execute_command - execute command write for the user
 *@command: char
 *@arguments: char
 */
void execute_command(char *command, char **arguments)
{
	pid_t pid = fork();
	char **custom_environ = NULL;

	if (pid == 0)
	{
		if (strchr(command, '/') != NULL)
		{
			if (execve(command, arguments, custom_environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = recreated_getenv("PATH");
			char *command_path = find_executable_path(command, path);

			if (command_path != NULL)
			{
				execve(command_path, arguments, custom_environ);
				free(command_path);
			}
			else
			{
				perror("Command not found");
				exit(EXIT_FAILURE);
			}
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
/**
*print_environment - print environment
*/
void print_environment(void)
{
	extern char **environ;
	char **env_ptr;

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		printf("%s\n", *env_ptr);
	}
}
