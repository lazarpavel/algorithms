#include <catch2/catch_all.hpp>

#include "data_structures/quick_find_uf.h"
#include "data_structures/quick_union_uf.h"
#include "data_structures/weighted_quick_union_uf.h"

TEST_CASE("union find")
{
    SECTION("quick find")
    {
        data_structures::quick_find_uf union_find(10);

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
        data_structures::quick_union_uf union_find(10);

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
        data_structures::weighted_quick_union_uf union_find(10);

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
