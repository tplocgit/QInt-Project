// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main()
{
	vector<Task*> list = readFile("data\\input.txt");
	cout << "Processing file...\n";
	TodoList doList(list);

	vector<string> resList = doList.doTask();
	
	
	try {
		outputFile(resList, "output_sv\\128BitsNumber_output.txt");
	}
	catch (string s) {
		cout << s << endl;
		system("pause>nul");
		exit(0);
	}
	

	cout << "===> All tasks completed!!!";
	system("pause>nul");
	return 0;
}
