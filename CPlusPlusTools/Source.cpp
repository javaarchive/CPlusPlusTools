// CPlusPlusTools.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <string>
#include "sha224.h"
#include "Stack.h"
#include "Queue.h"
#include <string>

int main()
{
	// CONFIG
	const bool manualPossibleChars = false; // Ask for list of characters to try
	const int LIMIT = 5; // String length limit
	//const std::string possible = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const std::string possible = "abcdefghijklmnopqrstuvwxyz";
	Queue<std::string> check;
	std::string target;
	std::cout << std::endl;
	std::cout << "Enter target hash to be cracked: " << std::endl;
	std::cin >> target;
	std::string msg = "Cracking: ";
	std::cout << msg + target;
	for (std::string::size_type i = 0; i < possible.size(); ++i) {
		std::string s(1, possible[i]);
		check.add(s);
	}
	bool done = false;
	int count = 0;
	while (!(check.empty())) {
		count++;
		std::string test = check.poll();
		std::string result = sha224(test);
		std::cout << count << ": " << test << std::endl;
		if (result == target) {
			std::cout << std::endl << "================= Crack Complete =================" << std::endl << "The password was " << test << std::endl;
			done = true;
			break;
		}
		if (!(test.length() == LIMIT)) {
			for (std::string::size_type i = 0; i < possible.size(); ++i) {
				check.add(test + possible[i]);
			}
		}
		test.clear();
		result.clear();
	}
	if (!done) {
		std::cout << "FAILED: Failed to find match" << std::endl;
	}
}