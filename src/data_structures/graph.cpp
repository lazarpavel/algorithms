#include "data_structures/graph.h"

namespace data_structures
{
    // graph node
    graph_node::graph_node(uint vertex, double weight)
    {
        this->m_vertex = vertex;
        this->m_weight = weight;
    }

    uint graph_node::get_vertex() { return this->m_vertex; }

    double graph_node::get_weight() { return this->m_weight; }

    // graph edge
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

    // graph
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