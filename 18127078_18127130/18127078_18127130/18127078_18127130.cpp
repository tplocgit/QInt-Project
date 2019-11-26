// 18127078_18127130.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main(/*int argc, char* argv[]*/)
{
	/*if (argc != 3) {
		cout << "Error: Invalid Argument count!!!!!!!!!!";
		return -1;
	}*/
	vector<Task*> list;
	try {
		list = readFile("data\\input.txt");
	}
	catch (string s) {
		cout << s << endl;
		system("pause>nul");
		return -2;
	}
	cout << "Processing file...\n";
	TodoList doList(list);

	vector<string> resList = doList.doTask();


	try {
		outputFile(resList, "output_sv\\18127078_18127130_output.txt");
	}
	catch (string s) {
		cout << s << endl;
		system("pause>nul");
		return -3;
	}


	cout << "===> All tasks completed!!!\n";
	
	system("pause");
	return 0;
}
