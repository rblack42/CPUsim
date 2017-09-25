#include <iostream>
#include <string>

#include "Machine.h"
#include "argParse.h"

std::string version = "0.2";
std::string fname;

int main(int argc, char *argv[]) {
    int exit_code;
    std::cout << "CPUsim (v" << version << ")" << std::endl;

    // create simulator
    Machine cpusim;
    
    // parse command line
    int argcode = argParse(&cpusim, argc, argv);

    // run the simulation
    if(argcode != OK) {
        argError(argcode);
    } else {
        std::cout << "\trunning..." << std::endl;
        cpusim.boot();
        exit_code = cpusim.run();
        if(exit_code == 0) {
            std::cout << "\tundefined instruction" << std::endl;
        }
        if(exit_code <0) {
            std::cout << "\t processor fault - illegal instruction" 
                << std::endl;
        }
    }
    std::cout << "\tprocessing finished..." << std::endl;
    return 0;
}
