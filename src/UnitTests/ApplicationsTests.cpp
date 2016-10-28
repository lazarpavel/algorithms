#include "catch.hpp"

#include <iostream>
#include "Applications/PercolationStats.h"

using namespace applications;

TEST_CASE("Percolation")
{
    SECTION("Percolation Stats")
    {
        PercolationStats percolationStats(100, 10);

        REQUIRE((percolationStats.mean() > 0) == true);
        REQUIRE((percolationStats.mean() < 1) == true);
        REQUIRE((percolationStats.confidenceHi() >= percolationStats.mean()) == true);
        REQUIRE((percolationStats.confidenceLo() <= percolationStats.mean()) == true);
    }

    SECTION("Percolation Stats")
    {
        PercolationStats percolationStats(200, 200);

        REQUIRE((percolationStats.mean() > 0) == true);
        REQUIRE((percolationStats.mean() < 1) == true);
        REQUIRE((percolationStats.confidenceHi() >= percolationStats.mean()) == true);
        REQUIRE((percolationStats.confidenceLo() <= percolationStats.mean()) == true);
    }
}
