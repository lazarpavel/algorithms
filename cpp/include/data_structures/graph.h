#pragma once

#include <memory>
#include <set>
#include <vector>

namespace data_structures
{
    class graph_node
    {
    public:
        graph_node(unsigned int vertex, double weight);

    public:
        unsigned int get_vertex();
        double get_weight();

    private:
        unsigned int m_vertex;
        double m_weight;
    };

    class graph_edge
    {
    public:
        graph_edge(unsigned int src, unsigned int dst, double weight);

    public:
        unsigned int get_src();
        unsigned int get_dst();
        double get_weight();

    private:
        unsigned int src;
        unsigned int dst;
        double weight;
    };

    //
    // Directed Weighted Graph API
    //
    class graph
    {
    public:
        // creates and empty graph with vertices_count vertices
        graph(unsigned int vertices_count);

        graph();

    public:
        // add an edge between vertices v and w
        void add_edge(unsigned int v, unsigned int w, double weight);

        // return vertices adjacents to vertex v
        std::set<std::shared_ptr<graph_node>> get_adjacents(unsigned int v) const;
        std::set<std::shared_ptr<graph_edge>> get_edges() const;

        unsigned int get_vertices_count() const;
        unsigned int get_edges_count() const;

    private:
        std::vector<std::set<std::shared_ptr<graph_node>>> m_vertices;
        std::set<std::shared_ptr<graph_edge>> m_edges;
        unsigned int m_vertices_count;
        unsigned int m_edges_count;
    };
}