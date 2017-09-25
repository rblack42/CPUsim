#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include "ALU.h"

TEST_CASE( "test basic 8-bit add", "alu" ){
    ALU alu;
    alu.add((uint16_t)250, (uint16_t)1, 1);
    REQUIRE(alu.get_result() == 251);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 16-bit add", "alu" ){
    ALU alu;
    alu.add((uint16_t)510, (uint16_t)1, 2);
    REQUIRE(alu.get_result() == 511);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 8-bit sub", "alu" ){
    ALU alu;
    alu.sub((uint16_t)255, (uint16_t)1, 1);
    REQUIRE(alu.get_result() == 254);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 16-bit sub", "alu" ){
    ALU alu;
    alu.sub((uint16_t)5530, (uint16_t)1, 1);
    REQUIRE(alu.get_result() == 5529);
    REQUIRE(!alu.get_carry());
}

TEST_CASE( "test basic 8-bit carry", "alu" ){
    ALU alu;
    alu.add((uint16_t)255, (uint16_t)1, 1);
    REQUIRE(alu.get_result() == 0);
    REQUIRE(alu.get_carry());
}

TEST_CASE( "test basic 16-bit carry", "alu" ){
    ALU alu;
    alu.add((uint16_t)65535, (uint16_t)1, 2);
    REQUIRE(alu.get_result() == 0);
    REQUIRE(alu.get_carry());
}
