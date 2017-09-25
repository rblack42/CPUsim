#pragma once
#include <cstdint>

class ALU {
    public:
        // constructor
        ALU( void );

        int16_t get_result( void );
        bool get_carry( void );
        bool get_overflow( void );

        void add(uint16_t op1, uint16_t op2, int size);
        void sub(uint16_t op1, uint16_t op2, int size);

    private:
        uint16_t result;
        bool carry;
        bool overflow;
};

