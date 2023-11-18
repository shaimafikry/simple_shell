#include "shell.h"

/**
 *main - the shell loop main function
 *@command[]: the command that the user will input
 * Return: 0 on success, 1 on error, or error code
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
char *filename = argv[0];
char command[125];
while (1)
{
print_prompt();
user_input(command, sizeof(command));
_exec(command, filename);
}
return (0);
}
