// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main()
{/*
	vector<Task*> list = readFile("data\\input.txt");

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
	*/
	//10 788323282258381939236275890776 / -27388934683056007097503944712
	BASE bs = DECIMAL;
	string s1, s2;
	cin >> s1 >> s2;

	QInt p1(bs, s1), p2(bs, s2),
		ans = p1 / p2;
	cout << ans.Dec();
	//cout << "finished";
	system("pause>nul");
	return 0;
}
