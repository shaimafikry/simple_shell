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
/*Child process*/
char comm_path[256];
snprintf(comm_path, sizeof(comm_path), "/bin/%s", command);

char *args[] = {comm_path, NULL};
execve(comm_path, args, NULL);

perror("execve");
exit(EXIT_FAILURE);
}
else
{
/*Parent process*/
wait(NULL);
}
}
