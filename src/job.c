#include "include/job.h"
#include <windows.h>
#include <string.h>

void run_as_admin(const char *command, prompt_t type) {
    char directory[MAX_PATH] = {0};
    GetCurrentDirectory(MAX_PATH, directory);

    size_t length = strlen(command) + MAX_PATH + 4;
    char *buffer = calloc(length, sizeof(char));
    buffer[0] = '/';
    buffer[1] = type == prompt_keep ? 'k' : 'c';
    buffer[2] = ' ';

    strcat(buffer, "cd \"");
    strcat(buffer, directory);
    strcat(buffer, "\" && ");
    strcat(buffer, command);

    ShellExecuteA(NULL, "runas", "cmd", buffer, directory, SW_SHOWNORMAL);
}
