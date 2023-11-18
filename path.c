#include "shell.h"
/**
 * find_path - check and find complete path
 * @name: the command
 * @command_path: the full path of the command
 * @path_arry[]: the array of the tokanizathion string of the path
*/
void find_path(char *name, char *command_path)
{
int i;
struct stat st;
char *full_path, *copied_full_path, *path_arry[1024], *token;

copied_full_path = malloc(1024);
if (copied_full_path == NULL)
{
	perror("malloc failed"), exit(2); }
for (i = 0; environ[i]; i++)
{
	if (strncmp(environ[i], "PATH=", 5) == 0)
	{
		full_path = environ[i] + 5;
		break; }}
if (full_path[0] == '=')
	strcpy(copied_full_path, full_path + 1);
else
	strcpy(copied_full_path, full_path);
token = strtok(copied_full_path, ":");
i = 0;
while (token != NULL)
{
	path_arry[i] = token, token = strtok(NULL, ":");
	i++; }
path_arry[i] = NULL;
if (strchr(name, '/') != NULL)
{
	strcpy(command_path, name);
	goto start; }
for (i = 0; path_arry[i]; i++)
{
	strcpy(command_path, path_arry[i]);
	strcat(command_path, "/"), strcat(command_path, name);
start:
	if (stat(command_path, &st) == 0)
	{
		free(copied_full_path);
		return; }}
command_path[0] = '\0', free(copied_full_path);
exit(2); }
