#pragma once
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <map>
#include <queue>

template <class T>
class graph
{
public:
	std::vector<vertex<T>*> vertices;
	std::vector<edge<T>*> edges;
	std::queue<vertex<T>*> queue;
	std::map<vertex<T>*, int> d;
	std::map<vertex<T>*, vertex<T>*> p;
	std::map<vertex<T>*, std::vector<vertex<T>*>> adj;
	std::vector<vertex<T>*> pq;
	std::map<std::pair<vertex<T>*, vertex<T>*>, int> w;

	graph(std::vector<vertex<T>*> vertices, std::vector<edge<T>*> edges)
	{
		this->vertices = vertices;
		this->edges = edges;
	}

	void add_edge(vertex<T>* u, vertex<T>* v, T weight)
	{
		edge<int>* e = new edge<int>(u, v, weight);
		this->edges.push_back(e);
		this->adj[u].push_back(v);
		this->w[{u, v}] = weight;

		/*add these 2 lines to implement non directional graph
		adj[u].push_back(v);
		this->edges_.push_back(new edge<int>(v, u));
		*/
	}

	void add_edge(vertex<T>* u, vertex<T>* v)
	{
		edge<int>* e = new edge<int>(u, v);
		this->edges.push_back(e);
		this->adj[u].push_back(v);
		this->w[{u, v}] = 1;

		/*add these 2 lines to implement non directional graph
		adj[u].push_back(v);
		this->edges_.push_back(new edge<int>(v, u));
		*/
	}

	vertex<T>* extract_min()
	{
		std::cout << "finding min" << std::endl;
		vertex<T>* min = pq[0];
		auto min_index = 0;
		auto counter = 0;
		for (vertex<T>* v : this->pq)
		{
			if (d[v] < d[min]) {
				min = v;
				min_index = counter;
			}
			counter += 1;
		}

		this->pq.erase(pq.begin() + min_index);

		return min;
	}


};
