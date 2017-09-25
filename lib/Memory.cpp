#include "Memory.h"
#include <cstddef>

// constructor
Memory::Memory(void) {
}

Memory::Memory(int size, int read_time, int write_time) {
}

Memory::~Memory() {
}

// accessors
void Memory::read(uint16_t address, int size) {
}

uint16_t Memory::read_valid(void) {
    return rdata;
}

bool Memory::ready(void) {
    return false;
}

int Memory::get_size(void) {
    return mSize;
}

// mutators
void Memory::write(uint16_t address, int size, uint16_t data) {
}


