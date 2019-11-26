#include "FileCooker.h"
#include "Calculator.h"
#include "Converter.h"
#include "pch.h"

vector <Task*> readFile(string fileName) {
	ifstream reader;
	reader.open(fileName, ios::in);

	if (!reader.is_open())
		return {};

	vector <Task*> list;
	string s;
	//int p = 0;
	while (!reader.eof()) {
		getline(reader, s, '\n');
		if (s == "")
			break;
		//cout << ++p << endl;

		Task* p = nullptr;
		try {
			p = readLine(s);
		}
		catch (string k) {
			cout << k << endl;
			system("pause>nul");
			exit(0);
		}
			
		list.push_back(p);
	}
	reader.close();

	return list;
}

Task*readLine(string lineInfo) {
	vector<string> tokens = Tokenizer::Parse(lineInfo, " ");
	Task* res = nullptr;
	
	if (tokens.size() == 3) {
		res = new Converter;
		res->setBase(tokens[0]);
		res->setOperator(tokens[1]);
		res->setNum1(tokens[2]);
	}
	else if (tokens.size() == 4) {
		res = new Calculator;
		res->setBase(tokens[0]);
		res->setNum1(tokens[1]);
		res->setOperator(tokens[2]);
		res->setNum2(tokens[3]);
	}
	else 
		throw "Error: Invalid file input";
	

	return res;
}

//----------------------------
void outputFile(vector <string> output, string outputName) {
	if (output.empty())
		throw "Error: empty output";

	ofstream printer;
	printer.open(outputName);

	if (!printer.is_open())
		throw "Error: can not open file";
	for (auto i = 0; i < output.size(); ++i) {
		printer << output[i] << '\n';
	}

	printer.close();
}