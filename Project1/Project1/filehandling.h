#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include<iostream>
#include<fstream>
#include<string>
#include "encryption.h"
#include "cqueue.h"
#include<thread>
#include<atomic>

extern std::atomic<bool> stopThread;

class FileHandling {
private:
	std::string filePath="C:/Users/Administrator/Desktop/file.txt";
	Encryption encryption;
	CircularQueue* cqueue;
	std::thread fileWriterThread;
	
public:
	void fileWrite( std::string& data);
	void fileRead();
	void fileErase();
	void displayFromFile();


	FileHandling(CircularQueue* q);
	~FileHandling();
	void startFileWriter();
	void stopFileWriter();
	void fileWriterThreadFunc();
};
#endif