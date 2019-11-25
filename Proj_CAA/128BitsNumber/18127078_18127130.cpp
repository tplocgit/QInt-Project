// 18127078_18127130.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		outputFile(resList, "output_sv\\18127078_18127130_output.txt");
	}
	catch (string s) {
		cout << s << endl;
		system("pause>nul");
		exit(0);
	}


	cout << "===> All tasks completed!!!";
	/*
	string a, b;
	cin >> a >> b;
	QInt p1(DECIMAL, a), p2(DECIMAL, b),
		ans = p1 / p2;

	cout << ans.Bin();
	*/
	system("pause>nul");
	return 0;
}
