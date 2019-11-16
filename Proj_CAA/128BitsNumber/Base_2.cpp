#include "pch.h"
#include "Base_2.h"

//Big Three & construct--------------------------------------------------------------------------------------------------------
Base_2 Base_2::operator=(const Base_2& num) {
	// Dellocate avaiable memory to avoid leaked
	if (this->Bits != nullptr)
		delete[] this->Bits;
	// Allocate new bits
	this->Bits = new int64_t[2];

	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];
}

Base_2::Base_2() {
	// Allocate two numbers of 64 bits to get 128 bits
	this->Bits = new int64_t[2];
	// Set 0 for 128 bit
	this->Bits[0] = 0;
	this->Bits[1] = 0;
}

Base_2::Base_2(const Base_2& num) {
	// Dellocate avaiable memory to avoid leaked
	if (this->Bits != nullptr)
		delete[] this->Bits;
	// Allocate new bits
	this->Bits = new int64_t[2];

	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];
}

Base_2::~Base_2() {
	delete[] this->Bits;
}

uint8_t powOfTwo(uint8_t n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else {
		if (n % 2 == 0)
			return powOfTwo(n / 2)*powOfTwo(n / 2);
		else
			return 2 * powOfTwo(n / 2)*powOfTwo(n / 2);
	}
}
// Support method-------------------------------------------------------------------------------------------------------------
void Base_2::setBit(uint8_t index, bool bitVal) {// Set value for bit of index 
	if (0 <= int(index) && int(index) <= 63)// The first element - Bits[0] contains bits from 0 -> 63
		this->Bits[0] = this->Bits[0] | (bitVal << index);
	else if (64 <= int(index) && int(index) <= 127)// The last element - Bist[1] contains bits from 64 -> 127 
		this->Bits[1] = this->Bits[1] | (bitVal << (index - 64));
	else
		throw "Error: Invalid index";
}

string Base_2::BitsToString() {// Return bits as string
	stringstream writer;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 64; ++j)
			writer << ((this->Bits[i] >> j) & int64_t(1));
	return writer.str();
}

bool Base_2::bitAt(uint8_t index) {
	if (0 <= int(index) && int(index) <= 63)// The first element contains bits from 1 -> 63
		return (this->Bits[0] << (63 - index)) & int64_t(1);
	else if (64 <= int(index) && int(index) <= 127)// The last element contains bits from 64 -> 127 
		return (this->Bits[1] << (63 - (index - 64))) & int64_t(1);
	else
		throw "Error: Invalid index";
}

Base_2 Base_2::ComplementOfOne() {
	Base_2 tmp = *this;
	for (int i = 0; i < 128; ++i)
		tmp.setBit(i, !tmp.bitAt(i));
	return tmp;
}


Base_2 Base_2::Negative() {
	Base_2 tmp = *this;

	if (this->bitAt(0) == true) {// Check sign bit, sign bit = 1 -> negative
		--tmp;
		tmp = tmp.ComplementOfOne();
	}
	else {
		tmp = tmp.ComplementOfOne();
		++tmp;
	}

	return tmp;
}

string Base_2::toDec() {

}

string Base_2::toBin() {
	stringstream writer;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 64; ++j)
			writer << ((this->Bits[i] >> j) & int64_t(1));
	return writer.str();
}

string Base_2::toHex() {
	string bits = this->BitsToString();
	stringstream writer;
	for (int i = 0; i < 128; i += 4) {
		string FourBits = bits.substr(i - 1, 4);// get sub string at i - 1 with length = 4
		writer << this->FourBitsToHex(FourBits);// convert 4 bits of sub string to hex value
	}
	return writer.str();
}

string Base_2::toString() {
	return this->BitsToString();
}

uint8_t Base_2::FourBitsToHex(string bits) {
	if (bits.length() != 4)
		throw "Error: Invalid length!";
	else {
		uint8_t value = 0;
		for (size_t i = 0; i < bits.length(); ++i) {
			if (bits[i] != '0' && bits[i] != '1')
				throw "Error: Invalid string";
			value += (bits[i] - '0') * powOfTwo(bits.length() - i - 1);// ASCII 0 not start at 48 so that we just - 48 then get int value
			if (0 <= value && value <= 9)
				return value;
			else {
				return value + ' ' - 1;// ASCII, character start at 41 with A, ' ' is 32, 10 + 32 - 1 = 41 = A, 11 + 32 - 1 = 42 = B
			}
		}
	}
}
//Operators-------------------------------------------------------------------------------------------------------------------
bool Base_2::lastBit() {
	return this->Bits[1] & int64_t(1);
}
Base_2& Base_2::operator++() {
	bool save = true;// Ex: 1 + 1 = 10, save = 1, 1 + 0 = 0 save 0

	for (int i = 127; i >= 0 && save; --i) {
		if (this->bitAt(i)) {// bit = 1
			this->setBit(i, 0);
			save = true;
		}
		else {// bit = 0
			this->setBit(i, 1);
			save = false;
		}
	}

	return *this;
}
Base_2& Base_2::operator--() {

}

Base_2 Base_2::operator++(int x) {
	Base_2 tmp = *this;
	++*this;
	return tmp;
}
Base_2 Base_2::operator--(int x) {

}