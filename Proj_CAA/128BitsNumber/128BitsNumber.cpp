// 128BitsNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "QInt.h"
#include "FileCooker.h"
#include "Calculator.h"
#include"TodoList.h"

int main()
{
<<<<<<< HEAD
	/*vector<Task*> list = readFile("sampleInput.txt");

=======
	
	vector<Task*> list = readFile("sampleInput.txt");
>>>>>>> master
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
<<<<<<< HEAD
	for (auto it = resList.begin(); it != resList.end(); ++it)
		delete* it;

	resList.clear();
	*/

	/*int n1, n2;
	cin >> n1 >> n2;
	*///cout << QInt::DeleteAllZeroAtHead(QInt::SubTwoStringNumber(QInt::TwoPowerToSrting(n1), QInt::TwoPowerToSrting(n2))) << endl;
	string b1, b2;
	cin >> b1;//>> b2;

	QInt a(DECIMAL,b1);
	cout << QInt::DeleteAllZeroAtHead(a.Bin()) << endl;
	cout << QInt::DeleteAllZeroAtHead(a.Dec())<<endl;
	//cout << QInt::SubTwoStringNumber(b1, b2) << endl;
=======

	cout << "finished";
>>>>>>> master
	system("pause>nul");
	return 0;
}
