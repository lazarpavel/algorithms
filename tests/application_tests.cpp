#include <catch2/catch.hpp>

#include <iostream>
#include "applications/percolation_stats.h"

TEST_CASE("percolation")
{
    SECTION("percolation stats - small")
    {
        applications::percolation_stats percolation_stats(100, 100);

        REQUIRE((percolation_stats.mean() > 0) == true);
        REQUIRE((percolation_stats.mean() < 1) == true);
        REQUIRE((percolation_stats.confidence_hi() >= percolation_stats.mean()) == true);
        REQUIRE((percolation_stats.confidence_lo() <= percolation_stats.mean()) == true);
    }
}
