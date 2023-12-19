#include "main.h"

/**
 * path_checker - Checks if a command exists in the system's PATH.
 * @command: The name of the command to search for
 * Return: If the command is found the full path of the command otherwise NULL
 */

char *path_checker(char *command)
{
	char *array[1000], *path = strdup(getenv("PATH"));
	char *path_token = strtok(path, ":");
	int index = 0;
	char *final_path;
	struct stat info;

	if (stat(command, &info) == 0)
	{
		strcpy(path, command);
		return (path);
	}

	final_path = (char *) malloc(1024 * sizeof(char));

	while (path_token != NULL)
	{
		array[index] = path_token;
		index++;
		path_token = strtok(NULL, ":");
	}
	index = 0;
	while (array[index] != NULL)
	{
		strcpy(final_path, array[index]);
		strcat(final_path, "/");
		strcat(final_path, command);
		strcat(final_path, "\0");
		if (stat(final_path, &info) == 0)
		{
			free(path);
			return (final_path);
		}
		index++;
	}
	free(final_path);
	free(path);
	return (NULL);
}
