#include "shell.h"

/**
 *main - the shell loop main function
 * @argc: num
 * @argv: input includeng file name
 * Return: 0 on success, 1 on error, or error code
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
char *filename = argv[0];
char command[1024];
char *args[1024];
int i = 0;

while (1)
{
	if (isatty(STDIN_FILENO))
		print_prompt();

	user_input(command, sizeof(command));
	while (command[i] != '\0')
	{
		if ((command[i] == ' ' || (command[i] == '\t' || command[i] == '\n')))
			i++;
		else
		{
			input_token(command, args);
			_exec(args[0], filename, args);
			break;
		}
	}
}
	return (0);
}
