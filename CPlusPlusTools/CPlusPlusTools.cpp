// CPlusPlusTools.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <string>
#include "Point.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main()
{
	cout << "Welcome to the C++ Tools demo" << endl << "Press Enter to Start the Demo " << endl << endl;
	string temp;
	getline(cin, temp);
	cout << endl << endl << "- Stacks -" << endl;
	Stack<int> demo_stack;
	demo_stack.push(3);
	demo_stack.push(2);
	demo_stack.push(1);
	demo_stack.push(4);
	cout << "Created stack with {3,2,1,4}" << endl;
	cout << "Poping of the stack...got " << demo_stack.pop() << endl;
	cout << "Poping of the stack...got " << demo_stack.pop() << endl;
	cout << "Poping of the stack...got " << demo_stack.pop() << endl;
	cout << "Poping of the stack...got " << demo_stack.pop() << endl;
	cout << endl << endl << "- Queues -" << endl;
	cout << "Created stack with {2,0,1,9}" << endl;
	Queue<int> demo_queue;
	demo_queue.add(2);
	demo_queue.add(0);
	demo_queue.add(1);
	demo_queue.add(9);
	cout << "Dequeueing.. got " << demo_queue.poll() << endl;
	cout << "Dequeueing.. got " << demo_queue.poll() << endl;
	cout << "Dequeueing.. got " << demo_queue.poll() << endl;
	cout << "Dequeueing.. got " << demo_queue.poll() << endl;
	cout << "-- Demo Finished --" << endl << "press enter to exit";
	getline(cin, temp);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
