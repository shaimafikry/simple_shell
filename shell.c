#include "shell.h"

/**
 *main - the shell loop main function
 *@command[]: the command that the user will input
 * Return: 0 on success, 1 on error, or error code
 */
int main(void)
{
char command[125];
while (1)
{
print_prompt();
user_input(command, sizeof(command));
_exec(command);
}
return (0);
}
