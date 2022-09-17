#ifndef ISUDO_JOB_H
#define ISUDO_JOB_H

typedef enum {
    prompt_close,
    prompt_keep
} prompt_t;

void run_as_admin(const char *command, prompt_t type);

#endif
