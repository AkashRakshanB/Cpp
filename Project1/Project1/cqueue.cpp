#include "cqueue.h"
#include<iostream>


void CircularQueue::insertData(const std::string& value) {
	std::lock_guard < std::mutex> lock(queueMutex);
	std::string data = value;
	if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
		rear = front;
		if (front == size- 1) {
			front = 0;
		}
		else {
			front += 1;
		}
		array[rear] = data;

		return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else {
		rear += 1;
	}
	array[rear] = data;
}
void CircularQueue::displayHistory() {
	std::lock_guard < std::mutex> lock(queueMutex);
	int f = front, r = rear;
	if (front == -1) {
		std::cout << "There is no history" << std::endl;
		return;
	}
	std::cout << "History" << std::endl;
	if (f <= r) {
		while (f <= r) {
			std::cout << array[f] << std::endl;
			f++;
		}
	}
	else {
		while (f <= size - 1) {
			std::cout << array[f] << std::endl;
			f++;
		}
		f = 0;
		while (f <= r) {
			std::cout << array[f] << std::endl;
			f++;
		}
	}
}
std::vector<std::string> CircularQueue::getNewData(int& newIndex) {
	std::lock_guard<std::mutex> lock(queueMutex);
	std::vector < std::string> result;
	int i = newIndex;
	if (front == -1 || i == rear + 1) {
		return result;
	}
	while (i != (rear + 1) % size) {
		result.push_back(array[i]);
		i = (i + 1) % size;
	}
	newIndex = rear+1;
	return result;
}