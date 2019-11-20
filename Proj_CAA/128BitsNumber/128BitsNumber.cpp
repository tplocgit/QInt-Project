// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main()
{
	vector<Task*> list = readFile("sampleInput.txt");

	TodoList doList(list);
	cout << "Plz Check data input";
	doList.checkList();

	vector<QInt*> resList = doList.doTask();

	cout << "List of result: \n";
	for (auto it = resList.begin(); it != resList.end(); ++it) {
		cout <<"Binary: "<< (*it)->Bin()<<endl;
		cout << "Hexadecimal: " << (*it)->Hex() << endl;
		cout << "Decimal: " << (*it)->Dec() << endl;
	}
	for (auto it = resList.begin(); it != resList.end(); ++it)
		delete* it;

	resList.clear();

	system("pause>nul");
	return 0;
}
