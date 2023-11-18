#include "shell.h"
/**
 * input_token -execute the command
 * @command:the command that will be inputed
 * @args: command tokenization
*/
void input_token(const char *command, char *args[1024])
{
	int argc = 0;
	char *token;

	token = strtok((char *)command, " ");
	while (token != NULL && argc < 1024)
	{
		args[argc] = token;
		token = strtok(NULL, " ");
		argc++;
	}
	args[argc] = NULL;
}
