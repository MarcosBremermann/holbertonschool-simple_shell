#include "main.h"
#include <string.h>
int
main(void)
{
	char *line = NULL;
	char *command = NULL;
	char **arguments = NULL;

	while (1)
	{
		char *line_copy = NULL;

		display_prompt();
		line = read_command();

		if (line == NULL)
		{
			break;
		}
		line_copy = strdup(line);
		command = strtok(line_copy, " ");

		if (command != NULL)
		{
			arguments = pased_arguments(line);

			if (strcmp(command, "exit") == 0)
			{
				free(line);
				free(arguments);
				free(line_copy);
				break;
			}
			else if (strcmp(command, "ls") == 0)
			{
				char command_path[] = "/bin/ls";

				execute_command(command_path, arguments);
			}
			else
			{
				execute_command(command, arguments);
			}
			free(arguments);
		}
		free(line_copy);
		free(line);
	}
	return (0);
}
