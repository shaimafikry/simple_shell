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
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("fgets");
		exit(EXIT_FAILURE);
	}
}
command[strcspn(command, "\n")] = '\0';
}
