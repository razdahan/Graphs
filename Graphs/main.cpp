#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include <queue>
#include "vertex.h"
#include "edge.h"
#include "bfs.h"
#include "dijkstra.h"
#include "bellmanford.h"
#include "primebasic.h"

int main()
{
	//declare the graph vertices
	std::vector<vertex<int>*> vertices = { new vertex<int>(1), new vertex<int>(2), new vertex<int>(3) };
	const std::vector<edge<int>*> edges;
	graph<int> g(vertices, edges);

	//add edges between graph vertices - adds them to the graph edges prop and the adj map
	g.add_edge(vertices[0], vertices[1], 4);
	g.add_edge(vertices[1], vertices[2], 6);
	g.add_edge(vertices[2], vertices[0], -12);
	
	
	 dijkstra(&g, vertices[0]);
	 std::cout << "result dijkstra distance from " << vertices[0]->id << " to " << vertices[2]->id << " is ";
	 std::cout << g.d[vertices[2]] << std::endl;
	
	 bfs(&g, vertices[0]);
	 std::cout << "result bfs distance from " << vertices[0]->id << " to " << vertices[2]->id << " is ";
	 std::cout << g.d[vertices[2]] << std::endl;
	
	 std::cout << "bellman ford result " << bellman_ford(&g, vertices[0]) << std::endl;

	graph<int> *graph =prime_basic(&g);
	std::cout << graph->edges.size()<< std::endl;

	std::string hold;
	std::cin >> hold;
	return 0;
}
