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

string Calculator::Exe() {
	QInt* res = new QInt;
	QInt num1(this->Base(), this->Num1());

	if (this->calOperator == ADD) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 + num2;
	}
	else if (this->calOperator == MINUS) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 - num2;
	}
	else if (this->calOperator == MULTIPLY) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 * num2;
	}
	else if (this->calOperator == DIVIDE) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 / num2;
	}
	else if (this->calOperator == OR) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 | num2;
	}
	else if (this->calOperator == XOR) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 ^ num2;
	}
	else if (this->calOperator == AND) {
		QInt num2(this->Base(), this->Num2());
		*res = num1 & num2;
	}

	else if (this->calOperator == MOVE_LEFT) {
		*res = num1 << stoi(this->Num2());
	}
	else if (this->calOperator == MOVE_RIGHT) {
		*res = num1 >> stoi(this->Num2());
	}
	else
		throw "Error: Operator is not defined!";
	//cout << res->Bin() << endl;
	//delete num1;
	//return res;
	string ans;
	if (this->Base() == BINARY)
		ans = res->Bin();
	else if (this->Base() == HEXADECIMAL)
		ans = res->Hex();
	else if (this->Base() == DECIMAL)
		ans = res->Dec();
	else
		throw "Error: wrong base input";

	delete res;
	
	return QInt::DeleteAllZeroAtHead(ans);
}

void Calculator::ShowAllInfor() {
	Task::ShowAllInfor();
	cout << "DO ";
	if (this->calOperator == AND)
		cout << "AND";
	else if (this->calOperator == OR)
		cout << "OR";
	else if (this->calOperator == XOR)
		cout << "XOR";
	else if (this->calOperator == ADD)
		cout << "ADD";
	else if (this->calOperator == MINUS)
		cout << "MINUS";
	else if (this->calOperator == MULTIPLY)
		cout << "MULTIPLY";
	else if (this->calOperator == DIVIDE)
		cout << "DIVIDE";
	else if (this->calOperator == MOVE_LEFT)
		cout << "SHIFT LEFT";
	else if (this->calOperator == MOVE_RIGHT)
		cout << "SHIFT RIGHT";
	else cout << "NONE";
	cout << endl;
}

Task* Calculator::Alloc() {
	Task* res = new Calculator;
	*res = *this;
	return res;
}