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

	Problem *readLine(string lineInfo);
};

