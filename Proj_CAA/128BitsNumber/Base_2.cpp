#include "pch.h"
#include "Base_2.h"

//Big Three & construct--------------------------------------------------------------------------------------------------------
Base_2::Base_2(string bits) {
	this->Bits = new int64_t[2];
	for (size_t i = 0; i < bits.length(); ++i)
		this->setBit(i, CharToInt(bits[i]));
}

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

Base_2::Base_2(uint8_t inputType, string value) {

}

// Support method-------------------------------------------------------------------------------------------------------------
uint8_t Base_2::TwoPower(uint8_t n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else {
		if (n % 2 == 0)
			return Base_2::TwoPower(n / 2) * Base_2::TwoPower(n / 2);
		else
			return 2 * Base_2::TwoPower(n / 2) * Base_2::TwoPower(n / 2);
	}
}

void Base_2::setBit(uint8_t index, bool bitVal) {// Set value for bit of index 
	if (0 <= int(index) && int(index) <= 63) {// The first element - Bits[0] contains bits from 0 -> 63
		if (bitVal)// Bit = 1
			this->Bits[0] = this->Bits[0] | (bitVal << (63 - index));
		else {// Bit = 0
			int64_t a = int64_t(1) << (63 - index);
			this->Bits[0] = this->Bits[0] & (a ^ int64_t(-1));
		}
	}
	else if (64 <= int(index) && int(index) <= 127) {// The last element - Bist[1] contains bits from 64 -> 127 
		if (bitVal)// Bit = 1
			this->Bits[1] = this->Bits[1] | (bitVal << (63 - (index - 64)));
		else {// Bit = 0
			int64_t a = int64_t(1) << (63 - (index - 64));
			this->Bits[1] = this->Bits[1] & (a ^ int64_t(-1));
		}
	}
	else
		throw "Error: Invalid index";
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
	if (!this->bitAt(0)) // Fist bit = 0
		tmp = ~*this;// tmp = NOT(*this)
	return tmp;
}


Base_2 Base_2::Negative() {// Using Two's Complement
	Base_2 tmp = *this;

	if (this->bitAt(0)) {// Check sign bit, sign bit = 1 -> negative so that we need reverse step
		--tmp;
		tmp = ~tmp;// tmp = NOT(tmp)
	}
	else {
		tmp = tmp.ComplementOfOne();
		++tmp;
	}

	return tmp;
}

string Base_2::DecDiv(string val, uint8_t divided) {
	bool isNeg = false;
	if (divided >= TwoPower(8))
		throw "Error: Divided overflow!";
	if (val[0] == '-') {// Remove char '-'
		val = val.substr(1, val.length() - 1);
		isNeg = true;
	}
	string res;
	if ((isNeg && divided > 0) || (divided < 0 && !isNeg)) {// Check sign of res
		res.push_back('-');
	}
	uint8_t save = 0;
	for (auto it = val.begin(); it != val.end(); ++it) {
		uint8_t digit = 10 * save + Base_2::CharToInt(*it);
		if (digit / divided > 0) {
			save = digit % divided;
			digit = digit / divided;
			res.push_back(Base_2::IntToChar(digit));
		}
	}
	auto it = res.begin();
	while (*it == '0')
		res = res.substr(1, res.length() - 1);
	if (res == "")
		res = "0";
	return res;
}
//Convert---------------------------------------------------------------------------------------------------------------------
string Base_2::DecToBin(string dec) {
	string res;
	res.reserve();
	string::iterator it = dec.end() - 1;
	int i = 127;
	while (dec != "0") {
		bool bit = Base_2::CharToInt(*it) % 2;
		res.push_back(IntToChar(bit));
	}
	reverse(res.begin(), res.end());
	return res;
}

string Base_2::HexToBin(string hex) {
	string res;
	for (auto it = hex.begin(); it != hex.end(); ++it)
		res += Base_2::HexToFourBits(*it);
	return res;
}

string Base_2::Dec() {

}

string Base_2::Bin() {
	stringstream writer;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 64; ++j)
			writer << ((this->Bits[i] >> j) & int64_t(1));
	return writer.str();
}

string Base_2::Hex() {
	string bits = this->Bin();
	stringstream writer;
	for (int i = 0; i < 128; i += 4) {
		string FourBits = bits.substr(i - 1, 4);// get sub string at i - 1 with length = 4
		writer << this->FourBitsToHex(FourBits);// convert 4 bits of sub string to hex value
	}
	return writer.str();
}


uint8_t Base_2::CharToInt(unsigned char input) {
	if (input - '0' < 0 || input - '0' > 9)
		throw "Error: Invalid Char!";
	else
		return input - '0';// ASCII, 0 start at 48 so we need to subtract value by 48 to get int value
}

unsigned char Base_2::IntToChar(uint8_t input) {
	if (input < 0 || input > 9)
		throw "Error: Invalid	Int!";
	else
		return input + '0';
}

char Base_2::FourBitsToHex(string bits) {
	if (bits.length() != 4)
		throw "Error: Invalid length!";
	else {
		uint8_t value = 0;
		for (size_t i = 0; i < bits.length(); ++i) {
			if (bits[i] != '0' && bits[i] != '1')
				throw "Error: Invalid data";
			value += (Base_2::CharToInt(bits[i])) * Base_2::TwoPower(bits.length() - i - 1);
			if (0 <= value && value <= 9)
				return value;
			else {
				return value + ' ' - 1;// ASCII, character start at 41 with A, ' ' is 32, 10 + 32 - 1 = 41 = A, 11 + 32 - 1 = 42 = B
			}
		}
	}
}

string Base_2::HexToFourBits(unsigned char hex) {
	switch (hex) {
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	default: throw "Error: Invalid Input!";
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
	bool save = true;// Ex: 0 -  1 = 1, save = 1, 1 - 1 = 0 save 0

	for (int i = 127; i >= 0 && save; --i) {
		if (this->bitAt(i)) {// bit = 1
			this->setBit(i, 0);
			save = false;
		}
		else {// bit = 0
			this->setBit(i, 1);
			save = true;
		}
	}

	return *this;
}

Base_2 Base_2::operator++(int x) {
	Base_2 tmp = *this;
	++*this;
	return tmp;
}
Base_2 Base_2::operator--(int x) {
	Base_2 tmp = *this;
	--*this;
	return tmp;
}
//Bit Wise operator-----------------------------------------------------------------------------------------------------------
Base_2 Base_2::operator~() {
	Base_2 tmp = *this;
	for (int i = 0; i < 128; ++i)
		tmp.setBit(i, !tmp.bitAt(i));
	return tmp;
}