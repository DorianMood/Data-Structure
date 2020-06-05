#ifndef ADJECENCY_GRAPH
#define ADJECENCY_GRAPH

#include "AdjacencyWGraph.h"

class AdjacencyGraph : public AdjacencyWGraph<int>
{
public:
    AdjacencyGraph(int Vertices = 10) : AdjacencyWGraph<int>(Vertices, 0) {}
    AdjacencyGraph& Add(int i, int j)
    {
        AdjacencyWGraph<int>::Add(i, j, 1);
        return *this;
    }
    AdjacencyGraph& Delete(int i, int j)
    {
        AdjacencyWGraph<int>::Delete(i, j);
        return *this;
    }
};
#endif