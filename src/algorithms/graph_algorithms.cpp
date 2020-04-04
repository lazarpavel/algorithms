namespace algorithms
{
// pseudocode source: https://en.wikipedia.org/wiki/Breadth-first_search
void bfs(shared_ptr<graph> graph, uint startVertex) {
    std::queue queue;

    std::vector<bool> visited(graph->get_vertices_count(), false);
    std::vector<uint> distance(graph->get_vertices_count(), 0);
    std::vector<uint> parents(graph->get_vertices_count(), 0);

    visited[startVertex] = true;
    distance[startVertex] = 0;

    queue.push(startVertex);

    while (!queue.empty())
    {
        uint current = queue.pop();
        auto adjacents = graph->get_adjacents(current);

        for (auto node : adjacents) {
            if (!visited[node]) {
                distance[node] = distance[current] + 1;
                parents[node] = current;
                visited[node] = true;

                queue.push(n);
            }
        }
    }
}

// pseudocode source: https://en.wikipedia.org/wiki/Depth-first_search
void dfs(shared_ptr<graph> graph, uint startVertex) {
    std::stack stack;

    std::vector<bool> visited(graph->get_vertices_count(), false);
    std::vector<uint> distance(graph->get_vertices_count(), 0);
    std::vector<uint> parents(graph->get_vertices_count(), 0);

    visited[startVertex] = true;
    distance[startVertex] = 0;

    stack.push(startVertex);

    while (!stack.empty())
    {
        uint current = stack.pop();
        auto adjacents = graph->get_adjacents(current);

        for (auto node : adjacents) {
            if (!visited[node]) {
                distance[node] = distance[current] + 1;
                parents[node] = current;
                visited[node] = true;

                stack.push(n);
            }
        }
    }
}

}
