#include "main.h"
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
