#include "main.h"
/**
*print_environment - print environment
*/
void print_environment(void)
{
	char **env_ptr;

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		printf("%s\n", *env_ptr);
	}
}
