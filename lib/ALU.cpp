#include "ALU.h"
#include <iostream>

ALU::ALU(void) {
}

bool ALU::get_carry( void ) {
    return carry;
}

bool ALU::get_overflow( void ) {
    return overflow;
}

int16_t ALU::get_result( void ) {
    return result;
}

void ALU::add(uint16_t op1, uint16_t op2, int size) {
}

void ALU::sub(uint16_t op1, uint16_t op2, int size) {
}

