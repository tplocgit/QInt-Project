#include "pch.h"
#include "FileCooker.h"


FileCooker::FileCooker()
{
}


FileCooker::~FileCooker()
{
}

void readFile(string fileName) {
	ifstream reader;
	reader.open(fileName, ios::in);

	if (!reader.is_open())
		return;

	//--------



	reader.close();
}
