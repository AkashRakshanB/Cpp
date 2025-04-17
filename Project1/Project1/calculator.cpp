#include "calculator.h"

Calculator::Calculator(CircularQueue* queue) {
	circularQueue = queue;
}

	double Calculator::add(double num1, double num2) {
		circularQueue->insertData(std::to_string(num1) + "\+" + std::to_string(num2) + '=' + std::to_string(num1 + num2));
		return num1 + num2;
	}
	double Calculator::sub(double num1, double num2) {
		circularQueue->insertData(std::to_string(num1) + "-" + std::to_string(num2) + '=' + std::to_string(std::abs(num1 - num2)));
		return std::abs(num1 - num2);
	}
	double Calculator::multi(double num1, double num2) {
		circularQueue->insertData(std::to_string(num1) + "*" + std::to_string(num2) + '=' + std::to_string(num1 * num2));
		return num1 * num2;
	}
	double Calculator::div(double num1, double num2) {
		circularQueue->insertData(std::to_string(num1) + "/" + std::to_string(num2) + '=' + std::to_string(num1 / num2));
		return num1 / num2;
	}
	int Calculator::rem(int num1, int num2) {
		circularQueue->insertData(std::to_string(num1) + "%" + std::to_string(num2) + '=' + std::to_string(num1 % num2));
		return num1 % num2;
	}
	double Calculator::squareRoot(double num) {
		circularQueue->insertData(std::to_string(num) + "Square root =" + std::to_string(std::sqrt(num)));
		return std::sqrt(num);
	}
	void Calculator::displayHistory() {
		circularQueue->displayHistory();
	 }
