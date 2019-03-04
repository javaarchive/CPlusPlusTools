#include <vector>
#pragma once
template <class T>
class Stack
{
	std::vector<T> storage;
public:
	Stack<T>() {

	}

	void push(T item);
};

