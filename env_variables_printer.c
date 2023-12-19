#include "main.h"

/**
 * env_variables_printer - Prints the environment variables.
 */
void env_variables_printer(void)
{
	char **current = environ;

	while (*current != NULL)
	{
		printf("%s\n", *current++);
	}
}
