#include "catch.hpp"

#include "data_structures/union_find.h"

using namespace datastructures;

TEST_CASE("union find")
{
    SECTION("quick find")
    {
        quick_find_uf union_find(10);

        union_find.connect(0, 1);
        union_find.connect(7, 8);
        union_find.connect(5, 9);

        REQUIRE(true == union_find.connected(5, 9));
        REQUIRE(false == union_find.connected(5, 7));

        union_find.connect(2, 6);
        union_find.connect(3, 4);
        union_find.connect(4, 8);
        union_find.connect(8, 9);

        REQUIRE(true == union_find.connected(3, 9));
        REQUIRE(true == union_find.connected(3, 7));
        REQUIRE(false == union_find.connected(1, 7));
    }

    SECTION("quick union")
    {
        quick_union_uf union_find(10);

        union_find.connect(0, 1);
        union_find.connect(7, 8);
        union_find.connect(5, 9);

        REQUIRE(true == union_find.connected(5, 9));
        REQUIRE(false == union_find.connected(5, 7));

        union_find.connect(2, 6);
        union_find.connect(3, 4);
        union_find.connect(4, 8);
        union_find.connect(8, 9);

        REQUIRE(true == union_find.connected(3, 9));
        REQUIRE(true == union_find.connected(3, 7));
        REQUIRE(false == union_find.connected(1, 7));
    }

    SECTION("weighted union find")
    {
        weighted_uf union_find(10);

        union_find.connect(0, 1);
        union_find.connect(7, 8);
        union_find.connect(5, 9);

        REQUIRE(true == union_find.connected(5, 9));
        REQUIRE(false == union_find.connected(5, 7));

        union_find.connect(2, 6);
        union_find.connect(3, 4);
        union_find.connect(4, 8);
        union_find.connect(8, 9);

        REQUIRE(true == union_find.connected(3, 9));
        REQUIRE(true == union_find.connected(3, 7));
        REQUIRE(false == union_find.connected(1, 7));
    }
}
