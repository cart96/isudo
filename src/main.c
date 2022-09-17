#include "job.c"
#include <stdio.h>

int main(int argc, char **argv) {
    // check argument count
    if (argc < 2) {
        run_as_admin("echo Loaded!", "cmd", prompt_keep);
        return 0;
    }

    char app[MAX_PATH] = {0};
    char *command = "";
    prompt_t option = prompt_close;

    // parse arguments
    for (size_t arg_index = 1; arg_index < argc; arg_index++) {
        char *current_arg = argv[arg_index];

        if (current_arg[0] == '-') {
            // get options
            int mode_index = -1;

            for (size_t char_index = 1; current_arg[char_index] != '\0'; char_index++) {
                char current_char = current_arg[char_index];

                if (mode_index >= 0) {
                    app[mode_index] = current_char;
                    app[mode_index++] = '\0';
                    continue;
                }

                if (current_char == 'k') {
                    option = prompt_keep;
                } else if (current_char == 'c') {
                    option = prompt_close;
                } else if (current_char == 'h') {
                    puts(
                        "Isudo 1.0.0\n\n"
                        "Note: Isudo supports argument/option overloading.\n"
                        "Usage: isudo.exe [options|command]\n"
                        "\nOptions\n"
                        "   -x<file>    Execute a program as admin.\n"
                        "   -k          Keep CMD open after execution.\n"
                        "   -c          Close CMD after execution.\n"
                        "\nExamples\n"
                        "   isudo.exe\n"
                        "   isudo.exe -h\n"
                        "   isudo.exe -k \"echo hello\"\n"
                        "   isudo.exe -xnotepad \"pass.txt\"\n"
                        "   isudo.exe \"echo ?\" -ck \"echo second\""
                        "\n");

                    return 0;
                } else if (current_char == 'x') {
                    mode_index = 0;
                    app[0] = '\0';
                } else {
                    fprintf(stderr, "unknown option '%c'\n", current_char);
                    return 1;
                }
            }
        } else {
            // change command to current argument
            command = current_arg;
        }
    }

    // check if app is not set
    if (app[0] == '\0') {
        app[0] = 'c';
        app[1] = 'm';
        app[2] = 'd';
        app[3] = '\0';
    }

    run_as_admin(command, app, option);
    return 0;
}
