#include "main.h"
#include <stdlib.h>

/**
 * line_parser - Parses the input line into an array of words.
 * @string_to_parse: The input string to be parsed.
 * @separator: The separator used to split the input into words.
 * Return: An array of words (tokens) obtained by splitting the input.
 */

char **line_parser(char *string_to_parse, const char *separator)
{
	int index = 0, size = SIZE;
	char **tokens = (char **)malloc(size * sizeof(char *)), *token = NULL;

	if (!tokens)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(string_to_parse, separator);

	while (token != NULL)
	{
		if (index >= size - 1)
		{
			size *= 2;
			tokens = realloc(tokens, size * sizeof(char *));
			if (!tokens)
			{
				perror("Memory reallocation error");
				exit(EXIT_FAILURE);
			}
		}

		tokens[index] = strdup(token);
		if (!tokens[index])
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		index++;
		token = strtok(NULL, separator);
	}

	tokens[index] = NULL;
	free(string_to_parse);

	return (tokens);
}
