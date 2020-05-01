#pragma once

#include <exception>
#include <memory>
#include <queue>
#include <stack>

#include "data_structures/graph.h"
#include "data_structures/min_heap.hpp"

namespace algorithms
{
    // pseudocode source: https://en.wikipedia.org/wiki/Breadth-first_search
    void bfs(std::shared_ptr<data_structures::graph> graph, uint startVertex);

    // pseudocode source: https://en.wikipedia.org/wiki/Depth-first_search
    void dfs(std::shared_ptr<data_structures::graph> graph, uint startVertex);

    void topological_sort_util(uint v, std::vector<bool>& visited, std::stack<uint>& stack, std::shared_ptr<data_structures::graph> graph);

    std::stack<uint> topological_sort(std::shared_ptr<data_structures::graph> graph);

    std::vector<double> dijkstra_shortest_path(uint start, std::shared_ptr<data_structures::graph> graph);

    std::vector<double> dijkstra_longest_path(uint start, std::shared_ptr<data_structures::graph> graph);

    std::vector<double> bellman_ford_shortest_path(uint start, std::shared_ptr<data_structures::graph> graph);

    std::vector<std::vector<double>> floyd_warshall_all_shortest_paths(std::vector<std::vector<double>> adjacency_matrix);

}