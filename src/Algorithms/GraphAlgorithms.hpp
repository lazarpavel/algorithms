#pragma once

#include <memory>
#include <queue>
#include <stack>

#include "UGraph.hpp"

namespace algorithms
{
    // pseudocode source: https://en.wikipedia.org/wiki/Breadth-first_search
    void bfs(shared_ptr<UGraph> graph, uint startVertex)
    {
        std::queue queue;

        std::vector<bool> visited (graph->getVerticesCount(), false);
        std::vector<uint> distance (graph->getVerticesCount(), 0);
        std::vector<uint> parents (graph->getVerticesCount(), 0);

        visited[startVertex] = true;
        distance[startVertex] = 0;

        queue.push(startVertex);

        while (!queue.empty())
        {
            uint current = queue.pop();
            auto adjacents = graph->getAdjacents(current);

            for (auto node : adjacents)
            {
                if (!visited[node])
                {
                    distance[node] = distance[current] + 1;
                    parants[node] = current;
                    visited[node] = true;

                    queue.push(n);
                }
            }
        }
    }

    // pseudocode source: https://en.wikipedia.org/wiki/Depth-first_search
    void dfs(shared_ptr<UGraph> graph, uint startVertex)
    {
        std::stack stack;

        std::vector<bool> visited (graph->getVerticesCount(), false);
        std::vector<uint> distance (graph->getVerticesCount(), 0);
        std::vector<uint> parents (graph->getVerticesCount(), 0);

        visited[startVertex] = true;
        distance[startVertex] = 0;

        stack.push(startVertex);

        while (!stack.empty())
        {
            uint current = stack.pop();
            auto adjacents = graph->getAdjacents(current);

            for (auto node : adjacents)
            {
                if (!visited[node])
                {
                    distance[node] = distance[current] + 1;
                    parants[node] = current;
                    visited[node] = true;

                    stack.push(n);
                }
            }
        }
    }
}

