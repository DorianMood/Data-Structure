#include <iostream>
#include "AdjacencyWDigraph.h"
#include "AdjacencyWGraph.h"

int main()
{
	AdjacencyWGraph<int> G(4, 100);
	std::cout << "Edges = " << G.Edges() << std::endl;
	G.Add(2, 4, 1).Add(1, 3, 2).Add(2, 1, 3).Add(1, 4, 4).Add(4, 3, 5);
	std::cout << "The graph is" << std::endl;
	G.Output();
	G.Delete(2, 1);
	std::cout << "The graph after deleting <2,1> is" << std::endl;
	G.Output();
	std::cout << "Exist(3,1) = " << G.Exist(3, 1) << std::endl;
	std::cout << "InDegree(3) = " << G.InDegree(3) << std::endl;
	std::cout << "OutDegree(1) = " << G.OutDegree(1) << std::endl;
	std::cout << "Edges = " << G.Edges() << std::endl;


	// Assignment 9
	//AdjacencyWGraph<int> WG(6, 100);

	auto mst = G.MinimumSpanningTree();
	mst->Output();
}
