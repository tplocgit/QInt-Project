// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
int main()
{
	vector<Task*> list = readFile("sampleInput.txt");

	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << "Type: " << (*i)->checkData() << endl << endl;
	}

	for (int i = 0; i < list.size(); ++i)
		delete list[i];
	list.clear();
	system("pause>nul");
}
