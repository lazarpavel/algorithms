#include "catch.hpp"

#include "algorithms/sorting_algorithms.hpp"
#include "algorithms/search_algorithms.hpp"

using namespace std;
using namespace algorithms;

TEST_CASE("combinatorial algorithms")
{
    SECTION("cycle detection")
    {
        SECTION("Floyd's algorithm")
        {
            // TODO:
        }

        SECTION("Brent's algorithm")
        {
            // TODO:
        }
    }
}

TEST_CASE("graph algorithms")
{
    SECTION("graph searching")
    {
        SECTION("BFS algorithm")
        {
            // TODO:
        }

        SECTION("DFS algorithm")
        {
            // TODO:
        }
    }
}

TEST_CASE("sorting algorithms")
{
    SECTION("data sorting")
    {
        SECTION("selection sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            selection_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("heap sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            heap_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("merge sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            merge_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("quick sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            quick_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("insertion sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            insertionSort(items);

            REQUIRE(items == expected);
        }
    }
}

TEST_CASE("search algorithms")
{
    SECTION("data searching")
    {
        SECTION("linear search")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };

            vector<int>::iterator it = algorithms::linear_search(items.begin(), items.end(), -1);

            REQUIRE(it != items.end());
            REQUIRE(*it == -1);
        }

        SECTION("binary search")
        {
            vector<int> items = { -1, 3, 3, 5, 6, 24, 24 };

            vector<int>::iterator it = algorithms::binary_search(items.begin(), items.end(), 24);
            REQUIRE(*it == 24);

            it = algorithms::binary_search(items.begin(), items.end(), 2);
            REQUIRE(it == items.end());
        }
    }
}

