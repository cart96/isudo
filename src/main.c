#include "job.c"

int main(int argc, char **argv) {
    run_as_admin("dir", prompt_keep);
    return 0;
}
