/*
Illustration of how to perform tests using catch2.
*/

#include "catch.hpp"

TEST_CASE("hello world int") {
    REQUIRE( 1 == 1 );
}

TEST_CASE("hello world float"){
    REQUIRE( 1.0000000000001 == Approx(1.0000000000002));
}
