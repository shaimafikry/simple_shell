#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
extern char **environ;
void user_input(char *command, size_t size);
void print_prompt(void);
void _exec(const char *command, char *filename);
void find_path(char *name, char *command_path);
#endif
