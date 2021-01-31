#include <catch2/catch.hpp>

#include "algorithms/graph_algorithms.h"
#include "algorithms/search_algorithms.hpp"
#include "algorithms/selection_algorithms.hpp"
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

    SECTION("graph sorting algorithms") {
        SECTION("graph topological sort") {
            std::shared_ptr<data_structures::graph> _graph = std::make_shared<data_structures::graph>(7);
            _graph->add_edge(3, 1, 2);
            _graph->add_edge(3, 4, 4);
            _graph->add_edge(1, 2, -1);
            _graph->add_edge(4, 0, 2);
            _graph->add_edge(2, 5, 5);
            _graph->add_edge(2, 6, 5);

            std::stack<unsigned int> stack = algorithms::topological_sort(_graph);
            REQUIRE(stack.top() == 3);
        }
    }

    SECTION("graph shortest path algorithms") {
        SECTION("dijkstra") {
            std::shared_ptr<data_structures::graph> _graph = std::make_shared<data_structures::graph>();
            _graph->add_edge(0, 1, 4);
            _graph->add_edge(0, 2, 4);
            _graph->add_edge(2, 3, 1);
            _graph->add_edge(2, 4, 6);
            _graph->add_edge(2, 5, 3);
            _graph->add_edge(3, 4, 3);
            _graph->add_edge(5, 4, 2);

            std::vector<double> expected = { 0, 4, 4, 5, 8, 7 };
            REQUIRE(algorithms::dijkstra_shortest_path(0, _graph) == expected);
        }

        SECTION("bellman-ford") {
            std::shared_ptr<data_structures::graph> _graph = std::make_shared<data_structures::graph>();
            _graph->add_edge(0, 1, 6);
            _graph->add_edge(0, 2, 7);
            _graph->add_edge(1, 3, 5);
            _graph->add_edge(1, 4, -4);
            _graph->add_edge(1, 2, 8);
            _graph->add_edge(2, 3, -3);
            _graph->add_edge(2, 4, 9);
            _graph->add_edge(3, 1, -2);
            _graph->add_edge(4, 0, 2);
            _graph->add_edge(4, 3, 7);

            std::vector<double> expected = { 0, 2, 7, 4, -2 };
            REQUIRE(algorithms::bellman_ford_shortest_path(0, _graph) == expected);
        }
    }

    SECTION("graph all shortest path algorithms") {
        SECTION("floyd-warshall") {
            const int N = 5;
            const double INF = std::numeric_limits<double>::infinity();

            std::vector<std::vector<double> > adjacency_matrix = {
                {0, 5, INF, 10},
                {INF, 0, 3, INF},
                {INF, INF, 0, 1},
                {INF, INF, INF, 0}
            };

            std::vector<std::vector<double> > expected = {
                { 0.0, 5.0, 8.0, 9.0 },
                { INF, 0.0, 3.0, 4.0 },
                { INF, INF, 0.0, 1.0 },
                { INF, INF, INF, 0.0 }
            };

            REQUIRE(algorithms::floyd_warshall_all_shortest_paths(adjacency_matrix) == expected);
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

TEST_CASE("selection algorithms") {
    SECTION("kth order statistic") {
        SECTION("quick select") {
            auto integer_comparator = [] (std::vector<int>::iterator a, std::vector<int>::iterator b) { return *a < *b; };

            std::vector<int> items = { 3, 6, -1, 5, 24, 24, 4 };
            std::vector<int>::iterator it = algorithms::quick_select(items.begin(), items.end(), items.begin() + 3, integer_comparator);

            REQUIRE(it != items.end());
            REQUIRE(*it == 5);
        }
    }
}