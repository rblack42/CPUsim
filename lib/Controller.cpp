#include "Controller.h"
#include "mnemonics.h"

// Constructor
Controller::Controller( void ) {
}
   
// accessors
int Controller::get_IR(void) {
    return IR;
}

int Controller::get_PC(void) {
    return PC;
}

// mutators

void Controller::reset(void) {
    PC = 0;
    IR = 0;
}

int Controller::fetch( Memory *mem ) {
    unsigned int ticks = 0;
    return ticks;;
}

int Controller::decode( Memory *iMem) {
    unsigned int ticks = 0;
    return ticks;
}

int Controller::execute( void ) {
    unsigned int ticks = 0;
    return ticks;
}

int Controller::retire( void ) {
    unsigned int ticks = 0;
    return ticks;
}

