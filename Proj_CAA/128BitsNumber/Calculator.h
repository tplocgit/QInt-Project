#pragma once
#include "pch.h"
enum BASE {
	BINARY,
	DECIMAL, 
	HEXADECIMAL,
	NONE
};

enum CASE1 {//convert
	CON_BIN,
	CON_HEX,
	CON_DEC,
	ROL,
	ROR,
	NOT,	//~
	NONE
};
enum CASE2 {//caculate
	AND,	// &
	OR,		// |
	XOR,	// ^
	//-----
	ADD,
	MINUS,
	MULTIPLY,
	DIVIDE,
	//-----
	MOVE_LEFT,	//<<
	MOVE_RIGHT,	//>>
	NONE
};

class Problem {
private:
	BASE base;

public:
	virtual void setOperator(string input) = 0;
	virtual void setNum1(string input) = 0;
	virtual void setNum2(string input) = 0;
	virtual void setNum(string input) = 0;

	Problem() {
		base = BASE::NONE;
	}
	void setBase(string input) {
		if (input == "16")
			base = HEXADECIMAL;
		else if (input == "10")
			base = DECIMAL;
		else if (input == "2")
			base = BINARY;
		else
			throw "Invalid input";
	}
};
//--------------
class Calculate : public Problem {
private:
	CASE2 calOperator;
	string num1, num2;

public:
	Calculate() : Problem() {
		num1 = num2 = "";
		calOperator = CASE2::NONE;
	}
	//----------------------	
	void setNum(string input) {}
	void setNum1(string input) {
		num1 = input;
	}
	void setNum2(string input) {
		num2 = input;
	}
	void setOperator(string input) {
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
};


class Convert : public Problem {
private:
	CASE1 convertOperator;
	string num;
public:
	Convert() : Problem() {
		num = "";
		convertOperator = CASE1::NONE;
	}

	void setNum1(string input) {
	}
	void setNum2(string input) {
	}
	void setNum(string input) {
		num = input;
	}
	void setOperator(string input) {
		if (input == "2")
			convertOperator = CON_BIN;
		else if(input == "10")
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
};

