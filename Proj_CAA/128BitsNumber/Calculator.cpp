#include "Calculator.h"



Problem::Problem() {
		base = BASE::NONE;
}

void Problem::setBase(string input) {
	if (input == "16")
		base = HEXADECIMAL;
	else if (input == "10")
		base = DECIMAL;
	else if (input == "2")
		base = BINARY;
	else
		throw "Invalid input";
}

//---------------------------------------------------------------------------
Calculate::Calculate() : Problem() {
		num1 = num2 = "";
		calOperator = CASE2::NONE;
}
void Calculate::setNum(string input) {}
void Calculate::setNum1(string input) {
	num1 = input;
}
void Calculate::setNum2(string input) {
	num2 = input;
}
void Calculate::setOperator(string input) {
	if (input == "+")
		calOperator = ADD;
	else if (input == "-")
		calOperator = MINUS;
	else if (input == "*")
		calOperator = MULTIPLY;
	else if (input == "/")
		calOperator = DIVIDE;
	else if (input == "&")
		calOperator = AND;
	else if (input == "|")
		calOperator = OR;
	else if (input == "^")
		calOperator = XOR;
	else if (input == ">>")
		calOperator = MOVE_RIGHT;
	else if (input == "<<")
		calOperator = MOVE_LEFT;
	else
		throw "Invalid input";
}

//---------------------------------------------------------------------------
Convert::Convert() : Problem() {
	num = "";
	convertOperator = CASE1::NONE;
}
void Convert::setNum1(string input) {}
void Convert::setNum2(string input) {}
void Convert::setNum(string input) {
	num = input;
}
void Convert::setOperator(string input) {
	if (input == "2")
		convertOperator = CON_BIN;
	else if (input == "10")
		convertOperator = CON_DEC;
	else if (input == "16")
		convertOperator = CON_HEX;
	else if (input == "~")
		convertOperator = NOT;
	else if (input == "ror")
		convertOperator = ROR;
	else if (input == "rol")
		convertOperator = ROL;
	else
		throw "Invalid input";
}


