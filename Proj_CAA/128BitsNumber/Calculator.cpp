#include "pch.h"
#include "Calculator.h"

Calculator::Calculator() : Task() {
	this->calOperator = NONE2;
}
Calculator::Calculator(string num1, string num2) : Task(num1, num2) {
	this->calOperator = NONE2;
}
void Calculator::setOperator(string input) {
	if (input == "+")
		this->calOperator = ADD;
	else if (input == "-")
		this->calOperator = MINUS;
	else if (input == "*")
		this->calOperator = MULTIPLY;
	else if (input == "/")
		this->calOperator = DIVIDE;
	else if (input == "&")
		this->calOperator = AND;
	else if (input == "|")
		this->calOperator = OR;
	else if (input == "^")
		this->calOperator = XOR;
	else if (input == ">>")
		this->calOperator = MOVE_RIGHT;
	else if (input == "<<")
		this->calOperator = MOVE_LEFT;
	else
		throw "Invalid input";
}
