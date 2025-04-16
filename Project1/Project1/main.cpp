#include <iostream>
#include <cmath>
#include<string>
#include<fstream>
class Calculator {
public:
	std::string arr[10];
	int front = -1;
	int rear = -1;
	int n = 10;
	
	void encrypt(std::string data){
		int key = 6;
		
		for (int i = 0;data[i]!='\0'; i++) {
			data[i] += key;
		}
		fileWrite(data);
	}
	std::string decrypt(std::string data) {
		int key = 6;
		for (int i = 0; data[i] != '\0'; i++) {
			data[i] -= key;
		}
		return data;
	}
	void fileWrite(std::string value) {
		std::ofstream file("C:/Users/Administrator/Desktop/file.txt",std::ios::app);
		
		file << value  << std::endl;
		file.close();
	}
	void fileRead() {
		std::ifstream file("C:/Users/Administrator/Desktop/file.txt");
		std::string fileLines;
		//int lineCount = 0;
		while (getline(file, fileLines)) {
			std::cout << decrypt(fileLines) << std::endl;
			/*lineCount++;

			if (lineCount >= 5) {
				std::cout << "More Items" << std::endl;
				std::string input;
				getline(std::cin, input);
				if (input == "q" || input == "Q") {
					break;
				}
			}*/
		}
		file.close();
	}
	void eraseData() {
		std::ofstream file("C:/Users/Administrator/Desktop/file.txt", std::ios::trunc);
		file.close();
	}
	void displayFromFile() {
		std::cout << "Displaying from file" << std::endl;
		fileRead();
	}
	void insert(std::string num){
		encrypt(num);
		if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
			rear = front;
			if (front == n - 1) {
				front = 0;
			}
			else {
				front += 1;
			}
			arr[rear] = num; 
			
			return;
		}
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else {
			rear += 1;
		}
		arr[rear] = num;
		
	}
	void display() {
		int f = front, r = rear;
		if (front == -1) {
			std::cout << "There is no history" << std::endl;
			return;
		}
		std::cout << "History" << std::endl;
		if (f <= r) {
			while (f <= r) {
				std::cout << arr[f] << std::endl;
				f++;
			}
		}
		else {
			while (f <= n - 1) {
				std::cout << arr[f] << std::endl;
				f++;
			}
			f = 0;
			while (f <= r) {
				std::cout << arr[f] << std::endl;
				f++;
			}
		}
	}

	int add(int num1, int num2) {
		insert(std::to_string(num1) +"\+" + std::to_string(num2) + '='+std::to_string(num1 + num2));
		return num1 + num2;
	}
	int sub(int num1, int num2) {
		insert(std::to_string(num1) + "-" + std::to_string(num2) + '=' + std::to_string( std::abs(num1 - num2)));
		return std::abs(num1 - num2);
	}
	int multi(int num1, int num2) {
		insert(std::to_string(num1) + "*" + std::to_string(num2) + '=' + std::to_string(num1 * num2));
		return num1 * num2;
	}
	int div(int num1, int num2) {
		insert(std::to_string( num1) + "/" + std::to_string(num2) + '=' + std::to_string(num1 / num2));
		return num1 / num2;
	}
	int rem(int num1, int num2) {
		insert(std::to_string( num1 )+ "%" + std::to_string(num2) + '=' + std::to_string(num1 % num2));
		return num1 % num2;
	}
	int squareRoot(double num) {
		insert(std::to_string(num) + "Square root =" + std::to_string(std::sqrt(num)));
		return std::sqrt(num);
	}
	
};


int main() {
	
	bool value = true;
	while (value) {
		Calculator calculator;
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
				//calculator.display();
				calculator.displayFromFile();
				break;

			case 8:
				session = false;
				break;

			case 9:
				session = false;
				value = false;
				calculator.eraseData();
				break;

			default:
				std::cout << "Enter a valid key";
			}
		}
	}

	return 0;
}