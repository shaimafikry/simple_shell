#include "shell.h"
/**
 * _exec-execute the command
 * @command:the command that will be inputed
 * @comm_path[]:the string that will save the full path of the command
 * @args[]:the secound argument of exeve function
*/
void _exec(const char *command) {
    char *command_path;
    char *token, *args[1024];
    int argc = 0;
    command_path = malloc(1024);
    if (command_path == NULL) {
        write(1, "malloc failed", strlen("malloc failed"));
        exit(EXIT_FAILURE);
    }

    // Tokenize the user input into command and arguments
token = strtok((char *)command, " ");
while (token != NULL && argc < 1023) {
    args[argc] = token;
    token = strtok(NULL, " ");
    argc++;
}
    args[argc] = NULL;
    printf("%s\n", args[0]);
    find_path(args[0], command_path);
    if (command_path[0] != '\0') {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            args[0]=command_path;
            if (execve(command_path, args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    } else {
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    free(command_path);
}
