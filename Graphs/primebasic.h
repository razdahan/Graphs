#pragma once
#include<iostream>
#include "vertex.h"
#include "graph.h"
#include "set"
#include <algorithm>


template<class T>
graph<T>* prime_basic(graph<T> *g)
{

	std::vector<vertex<T>*> v1={g->vertices[0]};
	std::vector<vertex<T>*> v2=g->vertices;
	v2.erase(remove_if(begin(v2), end(v2),
		[&](auto x) {return find(begin(v1), end(v1), x) != end(v1); }), end(v2));
	
	std::vector<edge<T>*> e1;
	auto index = 1;
	char end;
	do
	{
		auto e12 = get_cross_group(g, v1,v2);
		edge<T>* e_min = min_edge(e12);
		
		/*remove by value because the value represent the vertex location in the memory so its like a key*/
		if (exist(e_min->src, v1)) {
			v1.push_back(e_min->dest);
			v2.erase(std::remove(v2.begin(), v2.end(), e_min->dest), v2.end());
		}
		else
		{
			v1.push_back(e_min->src);
			v2.erase(std::remove(v2.begin(), v2.end(), e_min->src), v2.end());
		}
			
		e1.push_back(e_min);
        /*sorting so I can compare the 2 vectors without the need to worry about elements locations.*/
		std::sort(v1.begin(), v1.end());
		std::sort(g->vertices.begin(), g->vertices.end());
		
	} while (v1 != g->vertices);

	
	return new graph<T>(v1, e1);
	
}


template<class T>
std::vector<edge<T>*> get_cross_group(graph<T>* graph,std::vector<vertex<T>*> v1, std::vector<vertex<T>*> v2)
{
	std::vector<edge<T>*> result;;
	for(edge<T>* u:graph->edges)
	{
		
		if(exist(u->src,v1)&&exist(u->dest,v2)|| exist(u->src, v2) && exist(u->dest, v1))
		{
			std::cout << "pushing "<<u <<"to the cross group" << std::endl;
			result.push_back(u);
		}
	}
	return result;
}


template<class T>
bool exist(vertex<T> *v, std::vector<vertex<T>*> vertex_list)
{
	for(vertex<T> *u:vertex_list)
	{
		if (u == v) {
			return true;
		}
	}
	return false;
}

template<class T>
edge<T>* min_edge(std::vector<edge<T>*> edges)
{
	
	edge<T>* min_edge=edges.back();
	for(edge<T>* e:edges)
	{
		if(min_edge->weight>e->weight)
		{
			min_edge = e;
		}
	}
	return min_edge;
}