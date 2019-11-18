#pragma once
#include "pch.h"
#include "Calculator.h"
#include "Tokenizer.h"

class FileCooker{
public:
	FileCooker();
	~FileCooker();

	//-----------------
	vector <Problem*> readFile(string fileName);

private:
	Problem *readLine(string lineInfo);
};

