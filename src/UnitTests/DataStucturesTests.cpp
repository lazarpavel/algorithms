#include "catch.hpp"

#include "./DataStructures/UnionFind.h"

using namespace datastructures;

TEST_CASE("Union Find")
{
    SECTION("Quick Find")
    {
        QuickFindUF unionFind(10);

        unionFind.connect(0, 1);
        unionFind.connect(7, 8);
        unionFind.connect(5, 9);

        REQUIRE(true == unionFind.connected(5, 9));
        REQUIRE(false == unionFind.connected(5, 7));

        unionFind.connect(2, 6);
        unionFind.connect(3, 4);
        unionFind.connect(4, 8);
        unionFind.connect(8, 9);

        REQUIRE(true == unionFind.connected(3, 9));
        REQUIRE(true == unionFind.connected(3, 7));
        REQUIRE(false == unionFind.connected(1, 7));
    }

    SECTION("Quick Union")
    {
        QuickUnionUF unionFind(10);

        unionFind.connect(0, 1);
        unionFind.connect(7, 8);
        unionFind.connect(5, 9);

        REQUIRE(true == unionFind.connected(5, 9));
        REQUIRE(false == unionFind.connected(5, 7));

        unionFind.connect(2, 6);
        unionFind.connect(3, 4);
        unionFind.connect(4, 8);
        unionFind.connect(8, 9);

        REQUIRE(true == unionFind.connected(3, 9));
        REQUIRE(true == unionFind.connected(3, 7));
        REQUIRE(false == unionFind.connected(1, 7));
    }

    SECTION("WeightedUF")
    {
        WeightedUF unionFind(10);

        unionFind.connect(0, 1);
        unionFind.connect(7, 8);
        unionFind.connect(5, 9);

        REQUIRE(true == unionFind.connected(5, 9));
        REQUIRE(false == unionFind.connected(5, 7));

        unionFind.connect(2, 6);
        unionFind.connect(3, 4);
        unionFind.connect(4, 8);
        unionFind.connect(8, 9);

        REQUIRE(true == unionFind.connected(3, 9));
        REQUIRE(true == unionFind.connected(3, 7));
        REQUIRE(false == unionFind.connected(1, 7));
    }
}
