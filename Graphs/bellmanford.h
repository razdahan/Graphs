#pragma once
#include "dijkstra.h"
#include "edge.h"
//source https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
template<class T>
bool bellman_ford_op(graph<T>* graph, vertex<T>* s)
{

	for (auto i=1;i<=graph->vertices.size()-1;i++)
	{
		for(edge<T> *edge:graph->edges)
		{
			relax(graph, edge->src, edge->dest);
		}
	}
	for(edge<T> *edge:graph->edges)/*Testing for negative circle*/
	{
		if(graph->d[edge->dest]>graph->d[edge->src]+graph->w[{edge->src,edge->dest}])
		{
			return true;
		}
	}
	return false;
}






template<class T>
bool bellman_ford(graph<T> *graph,vertex<T> *s)
{
	/*same init method as dijkstra*/
	dij_init(graph, s);
	return bford_op(graph, s);
}