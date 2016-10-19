#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "./Algorithms/SortingAlgorithms.hpp"
#include "./Algorithms/SearchAlgorithms.hpp"
#include "./DataStructures/UnionFind.hpp"

using namespace std;
using namespace datastructures;
using namespace algorithms;

TEST_CASE("Combinatorial Algorithms")
{
    SECTION("Cycle Detection")
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
}

TEST_CASE("Graph Algorithms")
{
    SECTION("Graph Searching")
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
}

TEST_CASE("Sorting Algorithms")
{
    SECTION("Data Sorting")
    {
        SECTION("Selection Sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            selectionSort(items);

            REQUIRE(items == expected);
        }

        SECTION("Heap Sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            heapSort(items);

            REQUIRE(items == expected);
        }

        SECTION("Merge Sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            mergeSort(items);

            REQUIRE(items == expected);
        }

        SECTION("Quick Sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            quickSort(items);

            REQUIRE(items == expected);
        }

        SECTION("Insertion Sort")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            insertionSort(items);

            REQUIRE(items == expected);
        }
    }
}

TEST_CASE("Search Algorithms")
{
    SECTION("Data Searching")
    {
        SECTION("Linear Search")
        {
            vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };

            vector<int>::iterator it = linearSearch(items.begin(), items.end(), -1);

            REQUIRE(it != items.end());
            REQUIRE(*it == -1);
        }

        SECTION("Binary Search")
        {
            vector<int> items = { -1, 3, 3, 5, 6, 24, 24 };

            vector<int>::iterator it = binarySearch(items.begin(), items.end(), 24);
            REQUIRE(*it == 24);

            it = binarySearch(items.begin(), items.end(), 2);
            REQUIRE(it == items.end());
        }
    }
}

TEST_CASE("Data Structures")
{
    SECTION("Union Find")
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
}
