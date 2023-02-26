#include <iostream>
#include <thread>
#include "SafeQueue.h"
int main() {
	setlocale(LC_ALL, "Russian");
	SafeQueue<int> _myQueue;
	_myQueue.push(1);
	_myQueue.push(2);
	std::thread t1 = std::thread([&_myQueue]() {
		std::cout << _myQueue.front()<<'\n';
		_myQueue.push(11);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		_myQueue.push(12);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		_myQueue.push(13);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		});
	std::thread t2 = std::thread([&_myQueue]() {
		std::cout << _myQueue.front() << '\n';
		_myQueue.push(21);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		_myQueue.push(22);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		_myQueue.push(23);
		_myQueue.pop();
		std::cout << _myQueue.front() << '\n';
		});
	t1.join();
	t2.join();
	return 0;
}