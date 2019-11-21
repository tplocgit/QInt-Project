#include "pch.h"
#include "Converter.h"

//---------------------------------------------------------------------------
Converter::Converter() : Task() {
	this->convertOperator = NONE1;
}
Converter::Converter(string num) : Task(num, "") {
	this->convertOperator = NONE1;
}
void Converter::setOperator(string input) {
	if (input == "2")
		this->convertOperator = CON_BIN;
	else if (input == "10")
		this->convertOperator = CON_DEC;
	else if (input == "16")
		this->convertOperator = CON_HEX;
	else if (input == "~")
		this->convertOperator = NOT;
	else if (input == "ror")
		this->convertOperator = ROR;
	else if (input == "rol")
		this->convertOperator = ROL;
	else
		throw "Invalid input";
}

QInt* Converter::Exe() {
	QInt* res;
	QInt* num1 = new QInt(this->Base(), this->Num1());


	if (this->convertOperator == CON_DEC)
		res = new QInt(*num1);
	else if (this->convertOperator == CON_HEX)
		res = new QInt(*num1);
	else if (this->convertOperator == CON_BIN)
		res = new QInt(*num1);
	else if (this->convertOperator == ROL)
		res = new QInt(num1->ROL());
	else if (this->convertOperator == ROR)
		res = new QInt(num1->ROR());
	else if (this->convertOperator == NOT)
		res = new QInt(~(*num1));
	else
		throw "Error: Deo hieu luon a. T nhin ma t tuc a";
	delete num1;
	return res;
	//cout << res->Bin() << endl << res->Hex() << endl << res->Dec() << endl;
}

void Converter::ShowAllInfor() {
	Task::ShowAllInfor();
	cout << "DO ";
	if (this->convertOperator == ROL)
		cout << "ROL";
	else if (this->convertOperator == ROR)
		cout << "ROR";
	else if (this->convertOperator == CON_BIN)
		cout << "To Binary";
	else if (this->convertOperator == CON_DEC)
		cout << "To Decimal";
	else if (this->convertOperator == CON_HEX)
		cout << "To Hexadecimal";
	else if (this->convertOperator == NOT)
		cout << "NOT";
	else cout << "NONE";
	cout << endl;
}


Task* Converter::Alloc() {
	Task* res = new Converter;
	*res = *this;
	return res;
}