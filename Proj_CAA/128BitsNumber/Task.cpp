#include "Task.h"
#include "pch.h"

Task::Task() {
	this->base = NONE;
	this->num1 = this->num2 = "";
}
Task::Task(string num1, string num2) {
	this->base = NONE;
	this->num1 = num1;
	this->num2 = num2;
}
void Task::setBase(string input) {
	if (input == "16")
		this->base = HEXADECIMAL;
	else if (input == "10")
		this->base = DECIMAL;
	else if (input == "2")
		this->base = BINARY;
	else
		throw "Invalid input";
}
int Task::checkData() {
	if (this->base == NONE)
		return -1;//somethings went wrong 
	if (this->num1 != "" && this->num2 == "")
		return 1;//convert mode
	if (this->num1 != "" && this->num2 != "")
		return 2;//calculate mode
}

void Task::setNum1(string input) {
	this->num1 = input;
}
void Task::setNum2(string input) {
	this->num2 = input;
}

//--------------------------------------------------------------------------

void Task::viewBase() {
	if (this->base == NONE)
		cout << "<undefined>";
	else if (this->base == BINARY)
		cout << "BINARY";
	else if (this->base == DECIMAL)
		cout << "DECIMAL";
	else if (this->base == HEXADECIMAL)
		cout << "HEXADECIMAL";
}
void Task::viewNum1() {
	if (this->num1 == "")
		cout << "<undefined>";
	else cout << this->num1;
}
void Task::viewNum2() {
	if (this->num2 == "")
		cout << "<undefined>";
	else cout << this->num2;
}





