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

	vector<string> resList = doList.doTask();
	
	
	try {
		outputFile(resList, "output.txt");
	}
	catch (string s) {
		cout << s << endl;
		system("pause>nul");
		exit(0);
	}
	
	for (auto it = list.begin(); it != list.end(); ++it)
		delete* it;
	list.clear();

	cout << "finished";
	system("pause>nul");
	return 0;
}
