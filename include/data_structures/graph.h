#pragma once

#include <exception>
#include <memory>
#include <set>
#include <vector>

namespace data_structures
{
    class graph_node
    {
    public:
        graph_node(uint vertex, double weight);

    public:
        uint get_vertex();
        double get_weight();

    private:
        uint m_vertex;
        double m_weight;
    };

    class graph_edge
    {
    public:
        graph_edge(uint src, uint dst, double weight);

    public:
        uint get_src();
        uint get_dst();
        double get_weight();

    private:
        uint src;
        uint dst;
        double weight;
    };

    //
    // Directed Weighted Graph API
    //
    class graph
    {
    public:
        // creates and empty graph with vertices_count vertices
        graph(uint vertices_count);

        graph();

    public:
        // add an edge between vertices v and w
        void add_edge(uint v, uint w, double weight);

        // return vertices adjacents to vertex v
        std::set<std::shared_ptr<graph_node>> get_adjacents(uint v) const;
        std::set<std::shared_ptr<graph_edge>> get_edges() const;

        uint get_vertices_count() const;
        uint get_edges_count() const;

    private:
        std::vector<std::set<std::shared_ptr<graph_node>>> m_vertices;
        std::set<std::shared_ptr<graph_edge>> m_edges;
        uint m_vertices_count;
        uint m_edges_count;
    };
}