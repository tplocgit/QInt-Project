#pragma one
#include "pch.h"
#include "Type.h"
#include"QInt.h"

class Task {
private:
	BASE base;
	string num1, num2;
public:
	//virtual void ExeE() = 0;
	virtual void setOperator(string input) = 0;
	void setNum1(string input);
	void setNum2(string input);
	void setBase(string input);
	//--------------------------------------
	Task();
	Task(string num1, string num2);
	//--------------------------------------
	BASE Base();
	string Num1();
	string Num2();
	int checkData();
	void viewBase();
	void viewNum1();
	void viewNum2();
};
