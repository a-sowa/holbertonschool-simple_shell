#include "main.h"

/**
 * command_executor - Executes a command by forking a new process using execve.
 * @tokens: Command and its arguments to execute.
 * @path: The full path to the command executable.
 * Return: The exit status of the executed command.
 */

int command_executor(char **tokens, char *path)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(path, tokens, environ);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int wait_status;

		if (waitpid(pid, &wait_status, 0) == -1)
		{
			perror("Waitpid failed");
			exit(EXIT_FAILURE);
		}

		if (WIFEXITED(wait_status))
			status = WEXITSTATUS(wait_status);
		else
		{
			fprintf(stderr, "Child process did not terminate normally\n");
			status = EXIT_FAILURE;
		}
	}

	return (status);
}
