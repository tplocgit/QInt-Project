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
