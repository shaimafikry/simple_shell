#include "shell.h"
/**
 * user_input - function that get the input from the user
 * @command:the command that the user will input
 * @size:the size of the input
*/
void user_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(command);
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(command, "\n") != 0)
		command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
