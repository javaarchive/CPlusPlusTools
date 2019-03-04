#include "pch.h"
#include <vector>
#include <iostream>
#include "Stack.h"



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