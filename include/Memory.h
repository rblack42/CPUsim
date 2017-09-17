#pragma once
#include <cstdint>

class Memory {
    public:
        // constructor
        Memory(int size, int read_time, int write_time);
        ~Memory();

        // accessors
        void read(uint16_t address, int size);
        uint16_t read_valid(void);
        bool ready(void);

        // mutators
        void write(uint16_t address, int size, uint16_t data);

    private:
        int delay;
        uint8_t *mem;
        uint16_t rdata;
        int read_access_time;
        int write_access_time;
};

