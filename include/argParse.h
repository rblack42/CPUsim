#pragma once
#include "Machine.h"

enum argErrors {
    OK,
    NO_FILE,
    BAD_OPT,
};

int argParse( Machine *c, int argc, char *argv[]);
void argError(int code);
void usage(void);
