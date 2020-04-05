#pragma once

#include <memory>
#include <queue>
#include <stack>

#include "data_structures/graph.h"

namespace algorithms
{
    // pseudocode source: https://en.wikipedia.org/wiki/Breadth-first_search
    void bfs(std::shared_ptr<data_structures::graph> graph, uint startVertex)
    {
        std::queue<uint> queue;

        std::vector<bool> visited (graph->get_vertices_count(), false);
        std::vector<uint> distance (graph->get_vertices_count(), 0);
        std::vector<uint> parents (graph->get_vertices_count(), 0);

        visited[startVertex] = true;
        distance[startVertex] = 0;

        queue.push(startVertex);

        while (!queue.empty())
        {
            uint current = queue.front();
            queue.pop();

            auto adjacents = graph->get_adjacents(current);

            for (auto node : adjacents)
            {
                if (!visited[node->get_vertex()])
                {
                    distance[node->get_vertex()] = distance[current] + node->get_weight();
                    parents[node->get_vertex()] = current;
                    visited[node->get_vertex()] = true;

                    queue.push(node->get_vertex());
                }
            }
        }
    }

    // pseudocode source: https://en.wikipedia.org/wiki/Depth-first_search
    void dfs(std::shared_ptr<data_structures::graph> graph, uint startVertex)
    {
        std::stack<uint> stack;

        std::vector<bool> visited (graph->get_vertices_count(), false);
        std::vector<uint> distance (graph->get_vertices_count(), 0);
        std::vector<uint> parents (graph->get_vertices_count(), 0);

        visited[startVertex] = true;
        distance[startVertex] = 0;

        stack.push(startVertex);

        while (!stack.empty())
        {
            uint current = stack.top();
            stack.pop();

            auto adjacents = graph->get_adjacents(current);

            for (auto node : adjacents)
            {
                if (!visited[node->get_vertex()])
                {
                    distance[node->get_vertex()] = distance[current] + node->get_weight();
                    parents[node->get_vertex()] = current;
                    visited[node->get_vertex()] = true;

                    stack.push(node->get_vertex());
                }
            }
        }
    }
}

