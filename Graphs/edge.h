#pragma once
#include "vertex.h"

template <class T>
class edge
{
public:
	vertex<T>* src;
	vertex<T>* dest;
	T weight = 1;
	edge(vertex<T>* src, vertex<T>* dest, T weight)
	{
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}
	edge(vertex<T>* src, vertex<T>* dest)
	{
		this->src = src;
		this->dest = dest;

	}
};
