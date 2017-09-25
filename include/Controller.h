#pragma once

#include "Memory.h"

class Controller {
    public:
        // Constructor
        Controller( void );
   
        // accessors
        int get_IR(void);
        int get_PC(void);

        // mutators
        void reset(void);
        int fetch( Memory * mem );
        int decode( Memory * mem );
        int execute( void );
        int retire( void );

    private:
        unsigned int PC;    // program counter
        unsigned int IR;    // instruction register
};

