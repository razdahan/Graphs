#pragma once
#pragma once
#include "vertex.h"
#include "graph.h"



template <class T>
void dij_init(graph<T>* graph, vertex<T>* s)
{
	std::cout << "root is " << s->id << std::endl;
	graph->d[s] = 0;
	graph->p[s] = NULL;
	/*Initializing the d and p maps, d contains vector that for each vertex gives distance from s vertex to the given vertex*/
	for (vertex<T>* v : graph->vertices)
	{
		if (v->cmp(s->id))
			continue;
		std::cout << "Initialized " << v->id << "in d and p vectors" << std::endl;
		graph->d[v] = infinity;
		graph->p[v] = NULL;
	}

}

template <class T>
void relax(graph<T>* graph, vertex<T>* u, vertex<T>* v)
{
	if (graph->d[v] > graph->d[u] + graph->w[{u, v}])
	{
		graph->d[v] = graph->d[u] + graph->w[{u, v}];
		graph->p[v] = u;
	}
}


template <class T>
void dij_op(graph<T>* graph, vertex<T>* s)
{
	for (vertex<T>* v : graph->vertices)
		graph->pq.push_back(v);


	while (!graph->pq.empty())
	{
		vertex<T>* u = graph->extract_min();
		for (vertex<T>* v : graph->adj[u])
		{
			relax(graph, u, v);
		}

	}


}

template <class T>
void dijkstra(graph<T>* graph, vertex<T>* s)
{
	dij_init(graph, s);
	dij_op(graph, s);
}