#pragma once
#include"pch.h"
#include "Task.h"
#include"QInt.h"

class Converter : public Task {
private:
	CASE1 convertOperator;
public:
	void ExeE();
	Converter();
	Converter(string num);
	void setOperator(string input);
};

