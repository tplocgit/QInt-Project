// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main()
{
	/*vector<Task*> list = readFile("sampleInput.txt");

	TodoList doList(list);
	//cout << "Plz Check data input";
	//doList.checkList();

	vector<QInt*> resList = doList.doTask();

	//cout << "List of result: \n";
	uint16_t count = 0;
	for (auto it = resList.begin(); it != resList.end(); ++it) {
		cout << "\n\nTask " << ++count << endl;
		(list[count - 1])->ShowAllInfor();
		cout << "=>>Result: \n";
		cout << "Binary: " << QInt::DeleteAllZeroAtHead((*it)->Bin()) << endl;
		cout << "Hexadecimal: " << QInt::DeleteAllZeroAtHead((*it)->Hex()) << endl;
		cout << "Decimal: " << QInt::DeleteAllZeroAtHead((*it)->Dec()) << endl;
	}
	for (auto it = resList.begin(); it != resList.end(); ++it)
		delete* it;

	resList.clear();
	*/
	string bits;
	cin >> bits;
	QInt a(bits);
	for (int i = 0; i <= 120; ++i)
		a.setBit(i, 1);
	cout << QInt::DeleteAllZeroAtHead(a.Dec()) << endl;
	system("pause>nul");
	return 0;
}
