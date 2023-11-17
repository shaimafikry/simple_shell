#include "shell.h"
/**
 * find_path - check and find complete path
 * @command: order name
 * 
*/
void find_path(char *name, char *command_path) {
 char *full_path, *copied_full_path;
    char *path_arry[1024], *token;
    int i;
    struct stat st;

    copied_full_path = malloc(1024);  // Adjust the size based on your needs
    if (copied_full_path == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Gets path into array
    for (i = 0; environ[i]; i++) {
        if (strncmp(environ[i], "PATH=", 5) == 0) {
            full_path = environ[i] + 5;  // Skip the "PATH=" prefix
            break;
        }
    }

   if (full_path[0] == '=') {
        strcpy(copied_full_path, full_path + 1);  // Copy everything after '='
    } else {
        strcpy(copied_full_path, full_path);  // Copy the original string if '=' is not present
    }

    //printf("full path : %s\n", full_path);
    //printf("copied full path : %s\n", copied_full_path);

    token = strtok(copied_full_path, ":");
    i = 0;
    while (token != NULL) {
        path_arry[i] = token;
        token = strtok(NULL, ":");
        i++;
    }
    path_arry[i] = NULL;

    for (i = 0; path_arry[i]; i++) {
        strcpy(command_path, path_arry[i]);
        strcat(command_path, "/");
        strcat(command_path, name);

        if (stat(command_path, &st) == 0) {
           // printf("check stat\n");
           // printf("check command %s\n", command_path);
            free(copied_full_path);
            return;
        }
    }

    command_path[0] = '\0'; // Set an empty string if the command is not found
    free(copied_full_path);
}
