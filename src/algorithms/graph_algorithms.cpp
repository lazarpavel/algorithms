#include "algorithms/graph_algorithms.h"

namespace algorithms
{
    // pseudocode source: https://en.wikipedia.org/wiki/Breadth-first_search
    void bfs(std::shared_ptr<data_structures::graph> graph, uint startVertex)
    {
        std::queue<uint> queue;

        std::vector<bool> visited(graph->get_vertices_count(), false);
        std::vector<uint> distance(graph->get_vertices_count(), 0);
        std::vector<uint> parents(graph->get_vertices_count(), 0);

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

        std::vector<bool> visited(graph->get_vertices_count(), false);
        std::vector<uint> distance(graph->get_vertices_count(), 0);
        std::vector<uint> parents(graph->get_vertices_count(), 0);

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

    void topological_sort_util(uint v, std::vector<bool>& visited, std::stack<uint>& stack, std::shared_ptr<data_structures::graph> graph)
    {
        visited[v] = true;

        for (auto node : graph->get_adjacents(v))
        {
            if (!visited[node->get_vertex()])
                topological_sort_util(node->get_vertex(), visited, stack, graph);

        }

        stack.push(v);
    }

    std::stack<uint> topological_sort(std::shared_ptr<data_structures::graph> graph)
    {
        std::vector<bool> visited(graph->get_vertices_count(), false);
        std::stack<uint> stack;

        for (uint v = 0; v < graph->get_vertices_count(); ++v)
        {
            if (!visited[v])
            {
                topological_sort_util(v, visited, stack, graph);
            }
        }

        return stack;
    }

    std::vector<double> dijkstra_shortest_path(uint start, std::shared_ptr<data_structures::graph> graph)
    {
        std::unique_ptr<data_structures::min_heap<std::pair<int, uint>>> priority_queue = std::make_unique<data_structures::min_heap<std::pair<int, uint>>>(graph->get_vertices_count());
        std::vector<double> distance(graph->get_vertices_count(), std::numeric_limits<double>::infinity());

        priority_queue->insert(std::make_pair(0, start));
        distance[start] = 0;

        while(!priority_queue->is_empty())
        {
            uint current = priority_queue->extract().second;
            auto adjacents = graph->get_adjacents(current);

            for (auto node : adjacents)
            {
                if (distance[node->get_vertex()] > distance[current] + node->get_weight())
                {
                    distance[node->get_vertex()] = distance[current] + node->get_weight();
                    priority_queue->insert(std::make_pair(distance[node->get_vertex()], node->get_vertex()));
                }
            }
        }

        return distance;
    }

    std::vector<double> dijkstra_longest_path(uint start, std::shared_ptr<data_structures::graph> graph)
    {
        std::unique_ptr<data_structures::min_heap<std::pair<int, uint>>> priority_queue = std::make_unique<data_structures::min_heap<std::pair<int, uint>>>(graph->get_vertices_count());
        std::vector<double> inverse_distance(graph->get_vertices_count(), std::numeric_limits<double>::infinity());
        std::vector<double> distance(graph->get_vertices_count(), std::numeric_limits<double>::infinity());

        priority_queue->insert(std::make_pair(0, start));
        distance[start] = 0;
        inverse_distance[start] = 0;

        while(!priority_queue->is_empty())
        {
            uint current = priority_queue->extract().second;
            auto adjacents = graph->get_adjacents(current);

            for (auto node : adjacents)
            {
                if (node->get_weight() == 0 && inverse_distance[node->get_vertex()] > inverse_distance[current])
                {
                    distance[node->get_vertex()] = distance[current];
                    inverse_distance[node->get_vertex()] = inverse_distance[current];
                    priority_queue->insert(std::make_pair(inverse_distance[node->get_vertex()], node->get_vertex()));
                }
                else if (inverse_distance[node->get_vertex()] > inverse_distance[current] - node->get_weight())
                {
                    distance[node->get_vertex()] = distance[current] + node->get_weight();
                    inverse_distance[node->get_vertex()] = inverse_distance[current] - node->get_weight();
                    priority_queue->insert(std::make_pair(inverse_distance[node->get_vertex()], node->get_vertex()));
                }
            }
        }

        return distance;
    }

    std::vector<double> bellman_ford_shortest_path(uint start, std::shared_ptr<data_structures::graph> graph)
    {
        std::vector<double> distance(graph->get_vertices_count(), std::numeric_limits<double>::infinity());
        distance[start] = 0;

        for (uint it = 0; it < graph->get_vertices_count() - 1; ++it)
        {
            for (auto edge : graph->get_edges())
            {
                if (distance[edge->get_dst()] > distance[edge->get_src()] + edge->get_weight())
                {
                    distance[edge->get_dst()] = distance[edge->get_src()] + edge->get_weight();
                }
            }
        }

        for (auto edge : graph->get_edges())
        {
            if (distance[edge->get_dst()] > distance[edge->get_src()] + edge->get_weight())
            {
                throw std::invalid_argument("graph contains negative cycles");
            }
        }

        return distance;
    }

    std::vector<std::vector<double>> floyd_warshall_all_shortest_paths(std::vector<std::vector<double>> adjacency_matrix)
    {
        const size_t N = adjacency_matrix.size();

        for (size_t r = 0; r < N; ++r)
            if (N != adjacency_matrix[r].size()) throw std::invalid_argument("Invalid adjacency matrix argument");

        std::vector<std::vector<double>> distances(N, std::vector<double>(N, 0));

        for (size_t r = 0; r < N; ++r)
        {
            for (size_t c = 0; c < N; ++c)
            {
                distances[r][c] = adjacency_matrix[r][c];
            }
        }

        for (size_t k = 0; k < N; ++k)
        {
            for (size_t r = 0; r < N; ++r)
            {
                for (size_t c = 0; c < N; ++c)
                {
                    if (distances[r][k] + distances[k][c] < distances[r][c])
                        distances[r][c] = distances[r][k] + distances[k][c];
                }
            }
        }

        return distances;
    }

}