#pragma once
#include <iostream>


template <class T>
class vertex
{
public:
	T id;
	vertex(T id)
	{
		this->id = id;

	}

	bool cmp(T id)
	{
		return id == this->id;
	}
	vertex() {}
};

