#pragma once
#include <iostream>
#include <queue>
#include <mutex>
template<typename T>
class SafeQueue{
public:
	void pop() {
		lock();
		_safeQueue.pop();
	}
	void push(const T& other) {
		lock();
		_safeQueue.push(other);
	}
	bool empty() {
		lock();
		return _safeQueue.empty();
	}
	const T& front() {
		lock();
		return _safeQueue.front();
	}
private:
	inline void lock() {
		std::lock_guard<std::mutex> lock(_mutex);
	}
	std::mutex _mutex;
	std::queue<T> _safeQueue;
};
