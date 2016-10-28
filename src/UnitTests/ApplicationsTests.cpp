#include "catch.hpp"

#include <iostream>
#include "Applications/PercolationStats.h"

using namespace applications;

TEST_CASE("Percolation")
{
    SECTION("Percolation Stats - Small")
    {
        PercolationStats percolationStats(100, 100);

        REQUIRE((percolationStats.mean() > 0) == true);
        REQUIRE((percolationStats.mean() < 1) == true);
        REQUIRE((percolationStats.confidenceHi() >= percolationStats.mean()) == true);
        REQUIRE((percolationStats.confidenceLo() <= percolationStats.mean()) == true);
    }

    SECTION("Percolation Stats - Medium")
    {
        PercolationStats percolationStats(200, 200);

        REQUIRE((percolationStats.mean() > 0) == true);
        REQUIRE((percolationStats.mean() < 1) == true);
        REQUIRE((percolationStats.confidenceHi() >= percolationStats.mean()) == true);
        REQUIRE((percolationStats.confidenceLo() <= percolationStats.mean()) == true);
    }

    SECTION("Percolation Stats - Large")
    {
        PercolationStats percolationStats(400, 200);

        REQUIRE((percolationStats.mean() > 0) == true);
        REQUIRE((percolationStats.mean() < 1) == true);
        REQUIRE((percolationStats.confidenceHi() >= percolationStats.mean()) == true);
        REQUIRE((percolationStats.confidenceLo() <= percolationStats.mean()) == true);
    }
}
