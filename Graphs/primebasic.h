#pragma once
#include<iostream>
#include "vertex.h"
#include "graph.h"
#include "set"



template<class T>
void prime_basic(graph<T> *graph)
{

	std::vector<vertex<T>*> v1={graph->vertices[0]};
	std::vector<vertex<T>*> v2=graph->vertices;
	v2.erase(remove_if(begin(v2), end(v2),
		[&](auto x) {return find(begin(v1), end(v1), x) != end(v1); }), end(v2));
	
	std::vector<edge<T>*> e1;
	auto index = 1;
	do
	{
	/*Implement the algorithm*/
		
	} while (v1 != graph->vertices);

	std::cout << std::endl;
	std::cout << graph->vertices.size() << std::endl;
	std::cout << v2.size() << std::endl;
	
}