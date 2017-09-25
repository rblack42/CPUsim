#pragma once

enum mnemonics {
    UNDEF,

    // data movement
    MOVRR,      // mov from register to register
    MOVRM,      // move from memory to register
    MOVMR,      // move from register to memoru

    // arithmetic
    ADD,        // add unsigned
    SUB,        // sub unsigned
    IADD,       // signed add
    ISUB,       // signed subtract

    // system control
    HLT
};
