#ifndef ADJECENCY_W_GRAPH
#define ADJECENCY_W_GRAPH

#include "AdjacencyWDigraph.h"

template<class T>
class AdjacencyWGraph : public AdjacencyWDigraph<T> {
public:
    AdjacencyWGraph(int Vertices = 10, T noEdge = 0) : AdjacencyWDigraph<T>(Vertices, noEdge) {}
    AdjacencyWGraph<T>& Add(int i, int j, const T& w)
    {
        AdjacencyWDigraph<T>::Add(i, j, w);
        this->a[j][i] = w;
        return *this;
    }
    AdjacencyWGraph<T>& Delete(int i, int j)
    {
        AdjacencyWDigraph<T>::Delete(i, j);
        this->a[j][i] = this->NoEdge;
        return *this;
    }
    int Degree(int i) const { return this->OutDegree(i); }
};
#endif