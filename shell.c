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
char command[125];
while (1)
{
if (isatty(STDIN_FILENO))
	print_prompt();
user_input(command, sizeof(command));
_exec(command, filename);
}
return (0);
}
