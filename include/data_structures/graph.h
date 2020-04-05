#pragma once

#include <exception>
#include <memory>
#include <set>
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
        uint m_vertex;
        int m_weight;
    };

    adjacent_node::adjacent_node(uint vertex, int weight)
    {
        this->m_vertex = vertex;
        this->m_weight = weight;
    }

    uint adjacent_node::get_vertex() { return this->m_vertex; }

    int adjacent_node::get_weight() { return this->m_weight; }

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
        std::set<std::shared_ptr<adjacent_node>> get_adjacents(uint v) const;

        uint get_vertices_count() const;
        uint get_edges_count() const;

    private:
        std::vector<std::set<std::shared_ptr<adjacent_node> > > m_vertices;
        uint m_vertices_count;
        uint m_edges_count;
    };

    graph::graph(uint vertices_count)
        : m_vertices(vertices_count, std::set<std::shared_ptr<adjacent_node>>())
    {
        m_vertices_count = vertices_count;
        m_edges_count = 0;
    }

    void graph::add_edge(uint v, uint w, int weight)
    {
        if (v >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        if (w >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(w));

        m_vertices[v].insert(std::make_shared<adjacent_node>(w, weight));
    }

    std::set<std::shared_ptr<adjacent_node> > graph::get_adjacents(uint v) const
    {
        if (v >= m_vertices_count)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        return m_vertices[v];
    }

    uint graph::get_vertices_count() const { return m_vertices_count; }

    uint graph::get_edges_count() const { return m_edges_count; }

}