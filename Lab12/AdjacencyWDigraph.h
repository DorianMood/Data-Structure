#ifndef ADJECENCY_W_DIGRAPH
#define ADJECENCY_W_DIGRAPH

#include <iomanip>
#include <iostream>
#include <set>
#include <stack>

#include "myExceptions.h"
#include "ArrayUtil.h"
//#include "AdjacencyWGraph.h"

template<class T>
class AdjacencyWDigraph {
    friend AdjacencyWDigraph<T>;
public:
    AdjacencyWDigraph(int Vertices = 10, T noEdge = 0);
    AdjacencyWDigraph(AdjacencyWDigraph<T>* g);
    ~AdjacencyWDigraph() { Delete2DArray(a, n + 1); }
    bool Exist(int i, int j) const;
    int Edges()  const { return e; }
    int Vertices() const { return n; }
    AdjacencyWDigraph<T>& Add(int i, int j, const T& w);
    AdjacencyWDigraph<T>& Delete(int i, int j);
    int OutDegree(int i) const;
    int InDegree(int i) const;
    void Output() const;

    // Assignment 9
    AdjacencyWDigraph<T>* MinimumSpanningTree();
protected:
    T NoEdge;  // used for absent edge
    int n;     // number of vertices
    int e;     // number of edges
    T** a;     // 2D array
};

template<class T>
AdjacencyWDigraph<T>::AdjacencyWDigraph(int Vertices, T noEdge)
{// Constructor.
    n = Vertices;
    e = 0;
    NoEdge = noEdge;
    Make2DArray(a, n + 1, n + 1);
    T x = a[1][1];
    // initalize to graph with no edges
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = NoEdge;
}

template<class T>
AdjacencyWDigraph<T>::AdjacencyWDigraph(AdjacencyWDigraph<T>* g)
{
    n = g->n;
    e = g->e;
    NoEdge = g->NoEdge;
    Make2DArray(a, n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = g->a[i][j];
        }
    }
}

template<class T>
bool AdjacencyWDigraph<T>::Exist(int i, int j) const
{// Does edge (i, j) exist?
    if (i < 1 || j < 1 || i > n || j > n || a[i][j] == NoEdge) return false;
    return true;
}

template<class T>
AdjacencyWDigraph<T>& AdjacencyWDigraph<T>::Add(int i, int j, const T& w)
{// Add edge (i,j) to digraph if not present.
    T x = a[i][j];
    if (i < 1 || j < 1 || i > n || j > n || i == j || a[i][j] != NoEdge)
        throw illegalInputData();
    a[i][j] = w;
    e++;
    return *this;
}

template<class T>
AdjacencyWDigraph<T>& AdjacencyWDigraph<T>::Delete(int i, int j)
{// Delete edge (i,j).
    if (i < 1 || j < 1 || i > n || j > n || a[i][j] == NoEdge)
        throw illegalInputData();
    a[i][j] = NoEdge;
    e--;
    return *this;
}

template<class T>
int AdjacencyWDigraph<T>::OutDegree(int i) const
{// Return out degree of vertex i.
    if (i < 1 || i > n) throw illegalInputData();
    // count out edges from vertex i
    int sum = 0;
    for (int j = 1; j <= n; j++)
        if (a[i][j] != NoEdge) sum++;
    return sum;
}

template<class T>
int AdjacencyWDigraph<T>::InDegree(int i) const
{// Return indegree of vertex i.
    if (i < 1 || i > n) throw illegalInputData();
    // count in edges at vertex i
    int sum = 0;
    for (int j = 1; j <= n; j++)
        if (a[j][i] != NoEdge) sum++;
    return sum;
}

template<class T>
void AdjacencyWDigraph<T>::Output() const
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << setw(10) << a[i][j];
        }
        std::cout << std::endl;
    }
}

template<class T>
AdjacencyWDigraph<T>* AdjacencyWDigraph<T>::MinimumSpanningTree()
{
    AdjacencyWDigraph<T>* g = new AdjacencyWDigraph<T>(this);
    
    // Here do Prims algorithm

    set<int> verts;
    for (int i = 1; i <= n; i++)
    {
        verts.insert(i);
    }

    T** matr;
    Make2DArray(matr, n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            matr[i][j] = NoEdge;
        }
    }

    stack<int> path;
    set<int> current;
    current.insert(*(verts.begin()));
    verts.erase(*(verts.begin()));
    //path.push();
    

    while (!verts.empty())
    {
        // add next node to skeleton
        T m = LONG_MAX;
        int to = *(current.begin());
        int from = to;

        for (auto cur : current)
        {
            for (auto vert : verts)
            {
                if (a[cur][vert] != NoEdge && a[cur][vert] < m)
                {
                    m = a[cur][vert];
                    to = vert;
                    from = cur;
                }
            }
        }

        matr[from][to] = m;
        current.insert(to);
        verts.erase(to);
    }

    g->a = matr;

    return g;
}

#endif