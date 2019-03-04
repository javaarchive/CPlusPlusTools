#include <vector>
#pragma once
template <class T>
class Queue
{
	std::vector<T> storage;
public:
	Queue<T>() {

	}

	void push(T item);
	T pop();
	int length();
	~Queue()
	{
		delete storage;
	}
};

