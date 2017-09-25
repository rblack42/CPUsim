#include <iostream>
#include <fstream>

#include "Machine.h"
#include "mnemonics.h"
#include "mCodes.h"

// constructor
Machine::Machine(void) {
}

// destructor
Machine::~Machine(void) {
}

// accessors
std::string Machine::get_codeFile(void) {
    return codeFile;
}

int Machine::get_stopCycle(void) {
    return stopCycle;
}

bool Machine::get_debug(void) {
    return debug;
}

// mutators
void Machine::boot(void) {
}

void Machine::set_stopCycle(int val) {
}

void Machine::set_debug(void) {
    debug = true;
}

void Machine::set_codeFile(std::string fname) {
    codeFile = fname;
}

int Machine::run(void) {
    int code = 0;
    return code;
}

void Machine::dump_imem(void) {
}

