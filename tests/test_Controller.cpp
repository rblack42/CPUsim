#include "catch.hpp"
#include "Controller.h"
#include "Memory.h"
#include "mnemonics.h"

TEST_CASE( "test fetch", "controller" ){
    Controller ctl;
    REQUIRE(ctl.get_PC() == 0);
    Memory mem(5,0,0);
    REQUIRE(mem.ready());

    // test MOVRR
    ctl.reset();
    mem.write(0, 1, MOVRR);
    mem.read(0,1);
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == MOVRR);
    ctl.fetch(&mem);
    REQUIRE(ctl.get_PC() == 0);
    REQUIRE(ctl.get_IR() == MOVRR);
    ctl.decode(&mem);
    REQUIRE(ctl.get_PC() == 3);

    // test MOVRM
    ctl.reset();
    mem.write(0, 1, MOVRM);
    mem.read(0,1);
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == MOVRM);
    ctl.fetch(&mem);
    REQUIRE(ctl.get_PC() == 0);
    REQUIRE(ctl.get_IR() == MOVRM);
    ctl.decode(&mem);
    REQUIRE(ctl.get_PC() == 4);

    // test MOVMR
    ctl.reset();
    mem.write(0, 1, MOVMR);
    mem.read(0,1);
    REQUIRE(mem.ready());
    REQUIRE(mem.read_valid() == MOVMR);
    ctl.fetch(&mem);
    REQUIRE(ctl.get_PC() == 0);
    REQUIRE(ctl.get_IR() == MOVMR);
    ctl.decode(&mem);
    REQUIRE(ctl.get_PC() == 4);
}
