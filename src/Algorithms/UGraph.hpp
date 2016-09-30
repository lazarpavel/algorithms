#pragma once

#include <vector>
#include <exception>

namespace datastructures
{
    //
    // UnDirected Graph API
    //
    class UGraph
    {
    public:
        // creates and empty graph with verticesCount vertices
        UGraph(uint verticesCount);

    public:
        // add an edge between vertices v and w
        void addEdge(uint v, uint w);

        // return vertices adjacents to vertex v
        std::set<uint> getAdjacents(uint v) const;

        uint getVerticesCount() const;
        uint getEdgesCount() const;

    private:
        std::vector<std::set<uint>> m_vertices;
        uint m_verticesCount;
        uint m_edgesCount;
    };

    UGraph::UGraph(uint verticesCount)
        : m_vertices(verticesCount, std::set<uint>)
    {
        m_verticesCount = verticesCount;
        m_edgesCount = 0;
    }

    void UGraph::addEdge(uint v, uint w)
    {
        if (v >= m_verticesCount)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        if (v >= m_verticesCount)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(w));

        m_vertices[v].insert(w);
    }

    std::set<uint> UGraph::getAdjacents(uint v) const
    {
        if (v >= m_verticesCount)
            throw new std::out_of_range("Invalid vertex index: " + std::to_string(v));

        return m_vertices[v];
    }

    uint UGraph::getVerticesCount() const { return m_verticesCount; }
    uint UGraph::getEdgesCount() const { return m_edgesCount; }
}
