#include "job.c"
#include <stdio.h>

int main(int argc, char **argv) {
    // check argument count
    if (argc < 2) {
        fprintf(stderr, "no input found\n");
        return 1;
    }

    char *command = "cmd";
    prompt_t option = prompt_close;

    // parse arguments
    for (size_t arg_index = 1; arg_index < argc; arg_index++) {
        char *current_arg = argv[arg_index];

        if (current_arg[0] == '-') {
            // get options
            for (size_t char_index = 1; current_arg[char_index] != '\0'; char_index++) {
                char current_char = current_arg[char_index];

                if (current_char == 'k') {
                    option = prompt_keep;
                } else if (current_char == 'c') {
                    option = prompt_close;
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

    run_as_admin(command, option);
    return 0;
}
