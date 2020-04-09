#include <catch2/catch.hpp>

#include "euler/euler.h"
#include <memory>

TEST_CASE("euler problems") {
    SECTION("power digit sum") {
        std::shared_ptr<interview::euler> euler = std::make_shared<interview::euler>();
        REQUIRE(1366 == euler->power_digit_sum(1000));
    }

    SECTION("power digit sum") {
        std::shared_ptr<interview::euler> euler = std::make_shared<interview::euler>();
        REQUIRE(21124 == euler->number_letter_counts(1000));
    }
}