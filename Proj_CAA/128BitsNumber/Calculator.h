#pragma once
#include"pch.h"
#include "Task.h"
#include"QInt.h"

class Calculator : public Task{
private:
	CASE2 calOperator;
public:
	void ExeE();
	Calculator();
	Calculator(string num1, string num2);
	void setOperator(string input);
};

