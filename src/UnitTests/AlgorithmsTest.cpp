#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "./Algorithms/SortingAlgorithms.hpp"

using namespace std;

TEST_CASE("Cycle Detection", "Combinatorial Algorithms")
{
    SECTION("Floyd's Algorithm")
    {
        // TODO:
    }

    SECTION("Brent's Algorithm")
    {
        // TODO:
    }
}

TEST_CASE("Graph Searching", "Graph Algorithms")
{
    SECTION("BFS Algorithm")
    {
        // TODO:
    }

    SECTION("DFS Algorithm")
    {
        // TODO:
    }
}

TEST_CASE("Data Sorting", "Sorting Algorithms")
{
    SECTION("Selection Sort")
    {
        vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
        vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

        algorithms::selectionSort(items);

        REQUIRE(items == expected);
    }

    SECTION("Heap Sort")
    {
        vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
        vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

        algorithms::heapSort(items);

        REQUIRE(items == expected);
    }

    SECTION("Merge Sort")
    {
        vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
        vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

        algorithms::mergeSort(items);

        REQUIRE(items == expected);
    }

    SECTION("Quick Sort")
    {
        vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
        vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

        algorithms::quickSort(items);

        REQUIRE(items == expected);
    }
}
