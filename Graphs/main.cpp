#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include <queue>
#include "vertex.h"
#include "edge.h"
#include "bfs.h"
#include "dijkstra.h"

//source - https://en.wikipedia.org/wiki/Breadth-first_search
int main()
{
	//declare the graph vertices
	std::vector<vertex<int>*> vertices = { new vertex<int>(1), new vertex<int>(2), new vertex<int>(3) };
	const std::vector<edge<int>*> edges;
	graph<int> graph(vertices, edges);

	//add edges between graph vertices - adds them to the graph edges prop and the adj map
	graph.add_edge(vertices[0], vertices[1], 4);
	graph.add_edge(vertices[1], vertices[2], 6);
	graph.add_edge(vertices[2], vertices[0], 10);
	graph.add_edge(vertices[0], vertices[2], 5);

	dijkstra(&graph, vertices[0]);
	std::cout << "result dijkstra distance from " << vertices[0]->id << " to " << vertices[2]->id << " is ";
	std::cout << graph.d[vertices[2]] << std::endl;

	bfs(&graph, vertices[0]);
	std::cout << "result bfs distance from " << vertices[0]->id << " to " << vertices[2]->id << " is ";
	std::cout << graph.d[vertices[2]] << std::endl;

	std::string hold;
	std::cin >> hold;
	return 0;
}
