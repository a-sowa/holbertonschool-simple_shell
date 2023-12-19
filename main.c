#include "main.h"

/**
 * main - The main function running the simple shell.
 * Return: 0 for success.
 */

int main(void)
{
	char *input, **tokens, *path = NULL;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = line_interpreter();
		if (strcmp("env\n", input) == 0)
		{
			free(input);
			env_variables_printer();
			continue; }
		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			break;
		}
		tokens = line_parser(input, TOKEN_DELIMITER);
		if (*tokens == NULL)
		{
			free_double_pointer(tokens);
			continue;
		}
		path = path_checker(*tokens);
		if (path == NULL)
		{
			perror("Command not found");
			free(path);
			free_double_pointer(tokens);
			return (3);
		}
		if (path != NULL)
		{
			status = command_executor(tokens, path);
			free(path);
		}
		free_double_pointer(tokens);
	}
	return (status);
}
