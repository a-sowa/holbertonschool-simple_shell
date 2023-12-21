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
	{ /* Print shell prompt if the standard input is a terminal */
		if (isatty(STDIN_FILENO))
			printf("$ ");
		input = line_interpreter(); /* Read a line of input */
		if (strcmp("env\n", input) == 0) /* Check if the command is 'env' */
		{
			free(input);
			env_variables_printer();
			continue; }
		if (strcmp(input, "exit\n") == 0) /* Check if the command is 'exit' */
		{
			free(input);
			break; }
		/* Parse the input line into tokens */
		tokens = line_parser(input, TOKEN_DELIMITER);
		if (*tokens == NULL) /* Check if the first token is NULL */
		{
			free_double_pointer(tokens);
			continue; }
		/* Check if the command exists in the system's PATH */
		path = path_checker(*tokens);
		if (path == NULL)
		{ /* If the command is not found, print an error and return with status 3 */
			perror("Command not found");
			free(path);
			free_double_pointer(tokens);
			return (3);
		}
		if (path != NULL)
		{ /* If the command is found, execute it and update the status */
			status = command_executor(tokens, path);
			free(path);
		}
		free_double_pointer(tokens); /* Free memory allocated for tokens */
	}
	return (status);
}
