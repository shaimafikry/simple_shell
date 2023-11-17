#include "shell.h"
/**
 * find_path - check and find complete path
 * @command: order name
 * 
*/
void find_path (char *name, char *command_path)
{
	char *full_path,  *copied_full_path;
	char *path_arry[1024], *token;
	int i ;
	struct stat st;

	copied_full_path = malloc(1024);
	if (copied_full_path == NULL)
	{
		write(1,"malloc failed", sizeof("malloc failed"));
	}
	
	/*gits path into array*/
	for ( i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			{
				full_path = *environ + 5;
				break;
			}

	}
	printf ("full path : %s", full_path);
	strcpy(copied_full_path, full_path);
	printf (" copied full path : %s", copied_full_path);
	token = strtok(copied_full_path, ":");
	i = 0;
	while(token != NULL)
	{
		path_arry[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	path_arry[i] = NULL;
	
	i = 0;
	while (path_arry[i])
	{
		if (chdir(path_arry[i]) == 0)
		{
			if (stat(name,&st) == 0)
			{
				printf("check stat\n");
				strcpy(command_path, path_arry[i]);
				strcat(command_path, "/");
				strcat(command_path, name);
				printf("check command %s\n", command_path);
				return;

			}

		}
	}
	command_path = NULL;
	free(copied_full_path);
}
