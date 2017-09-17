#include "catch.hpp"
#include <cstdlib>

#include "ALU.h"

TEST_CASE( "test basic 8-bit add", "alu" ){
    ALU alu;
    alu.add(250, 1, 1);
    REQUIRE(alu.get_result() == 251);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 16-bit add", "alu" ){
    ALU alu;
    alu.add(510, 1, 2);
    REQUIRE(alu.get_result() == 511);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 8-bit sub", "alu" ){
    ALU alu;
    alu.sub(255, 1, 1);
    REQUIRE(alu.get_result() == 254);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 16-bit sub", "alu" ){
    ALU alu;
    alu.sub(5530, 1, 1);
    REQUIRE(alu.get_result() == 5529);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 8-bit carry", "alu" ){
    ALU alu;
    alu.add(255, 1, 1);
    REQUIRE(alu.get_result() == 0);
    REQUIRE(alu.get_carry());
}

TEST_CASE( "test basic 16-bit carry", "alu" ){
    ALU alu;
    alu.add(65535, 1, 2);
    REQUIRE(alu.get_result() == 0);
    REQUIRE(alu.get_carry());
}
