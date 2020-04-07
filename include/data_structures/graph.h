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

    graph_node::graph_node(uint vertex, double weight)
    {
        this->m_vertex = vertex;
        this->m_weight = weight;
    }

    uint graph_node::get_vertex() { return this->m_vertex; }

    double graph_node::get_weight() { return this->m_weight; }

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

    graph_edge::graph_edge(uint src, uint dst, double weight)
    {
        this->src = src;
        this->dst = dst;
        this->weight = weight;
    }

    uint graph_edge::get_src()
    {
        return this->src;
    }

    uint graph_edge::get_dst()
    {
        return this->dst;
    }

    double graph_edge::get_weight()
    {
        return this->weight;
    }

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

    graph::graph(uint vertices_count)
        : m_vertices(vertices_count, std::set<std::shared_ptr<graph_node>>())
    {
        m_vertices_count = vertices_count;
        m_edges_count = 0;
    }

    graph::graph()
    {
        m_vertices_count = 0;
        m_edges_count = 0;
    }

    void graph::add_edge(uint v, uint w, double weight)
    {
        if (std::max(v, w) >= m_vertices_count)
        {
            m_vertices_count = std::max(v, w) + 1;
            m_vertices.resize(m_vertices_count, std::set<std::shared_ptr<graph_node>>());
        }

        ++m_edges_count;
        m_edges.insert(std::make_shared<graph_edge>(v, w, weight));
        m_vertices[v].insert(std::make_shared<graph_node>(w, weight));
    }

    std::set<std::shared_ptr<graph_node>> graph::get_adjacents(uint v) const
    {
        if (v >= m_vertices_count)
            throw new std::out_of_range("invalid vertex index: " + std::to_string(v));

        return m_vertices[v];
    }

    std::set<std::shared_ptr<graph_edge>> graph::get_edges() const
    {
        return m_edges;
    }

    uint graph::get_vertices_count() const { return m_vertices_count; }

    uint graph::get_edges_count() const { return m_edges_count; }

}