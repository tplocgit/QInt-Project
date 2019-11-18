#include "FileCooker.h"


FileCooker::FileCooker()
{
}


FileCooker::~FileCooker()
{
}

vector <Problem*> FileCooker::readFile(string fileName) {
	ifstream reader;
	reader.open(fileName, ios::in);

	if (!reader.is_open())
		return;

	vector <Problem*> list;
	string s;
	while (!reader.eof()) {
		getline(reader, s);
		if (s == "")
			break;
		Problem *p = readLine(s);
		list.push_back(p);
		//delete p;
	}
	reader.close();
}

Problem *FileCooker::readLine(string lineInfo) {
	vector<string> tokens = Tokenizer::Parse(lineInfo, " ");
	
	Problem* res = nullptr;
	if (tokens.size() == 3) {
		res = new Convert;
		res->setBase(tokens[0]);
		res->setOperator(tokens[1]);
		res->setNum(tokens[2]);
	}
	else if (tokens.size() == 4) {
		res = new Calculate;
		res->setBase(tokens[0]);
		res->setNum1(tokens[1]);
		res->setOperator(tokens[2]);
		res->setNum2(tokens[3]);
	}
	else {
		throw "Error: Invalid input";
	}

	return res;
}
