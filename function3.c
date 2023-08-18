#include "main.h"
/**
*find_executable_path - function that finds the path of an executable command
*@command: name of the command
*@path: a colon-separated list of paths to search from
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
 *execute_command - function that executes a command with arguments
 *@command: command to be executed
 *@arguments: array of arguments for the command
 *@line: pointer to the original line of command
 */
void execute_command(char *command, char **arguments, char **line)
{
	pid_t pid = fork();
	char **custom_environ = 0;

	line = line;

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
*print_environment - function that prints the environment
*/
void print_environment(void)
{
	char **env_ptr;

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		printf("%s\n", *env_ptr);
	}
}
