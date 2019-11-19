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

void Converter::ExeE() {
	QInt* res = new QInt;
	QInt* num1 = new QInt(this->Base(), this->Num1());


	if (this->convertOperator == CON_DEC)
		*res = num1->Dec();
	else if (this->convertOperator == CON_HEX)
		*res = num1->Hex();
	else if (this->convertOperator == CON_BIN)
		*res = num1->Bin();
	else if (this->convertOperator == ROL)
		*res = num1->ROL();
	else if (this->convertOperator == ROR)
		*res = num1->ROR();
	else if (this->convertOperator == NOT)
		*res = ~(*num1);
	else
		throw "Error: Deo hieu luon a";
	delete num1;
	delete res;
	cout << res->Bin() << endl << res->Hex() << endl << res->Dec() << endl;
}