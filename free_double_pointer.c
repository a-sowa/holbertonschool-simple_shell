#include "main.h"

/**
 * free_double_pointer - Frees memory allocated for a double pointer.
 * @double_pointer: The double pointer to free.
 */

void free_double_pointer(char **double_pointer)
{
	int index;

	if (double_pointer == NULL)
	{
		fprintf(stderr, "Error: Attempting to free a NULL double pointer\n");
		return;
	}

	for (index = 0; double_pointer[index] != NULL; index++)
	{
		/* Free each element of the double pointer */
		free(double_pointer[index]);
	}
	/* Free the double pointer itself */
	free(double_pointer);
}
