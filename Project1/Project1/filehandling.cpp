#include "filehandling.h"
#include<chrono>

std::atomic<bool> stopThread = false;

FileHandling::FileHandling(CircularQueue* queue) {
	cqueue = queue;
}

FileHandling::~FileHandling() {
	stopFileWriter();
}
void FileHandling::startFileWriter() {
	fileWriterThread = std::thread(&FileHandling::fileWriterThreadFunc,this);
}

void FileHandling::stopFileWriter() {
	stopThread = true;
	if (fileWriterThread.joinable()) {
		fileWriterThread.join();
	}
}

//Writing the file using the thread.
void FileHandling::fileWriterThreadFunc() {
	int newIndex = 0;
	std::ofstream file(filePath, std::ios::app);
	while (!stopThread) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		auto newData = cqueue->getNewData(newIndex);
		for (auto data : newData) {
			file << encryption.encrypt(data) << std::endl;
		}
	}
	file.close();
}

//Writing the file in the usual way.
void FileHandling::fileWrite(std::string& data) {
	std::ofstream file(filePath, std::ios::app);
	file << encryption.encrypt(data) << std::endl;
	file.close();
}
void FileHandling::fileRead() {
	std::ifstream file(filePath);
	std::string fileLines;
		while (getline(file, fileLines)) {
		std::cout << encryption.decrypt(fileLines) << std::endl;
	}
	file.close();
}
void FileHandling::fileErase() {
	std::ofstream file(filePath, std::ios::trunc);
	file.close();
}
void FileHandling::displayFromFile() {
	std::cout << "Displaying from file" << std::endl;
	fileRead();
}