#include "catch.hpp"

#include "Algorithms/SortingAlgorithms.hpp"
#include "Algorithms/SearchAlgorithms.hpp"

using namespace std;
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

