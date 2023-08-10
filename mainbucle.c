#include "main.h"
int
main(void)
{
	char *line;
	char *command;

	while (1)
	{
		display_prompt();
		line = read_command();

		if (line == NULL)
		{
			break;
		}
		command = strtok(line, " ");

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				free(line);
				break;
			}
			else if (strcmp(command, "env") == 0)
			{
			extern char **environ;
			char **env_var = environ;

			while (*env_var != NULL)
			{
				printf("%s\n", *env_var);
				env_var++;
			}
			}
			else if (strcmp(command, "ls") == 0)
			{
			char command_path[] = "/bin/ls";

			execute_command(command_path);
			}
			else
			{
			execute_command(command);
			}
		}
		free(line);
	}
	return (0);
}
