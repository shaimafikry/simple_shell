#include "shell.h"
/**
 * _exec-execute the command
 * @command:the command that will be inputed
 * @filename: file name
*/
void _exec(const char *command, char *filename)
{
	char *command_path, *token, *args[1024];
	int argc = 0;

	command_path = malloc(1024);
	if (command_path == NULL)
	{
		write(1, "malloc failed", strlen("malloc failed"));
		exit(EXIT_FAILURE); }
	token = strtok((char *)command, " ");
	while (token != NULL && argc < 1023)
	{
		args[argc] = token;
		token = strtok(NULL, " ");
		argc++;
	}
	args[argc] = NULL;
	find_path(args[0], command_path);
	if (command_path[0] != '\0')
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror(filename);
			exit(EXIT_FAILURE); }
		else if (child_pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				perror(filename), exit(EXIT_FAILURE); }
		}
		else
			wait(NULL); }
		else
		{
			perror(filename), exit(EXIT_FAILURE); }
	free(command_path); }
