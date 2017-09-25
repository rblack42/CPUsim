#include <string>
#include "catch.hpp"
#include "argParse.h"
#include "Machine.h"

TEST_CASE( "arParse test", "check valid file name" ){
    Machine m;
    std::string cmd = "argParse";
    int argc = 1;
    char *argv[1];
    argv[0] = (char *)cmd.c_str();
    REQUIRE(argParse(&m, argc, argv) != OK);
    REQUIRE(!m.get_debug());
}

TEST_CASE("argParse check debug flags", "argParse") {
    Machine m;
    std::string cmd = "argParse";
    std::string fn = "argParse";
    std::string flag = "-d";
    int argc = 3;
    char *argv[3];
    argv[1] = (char *)fn.c_str();
    argv[2] = (char *)flag.c_str();
    REQUIRE(argParse(&m, argc, argv) == OK);
    REQUIRE(m.get_debug());
}

TEST_CASE("argParse check bad flag", "argParse") {
    Machine m;
    std::string cmd = "argParse";
    std::string fn = "argParse";
    std::string flag = "-x";
    int argc = 3;
    char *argv[3];
    argv[1] = (char *)fn.c_str();
    argv[2] = (char *)flag.c_str();
    REQUIRE(argParse(&m, argc, argv) == BAD_OPT);
    REQUIRE(!m.get_debug());
}

