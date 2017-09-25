#pragma once
#include <string>

#include "Memory.h"
#include "Controller.h"

class Machine {
    public:
        // constructors
        Machine(void);

        // destructors
        ~Machine(void);

        // accessors
        std::string get_codeFile(void);
        int get_stopCycle(void);
        bool get_debug(void);

        // mutators
        void boot();
        int run(void);
        void set_stopCycle(int val);
        void set_debug(void);
        void set_codeFile(std::string fname);
        void dump_imem(void);

    private:
        // memory components
        Memory *iMem;   // dynamically allocated instruction memory
        Memory *dMem;   // data memory
        Memory *rMem;   // internal register set

        // von Neumann components
        Controller ctrl;

        // simulator control variables
        int ticks;
        std::string codeFile;
        int stopCycle;
        int cycles;
        bool debug = false;
};

