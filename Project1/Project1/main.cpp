#include <iostream>
#include<thread>
#include<chrono>
#include<string>
#include "calculator.h"
#include "cqueue.h"
#include "filehandling.h"

int main() {
	
	CircularQueue sharedQueue;
	FileHandling fileHandling(&sharedQueue);
	Calculator calculator(&sharedQueue);

	std::thread fileWriterThread(&FileHandling::fileWriterThreadFunc, &fileHandling);
	bool value = true;
	while (value) {
		
		bool session = true;
		std::cout << "Enter the number you want to calculate:";
		double n1;
		double n2;
		std::cin >> n1;
		
		while (session) {

			int choice;
			std::cout << "\nNow Choose the operation\n";
			std::cout << "To choose Addition enter: 1\n";
			std::cout << "To choose Subraction enter: 2\n";
			std::cout << "To choose Multiplication enter: 3\n";
			std::cout << "To choose Division enter: 4\n";
			std::cout << "To choose Reminder enter: 5\n";
			std::cout << "To get Square Root enter: 6\n";
			std::cout << "To Display History enter: 7\n";
			std::cout << "To Clear the current calculations enter: 8\n";
			std::cout << "To Exit the App enter: 9\n";

			std::cin >> choice;

			switch (choice) {
			case 1:
				std::cout << "Enter the Other number\n";
				std::cin >> n2;
				n1 = calculator.add(n1, n2);

				std::cout << n1;
				break;

			case 2:
				std::cout << "Enter the other number\n";
				std::cin >> n2;
				n1 = calculator.sub(n1, n2);

				std::cout << n1;
				break;

			case 3:
				std::cout << "Enter the other number\n";
				std::cin >> n2;
				n1 = calculator.multi(n1, n2);

				std::cout << n1;
				break;

			case 4:
				std::cout << "Enter the other number\n";
				std::cin >> n2;
				n1 = calculator.div(n1, n2);

				std::cout << n1;
				break;

			case 5:
				std::cout << "Enter the other number\n";
				std::cin >> n2;
				n1 = calculator.rem(n1, n2);

				std::cout << n1;
				break;

			case 6:
				n1 = calculator.squareRoot(n1);
				std::cout << n1;
				break;
			case 7:
				sharedQueue.displayHistory();
				
				break;

			case 8:
				session = false;
				break;
			case 9:
				session = false;
				value = false;
				fileHandling.fileErase();
				break;

			default:
				std::cout << "Enter a valid key";
			}
		}
	}
	stopThread = true;
	fileWriterThread.join();

	return 0;
}