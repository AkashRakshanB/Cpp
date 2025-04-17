#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include<cmath>
#include "cqueue.h"
class Calculator {
private:
	CircularQueue* circularQueue;

public:
	double add(double num1, double num2);
	double sub(double num1, double num2);
	double multi(double num1, double num2);
	double div(double num1, double num2);
	int rem(int num1, int num2);
	double squareRoot(double num);
	void displayHistory();

	Calculator(CircularQueue* queue);
};

#endif // !CALCULATOR_H
