#pragma once
#include "Task.h"
class Calculator : public Task
{
private:
	CASE2 calOperator;

public:
	Calculator();
	Calculator(string num1, string num2);
	void setOperator(string input);
};

