#include "pch.h"
#include <vector>
#include <iostream>
#include "Queue.h"



template <class T>
void Queue<T>::push(T item) {
	storage.push_back(item);
}
template <class T>
T Queue<T>::pop() {
	T temp = storage.at(0);
	storage.erase(0);
	return temp;
}
template <class T>
int Queue<T>::length() {
	return storage.size();
}