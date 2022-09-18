#include "include/job.h"
#include <windows.h>
#include <string.h>
#include <stdio.h>

void run_as_admin(char *command, char *app, prompt_t type, int def_dir) {
    // get current directory
    char directory[MAX_PATH] = {0};
    GetCurrentDirectory(MAX_PATH, directory);

    // edit buffer
    size_t length = strlen(command) + strlen(app) + MAX_PATH + 10;
    char *buffer = calloc(length, sizeof(char));

    buffer[0] = '/';
    buffer[1] = type == prompt_keep ? 'k' : 'c';
    buffer[2] = ' ';

    if (def_dir == 1) {
        strcat(buffer, "cd \"");
        strcat(buffer, directory);
        strcat(buffer, "\" && ");
    } else {
        directory[0] = '\0';
    }

    if (app[0] != '\0') {
        strcat(buffer, app);
        strcat(buffer, " ");
    }

    strcat(buffer, command);

    puts(buffer);

    // execute as admin
    ShellExecuteA(NULL, "runas", "cmd", buffer, directory, SW_SHOWNORMAL);

    free(buffer);
}
