#include "job.c"
#include <stdio.h>

int main(int argc, char **argv)
{
    int def_dir = 1;
    char app[MAX_PATH] = {0};
    char *command = "";
    prompt_t option = prompt_keep;

    if (argc < 2)
    {
        run_as_admin("echo Loaded!", app, option, def_dir);
        return 0;
    }

    for (size_t arg_index = 1; arg_index < argc; arg_index++)
    {
        char *current_arg = argv[arg_index];

        if (current_arg[0] == '-')
        {
            int mode_index = -1;

            for (size_t char_index = 1; current_arg[char_index] != '\0'; char_index++)
            {
                char current_char = current_arg[char_index];

                if (mode_index >= 0)
                {
                    app[mode_index] = current_char;
                    app[mode_index + 1] = '\0';
                    mode_index += 1;
                    continue;
                }

                switch (current_char)
                {
                case 'k':
                    option = prompt_keep;
                    break;
                case 'c':
                    option = prompt_close;
                    break;
                case 'd':
                    def_dir = 0;
                    break;
                case '-':
                    arg_index = argc;
                    current_arg[char_index + 1] = '\0';
                    break;
                case 'x':
                    mode_index = 0;
                    app[0] = '\0';
                    break;
                case 'h':
                    puts(
                        "Isudo 1.0.0\n\n"
                        "Code: https://github.com/cart96/isudo\n"
                        "Note: Isudo supports argument/option overriding.\n"
                        "Usage: isudo.exe [options|command]\n"
                        "\nOptions\n"
                        "   -x<command>    Execute a command as admin.\n"
                        "   -k             Keep CMD open after execution.\n"
                        "   -c             Close CMD after execution.\n"
                        "   -d             Prevent directory replacing.\n"
                        "   -h             You already ran that!\n"
                        "   --             Stop processing arguments.\n"
                        "\nExamples\n"
                        "   isudo.exe\n"
                        "   isudo.exe -h\n"
                        "   isudo.exe -k \"echo hello\"\n"
                        "   isudo.exe -xnotepad \"pass.txt\"\n"
                        "   isudo.exe \"echo ?\" -ck \"echo second\"\n"
                        "   isudo.exe -cx\"C:\\app.exe\" \"arg1 arg2\"\n");

                    return 0;
                default:
                    fprintf(stderr, "unknown option '%c'\n", current_char);
                    return 1;
                }
            }
        }
        else
        {
            command = current_arg;
        }
    }

    run_as_admin(command, app, option, def_dir);
    return 0;
}
