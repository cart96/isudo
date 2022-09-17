#include "include/job.h"
#include <windows.h>
#include <string.h>
#include <stdio.h>

void run_as_admin(char *command, char *app, prompt_t type) {
    // get current directory
    char directory[MAX_PATH] = {0};
    GetCurrentDirectory(MAX_PATH, directory);

    // edit buffer
    size_t length = strlen(command) + 1;
    char *buffer = NULL;

    if (strcmp(app, "cmd") == 0) {
        length += MAX_PATH + 4;
        buffer = calloc(length, sizeof(char));

        buffer[0] = '/';
        buffer[1] = type == prompt_keep ? 'k' : 'c';
        buffer[2] = ' ';

        strcat(buffer, "cd \"");
        strcat(buffer, directory);
        strcat(buffer, "\" && ");
    } else {
        buffer = calloc(length, sizeof(char));
    }

    strcat(buffer, command);

    // execute as admin
    ShellExecuteA(NULL, "runas", app, buffer, directory, SW_SHOWNORMAL);
}
