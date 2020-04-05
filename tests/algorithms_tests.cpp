#include <catch2/catch.hpp>

#include "algorithms/graph_algorithms.hpp"
#include "algorithms/search_algorithms.hpp"
#include "algorithms/sorting_algorithms.hpp"
#include "data_structures/graph.h"

#include <memory>

TEST_CASE("combinatorial algorithms") {
    SECTION("cycle detection") {
        SECTION("Floyd's algorithm") {
            // TODO:
        }

        SECTION("Brent's algorithm") {
            // TODO:
        }
    }
}

TEST_CASE("graph algorithms") {
    SECTION("graph searching") {
        SECTION("BFS algorithm") {
            std::shared_ptr<data_structures::graph> _graph = std::make_shared<data_structures::graph>(5);
            _graph->add_edge(0, 3, 2);
            _graph->add_edge(0, 1, 4);
            _graph->add_edge(1, 2, -1);
            _graph->add_edge(2, 3, 2);
            _graph->add_edge(2, 4, 5);

            algorithms::bfs(_graph, 0);
        }

        SECTION("DFS algorithm") {
            std::shared_ptr<data_structures::graph> _graph = std::make_shared<data_structures::graph>(5);
            _graph->add_edge(0, 3, 2);
            _graph->add_edge(0, 1, 4);
            _graph->add_edge(1, 2, -1);
            _graph->add_edge(2, 3, 2);
            _graph->add_edge(2, 4, 5);

            algorithms::dfs(_graph, 0);
        }
    }
}

TEST_CASE("sorting algorithms") {
    SECTION("data sorting") {
        SECTION("selection sort") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            algorithms::selection_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("heap sort") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            algorithms::heap_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("merge sort") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            algorithms::merge_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("quick sort") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            algorithms::quick_sort(items);

            REQUIRE(items == expected);
        }

        SECTION("insertion sort") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int> expected = { -1, 3, 3, 5, 6, 24, 24 };

            algorithms::insertion_sort(items);

            REQUIRE(items == expected);
        }
    }
}

TEST_CASE("search algorithms") {
    SECTION("data searching") {
        SECTION("linear search") {
            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 3 };
            std::vector<int>::iterator it = algorithms::linear_search(items.begin(), items.end(), -1);

            REQUIRE(it != items.end());
            REQUIRE(*it == -1);
        }

        SECTION("binary search") {
            std::vector<int> items = { -1, 3, 3, 5, 6, 24, 24 };

            std::vector<int>::iterator it = algorithms::binary_search(items.begin(), items.end(), 24);
            REQUIRE(*it == 24);

            it = algorithms::binary_search(items.begin(), items.end(), 2);
            REQUIRE(it == items.end());
        }
    }
}