#include "main.h"
int
main(void)
{
	int i = 0;
	char *line = NULL;
	char *command = NULL;
	char **arguments = NULL;
	char *line_copy = NULL;

	while (1)
	{
		display_prompt();
		line = read_command();

		if (line == NULL)
		{
			break;
		}
		line_copy = strdup(line);
		command = strtok(line_copy, " \t");

		if (command != NULL)
		{
			arguments = pased_arguments(line);

			if (strcmp(command, "exit") == 0)
			{
				while (arguments[i])
				{
					free(arguments[i]);
					i++;
				}
				free(arguments);
				free(line);
				free(line_copy);
				break;
			}
			else if (strcmp(command, "ls") == 0)
			{
				char command_path[] = "/bin/ls";

				execute_command(command_path, arguments, &line);
			}
			else if (strcmp(command, "env") == 0)
			{
				print_environment();
			}
			else
			{
			execute_command(command, arguments, &line);
			}
			while (arguments[i])
			{
				free(arguments[i]);
					i++;
			}
			free(arguments);
		}
		free(line);
		free(line_copy);
	}
	return (0);
}
