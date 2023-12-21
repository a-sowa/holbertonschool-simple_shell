#include "main.h"

/**
 * line_interpreter - Interprets a line of text from standard input.
 * Return: The input line as a string.
 */

char *line_interpreter(void)
{
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t input_length;

	/* Read a line from standard input */
	input_length = getline(&input, &buffer_size, stdin);

	if (input_length == -1)
	{
		free(input);
		if (feof(stdin))
		{
			/* No more input, exit gracefully */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Handle getline failure */
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
	}

	return (input);
}
