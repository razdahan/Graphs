#pragma once
#include "vertex.h"
#include "graph.h"
const int infinity = std::numeric_limits<int>::max();
template <class T>
void bfs_init(graph<T>* graph, vertex<T>* s)
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
	graph->queue.push(s);
}

template <class T>
void bfs_op(graph<T>* graph, vertex<T>* s)
{
	while (!graph->queue.empty())
	{
		auto* u = graph->queue.front();
		graph->queue.pop();
		for (auto* v : graph->adj[u])
		{
			auto const temp = graph->d[v];
			if (temp == infinity)
			{
				graph->d[v] = graph->d[u] + 1;
				graph->p[v] = u;
				graph->queue.push(v);
			}
		}
	}


}

template <class T>
void bfs(graph<T>* graph, vertex<T>* s)
{
	//initializing the d and p array
	bfs_init(graph, s);
	bfs_op(graph, s);
}