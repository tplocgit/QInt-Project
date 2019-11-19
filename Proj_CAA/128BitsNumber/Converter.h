#pragma once
#include"pch.h"
#include "Task.h"
#include"QInt.h"

class Converter : public Task {
private:
	CASE1 convertOperator;
public:
	Task* Alloc();
	void ShowAllInfor();
	QInt* Exe();
	Converter();
	Converter(string num);
	void setOperator(string input);
};

