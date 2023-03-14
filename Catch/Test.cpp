//
// Created by Chris Robinson on 3/2/23.
//
#include "catch.hpp"
#include "../tsp.h"
#include <string>

TEST_CASE("a is equal to 1")
{
    tsp tsp;
    int b = 1;
    tsp.setA(b);
    REQUIRE( tsp.getA() == 1);
}

TEST_CASE("Create adjacency matrix") {
    tsp tsp;
    REQUIRE(tsp.createAdjacencyMatrix());
}
TEST_CASE("Read distances.txt") {
    tsp tsp;
    REQUIRE(tsp.readDistances() == true);
}

TEST_CASE("Accept user input - getInput()") {
    tsp tsp;
    REQUIRE(tsp.acceptInput() == true);
    REQUIRE(tsp.cities == 5);
    REQUIRE(tsp.tours == 5);
    REQUIRE(tsp.generations == 5);
    REQUIRE(tsp.percentMutated == 5);
}

TEST_CASE("Print s array - printS()") {

}

