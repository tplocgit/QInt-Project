#pragma once
#include "Task.h"

class Converter : public Task {
private:
	CASE1 convertOperator;
public:
	Converter();
	Converter(string num);
	void setOperator(string input);
};

