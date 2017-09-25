#include <iostream>
#include <cstdlib>
using namespace std;

#include "argParse.h"
#include "Machine.h"

void usage(void) {
    cout << "cpusim usage:" << endl;
    cout << "   cpusim [-d] [-s num] codefile" << endl;
    cout << "   -d - enable debug messages" << endl;
    cout << "   -s num - run num steps" << endl;
}

int argParse(Machine *c, int argc, char *argv[]) {
    std::string fname = "";
    if( argc < 2) {
        return NO_FILE;
    }
    for(int i = 1; i < argc; i++) {
        if( argv[i][0] == '-' ) {
            switch ( argv[i][1] ) {
                case 'd':
                    c->set_debug();
                    break;
                case 's':
                    c->set_stopCycle( atoi( argv[i+1] ));
                    i++;
                    break;
                default:
                    return BAD_OPT;
            }
        } else {
            fname = argv[i];
        }
    }          
    if( fname.length() == 0) {
        return NO_FILE;
    } else
        c->set_codeFile(fname);
    return OK;
}

void argError(int code) {
    switch (code) {
        case NO_FILE:
            std::cout << "code file cannot be opened" << std::endl;
            break;
        case BAD_OPT:
            std::cout << "bad command line option" << std::endl;
            break;
    }
}

