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

void Calculator::ExeE() {
	QInt* res = new QInt;
	QInt* num1, * num2;
	num1 = new QInt(this->Base(), this->Num1());

	if (this->calOperator == ADD) {
		num2 = new QInt(this->Base(), this->Num2());
		*res = *num1 + *num2;
		delete num2;
	}
	else if (this->calOperator == MINUS) {
		num2 = new QInt(this->Base(), this->Num2());
		*res = *num1 - *num2;
		delete num2;
	}
	else if (this->calOperator == MOVE_LEFT) {
		*res = *num1 << stoi(this->Num2());
	}
	else if (this->calOperator == MOVE_RIGHT) {
		*res = *num2 >> stoi(this->Num2());
	}
	else
		throw "Error: Operator is not defined!";

	cout << res->Bin() << endl << res->Hex() << endl << res->Dec() << endl;
	delete num1;
	delete res;
}