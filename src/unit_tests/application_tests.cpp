#include "catch.hpp"

#include <iostream>
#include "applications/percolation_stats.h"

using namespace applications;

TEST_CASE("percolation")
{
    SECTION("percolation stats - small")
    {
        percolation_stats percolation_stats(100, 100);

        REQUIRE((percolation_stats.mean() > 0) == true);
        REQUIRE((percolation_stats.mean() < 1) == true);
        REQUIRE((percolation_stats.confidence_hi() >= percolation_stats.mean()) == true);
        REQUIRE((percolation_stats.confidence_lo() <= percolation_stats.mean()) == true);
    }

    SECTION("percolation stats - medium")
    {
        percolation_stats percolation_stats(200, 200);

        REQUIRE((percolation_stats.mean() > 0) == true);
        REQUIRE((percolation_stats.mean() < 1) == true);
        REQUIRE((percolation_stats.confidence_hi() >= percolation_stats.mean()) == true);
        REQUIRE((percolation_stats.confidence_lo() <= percolation_stats.mean()) == true);
    }

    SECTION("percolation stats - large")
    {
        percolation_stats percolation_stats(400, 200);

        REQUIRE((percolation_stats.mean() > 0) == true);
        REQUIRE((percolation_stats.mean() < 1) == true);
        REQUIRE((percolation_stats.confidence_hi() >= percolation_stats.mean()) == true);
        REQUIRE((percolation_stats.confidence_lo() <= percolation_stats.mean()) == true);
    }
}