#include <vector>
#pragma once
template <class T>
class Queue
{
	std::vector<T> storage;
public:
	Queue<T>() {

	}
	void enqueue(T item) { add(item); };
	void add(T item);
	T poll();
	T peek();
	T dequeue() { return poll(); }

	bool empty() { return storage.empty(); }
	int length();
	~Queue()
	{
		
	}
};

template <class T>
void Queue<T>::add(T item) {
	storage.push_back(item);
}
template <class T>
T Queue<T>::poll() {
	T temp = storage.at(0);
	storage.erase(storage.begin());
	return temp;
}
template <class T>
T Queue<T>::peek() {
	T temp = storage.at(0);
	return temp;
}
template <class T>
int Queue<T>::length() {
	return storage.size();
}