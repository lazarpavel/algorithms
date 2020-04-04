#pragma once

#include <exception>
#include <vector>

namespace data_structures
{
    class adjacent_node
    {
    public:
        adjacent_node(uint vertex, int weight);

    public:
        uint get_vertex();
        int get_weight();

    private:
        uint vertex;
        int weight;
    };

    adjacent_node::adjacent_node(uint vertex, int weight)
    {
        this->vertex = vertex;
        this->weight = weight;
    }

    uint adjacent_node::get_vertex() { return this->vertex; }

    int adjacent_node::get_weight() { return this->weight; }

    //
    // Directed Weighted Graph API
    //
    class graph
    {
    public:
        // creates and empty graph with vertices_count vertices
        graph(uint vertices_count);

    public:
        // add an edge between vertices v and w
        void add_edge(uint v, uint w, int weight);

        // return vertices adjacents to vertex v
        std::set<uint> get_adjacents(uint v) const;

        uint get_vertices_count() const;
        uint get_edges_count() const;

    private:
        std::vector<set<adjacent_node> > m_vertices;
        uint m_vertices_count;
        uint m_edges_count;
    };

    graph::graph(uint vertices_count)
        : m_vertices(vertices_count, std::set<uint>)
    {
        m_vertices_count = vertices_count;
        m_edges_count = 0;
    }

    void graph::add_edge(uint v, uint w, int weight)
    {
        if (v >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        if (vw >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(w));

        m_vertices[v].insert(w);
    }

    std::set<uint> graph::get_adjacents(uint v) const
    {
        if (v >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        return m_vertices[v];
    }

    uint graph::get_vertices_count() const { return m_vertices_count; }

    uint graph::get_edges_count() const { return m_edges_count; }

}