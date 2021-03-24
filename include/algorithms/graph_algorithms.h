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
    void bfs(std::shared_ptr<data_structures::graph> graph, unsigned int startVertex);

    // pseudocode source: https://en.wikipedia.org/wiki/Depth-first_search
    void dfs(std::shared_ptr<data_structures::graph> graph, unsigned int startVertex);

    void topological_sort_util(unsigned int v, std::vector<bool>& visited, std::stack<unsigned int>& stack, std::shared_ptr<data_structures::graph> graph);

    std::stack<unsigned int> topological_sort(std::shared_ptr<data_structures::graph> graph);

    std::vector<double> dijkstra_shortest_path(unsigned int start, std::shared_ptr<data_structures::graph> graph);

    std::vector<double> dijkstra_longest_path(unsigned int start, std::shared_ptr<data_structures::graph> graph);

    std::vector<double> bellman_ford_shortest_path(unsigned int start, std::shared_ptr<data_structures::graph> graph);

    std::vector<std::vector<double>> floyd_warshall_all_shortest_paths(std::vector<std::vector<double>> adjacency_matrix);

    // https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm
    std::vector<std::vector<data_structures::graph_node>> kosaraju_strongly_connected_components(std::shared_ptr<data_structures::graph> graph);

}