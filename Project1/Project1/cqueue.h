#ifndef CQUEUE_H
#define CQUEUE_H
#include<iostream>
#include<string>
#include<mutex>
#include<vector>

class CircularQueue {
private:
	
	int front = -1;
	int rear = -1;
	int size = 10;
	std::string array[10];
	std::mutex queueMutex;
public:
	void insertData(const std::string& data);
	void displayHistory();
	std::vector<std::string> getNewData(int& newIndex);
};
#endif