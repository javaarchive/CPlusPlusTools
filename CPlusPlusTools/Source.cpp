// CPlusPlusTools.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <string>
#include "sha224.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <thread>
#include <mutex>
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
std::mutex clock;
std::mutex lock;
void bird() {
	for (int i = 0; i < 5; i++) {
		std::cout << "Birdy Test" << std::endl;
	}
}
void consumer(Queue<std::string> *check, int *count, std::string target, bool *done,int LIMIT,std::string possible) {
	while (!((*check).empty()) && !(*done)) {
		(*count)++;
		while (*lock == true) {
			sleep_for(200ms);
			std::cout << "Waiting for the lock";
		}
		*lock = true;
		std::string test = (*check).poll();
		if (test == "azz" || (*count) == 1352) {
			std::cout << "-/-";
		}
		*lock = false;
		std::string result = sha224(test);
		std::cout <<std::endl << (*count) << ": " << test;
		if (result == target) {
			int count = 0;
			while (*clock == true) {
				count++;
				sleep_for(200ms);
				std::cout << std::endl << ("Waiting for the lock to submit answer T: "+std::to_string(count));
			}
			
			*clock = true;
			*done = true;
			sleep_for(2ms);
			std::cout << std::endl << "================= Crack Complete =================" << "\n" << "The password was " << test << std::endl << std::endl;
			sleep_for(5s);
			*clock = false;
			break;
		}
		
		if (!(test.length() == LIMIT)) {
			for (std::string::size_type i = 0; i < possible.size(); ++i) {
				int count = 0;
				while (*lock == true) {
					count++;
					sleep_for(200ms);
					std::cout << ("Waiting for the lock T:"+count) << std::endl;
				}
				*lock = true;
				(*check).add(test + possible[i]);
				*lock = false;
			}
		}
		test.clear();
		result.clear();
	}
	if (!done) {
		//std::cout << "FAILED: Failed to find match" << std::endl;
	}
}
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
	std::cout << std::endl << std::endl << "Enter target hash to be cracked: " << std::endl;
	std::cin >> target;
	std::string msg = "Cracking: ";
	std::cout << msg + target;
	for (std::string::size_type i = 0; i < possible.size(); ++i) {
		std::string s(1, possible[i]);
		check.add(s);
	}
	bool done = false;
	int count = 0;
	std::vector<std::thread> pool;
	int CORES = 4;
	//bool lock = false;
	//bool clock = false;
	
	for (int i = 0; i < CORES; i ++) {
	pool.push_back(std::thread (*consumer, &check, &count, target, &done, LIMIT, possible));
}
	for (int i = 0; i < CORES; i++) {
		pool[i].join();
		std::cout << "+++++++++++++++++++++ Terminated ++++++++++++++++++++";
	}
	
}
