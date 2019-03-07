#include <vector>
#pragma once
template <class T>
class Stack
{
	std::vector<T> storage;
public:
	Stack<T>() {
		
	}
	bool empty() { return storage.empty; }
	void push(T item);
	T pop();
	int length();
	~Stack()
	{
		
	}
};

template <class T>
void Stack<T>::push(T item) {
	storage.insert(storage.begin(), item);
}
template <class T>
T Stack<T>::pop() {
	T temp = storage.at(0);
	storage.erase(storage.begin());
	return temp;
}
template <class T>
int Stack<T>::length() {
	return storage.size();
}