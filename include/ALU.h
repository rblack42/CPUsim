#pragma once
#include <cstdint>

class ALU {
    public:
        // constructor
        ALU( void );

        int16_t get_result( void );
        bool get_carry( void );
        bool get_overflow( void );

        void add(int16_t op1, int16_t op2, int size);
        void sub(int16_t op1, int16_t op2, int size);

    private:
        int16_t result;
        bool carry;
        bool overflow;
};

