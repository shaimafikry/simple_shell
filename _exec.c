#include "shell.h"
/**
 * _exec-execute the command
 * @command:the command that will be inputed
 * @filename: file name
 * @args: tokenizaed input
*/
void _exec(char *command, char *filename, char *args[1024])
{
	char *command_path;
	int status;
	command_path = malloc(1024);
	if (command_path == NULL)
	{
		write(1, "malloc failed", strlen("malloc failed"));
		exit(2);
	}
	find_path(command, command_path);
	if (command_path[0] != '\0')
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
			free(command_path), perror(filename), exit(2);

		else if (child_pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
				free(command_path), perror(filename), exit(EXIT_FAILURE); }
		else
		{
			wait(&status);
			if (WIFEXITED(status) == 0)
				exit(WEXITSTATUS(status));
		}
	}
	else
		perror(filename);

	free(command_path);
}
