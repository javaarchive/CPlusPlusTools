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
	T pop();
	int length();
	~Stack()
	{
		
	}
};

template <class T>
void Stack<T>::push(T item) {
	storage.insert(0, storage.begin, item);
}
template <class T>
T Stack<T>::pop() {
	T temp = storage.at(0);
	storage.erase(0);
	return temp;
}
template <class T>
int Stack<T>::length() {
	return storage.size();
}