#include "shell.h"
/**
 * _exec-execute the command
 * @command:the command that will be inputed
 * @comm_path[]:the string that will save the full path of the command
 * @args[]:the secound argument of exeve function
*/
void _exec(const char *command)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
/*Tokenize the user input into command and arguments*/
char *token;
char *args[1024];
int argc = 0;

token = strtok((char *)command, " ");
while (token != NULL)
{
args[argc] = token;
token = strtok(NULL, " ");
argc++;
}
args[argc] = NULL;

/*Construct the full path to the command*/
char command_path[256];
snprintf(command_path, sizeof(command_path), "/bin/%s", args[0]);


if (execve(command_path, args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/*Parent process*/
wait(NULL);
}
}
