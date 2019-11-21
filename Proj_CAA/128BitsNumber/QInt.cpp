﻿#include "pch.h"
#include "QInt.h"

//Big Three & construct--------------------------------------------------------------------------------------------------------
QInt::QInt(string bits) {
	this->Bits[0] = 0;
	this->Bits[1] = 0;
	uint8_t bitIndex = 127;
	for (auto it = bits.rbegin(); it != bits.rend() && bitIndex >= 0; ++it, --bitIndex) {
		bool bit = CharToInt(*it);
		this->setBit(bitIndex, bit);
	}
}

QInt QInt::operator=(const QInt& num) {
	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];

	return *this;
}

QInt::QInt() {
	// Set 0 for 128 bit
	this->Bits[0] = 0;
	this->Bits[1] = 0;
}

QInt::QInt(const QInt& num) {
	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];
}

QInt::~QInt() {
	//
}

QInt::QInt(BASE inputType, string value) {

	if (inputType == BINARY) { // Binary	
		QInt tmp(value);
		*this = tmp;
	}
	else if (inputType == DECIMAL) { // Dec	
		string bits = DecToBin(value);
		QInt tmp(bits);
		*this = tmp;
	}
	else if (inputType == HEXADECIMAL) {//Hex
		string bits = HexToBin(value);
		QInt tmp(bits);
		*this = tmp;
	}
	else throw "Error: Invalid input Type!";
}

// Support method-------------------------------------------------------------------------------------------------------------

string QInt::DeleteAllZeroAtHead(string str) {
	auto it = str.begin();
	for (it; it != str.end() && *it == '0'; ++it);

	if (it == str.end())
		return "0";

	str.erase(str.begin(), it);

	return str;
}

string QInt::BitsFrom(uint8_t startPos, uint8_t endPos) {
	if (startPos < 0 || endPos >127)
		throw "Error: Out of range!";
	stringstream writer;
	for (uint8_t i = startPos; i <= endPos; ++i)
		writer << (*this)[i];
	return writer.str();
}

uint8_t QInt::TwoPower(uint8_t n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else {
		if (n % 2 == 0)
			return QInt::TwoPower(n / 2) * QInt::TwoPower(n / 2);
		else
			return 2 * QInt::TwoPower(n / 2) * QInt::TwoPower(n / 2);
	}
}

void QInt::setBit(uint8_t index, bool bitVal) {// Set value for bit of index 
	int64_t one = 1;
	int64_t negOne = int64_t(-1);
	int8_t shiftSize = 63 - index;
	int64_t rawBit = int64_t(bitVal);

	if (0 <= int(index) && int(index) <= 63) {// The first element - Bits[0] contains bits from 0 -> 63
		if (bitVal)// Bit = 1
			this->Bits[0] = this->Bits[0] | (rawBit << shiftSize);
		else {// Bit = 0
			int64_t shiftedOne = one << shiftSize;
			this->Bits[0] = this->Bits[0] & (shiftedOne ^ negOne);
		}
	}
	else if (64 <= int(index) && int(index) <= 127) {// The last element - Bist[1] contains bits from 64 -> 127 
		uint8_t newIndex = index - 64;
		shiftSize = 63 - newIndex;
		if (bitVal)// Bit = 1
			this->Bits[1] = this->Bits[1] | (rawBit << shiftSize);
		else {// Bit = 0
			int64_t shiftedOne = one << shiftSize;
			this->Bits[1] = this->Bits[1] & (shiftedOne ^ negOne);
		}
	}
	else
		throw "Error: Invalid index";
}

bool QInt::bitAt(uint8_t index) const {
	bool bit;
	bool partBits;
	uint8_t shiftSize;

	if (0 <= int(index) && int(index) <= 63) {// The first element contains bits from 1 -> 63
		partBits = 0;
		shiftSize = 63 - index;
	}
	else if (64 <= int(index) && int(index) <= 127) {// The last element contains bits from 64 -> 127 
		partBits = 1;
		uint8_t newIndex = index - 64;
		shiftSize = 63 - newIndex;
	}
	else
		throw "Error: Invalid index";
	bit = (this->Bits[partBits] >> shiftSize)& int64_t(1);
	return bit;
}

bool QInt::operator[](int index)const {// New
	return this->bitAt(index);
}
QInt QInt::ComplementOfOne()const {
	QInt tmp = *this;
	if (!(*this)[0]) // Fist bit = 0
		tmp = ~(*this);// tmp = NOT(*this)
	return tmp;
}


QInt QInt::Negative()const {// Using Two's Complement
	QInt tmp = *this;

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

string QInt::DecDiv(string val, uint8_t divided) {
	bool isNeg = false;
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
		uint8_t digit = 10 * save + QInt::CharToInt(*it);
		save = digit % divided;
		digit = digit / divided;
		res.push_back(QInt::IntToChar(digit));
	}
	size_t start = 0;
	if (res[start] == '-')
		++start;
	size_t end = start;
	while (res[end] == '0')
		++end;
	size_t count = end - start;
	res.erase(start, count);
	if (res == "" || res == "-")
		res = "0";
	return res;
}
//Convert---------------------------------------------------------------------------------------------------------------------
string QInt::DecToBin(string dec) {
	string res;
	bool Neg = false;

	if (dec[0] == '-')
		Neg = true;
	while (dec != "0") {
		bool bit = QInt::CharToInt(dec.back()) % 2;
		res.push_back(IntToChar(bit));
		dec = QInt::DecDiv(dec, 2);
	}
	reverse(res.begin(), res.end());
	if (Neg) {
		QInt tmp(res);
		tmp = tmp.Negative();
		res = tmp.Bin();
	}

	return res;
}

string QInt::HexToBin(string hex) {
	stringstream writer;
	for (auto it = hex.begin(); it != hex.end(); ++it)
		writer << QInt::HexToFourBits(*it);
	return writer.str();
}

string QInt::Dec() {
	return "";
}

string QInt::Bin() {
	stringstream writer;
	for (int i = 0; i < 128; ++i)
		writer << (*this)[i];
	return writer.str();
}

string QInt::Hex() {
	//cout << "To Hex\n";
	string bits = this->Bin();
	string hex;
	for (int i = 0; i < 128; i += 4) {
		string FourBits = bits.substr(i, 4);// get sub string at i - 1 with length = 4
		char hexChar = QInt::FourBitsToHex(FourBits);
		hex.push_back(hexChar);// convert 4 bits of sub string to hex value
	}
	return hex;
}
//--------------------------------------------------------------------

uint8_t QInt::CharToInt(char input) {
	if (input < '0' || input  > '9')
		throw "Error: Invalid Char!";
	else
		return input - '0';// ASCII, 0 start at 48 so we need to subtract value by 48 to get int value
}

unsigned char QInt::IntToChar(uint8_t input) {
	if (input < 0 || input > 9)
		throw "Error: Invalid	Int!";
	else
		return input + '0';
}

char QInt::FourBitsToHex(string bits) {
	if (bits.length() != 4)
		throw "Error: Invalid length!";
	else {
		char hexChar;
		uint8_t value = 0;
		for (size_t i = 0; i < bits.length(); ++i) {
			if (bits[i] != '0' && bits[i] != '1')
				throw "Error: Invalid data";
			bool bit = QInt::CharToInt(bits[i]);
			uint8_t exp = uint8_t(bits.length() - i - size_t(1));
			uint16_t mul = QInt::TwoPower(exp);
			value += bit * mul;
		}
		if (value > 15 || value < 0)
			throw "Error: Overflow!";
		if (value >= 10)
			hexChar = value + 'A' - 10;
		else
			hexChar = value + '0';
		return hexChar;
	}
}

string QInt::HexToFourBits(unsigned char hex) {
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

string QInt::AddTwoDec(string dec1, string dec2) {
	size_t len1 = dec1.length();
	size_t len2 = dec2.length();
	string res;
	bool save = false;
	while (len1 >= 0 || len2 >= 0 || save) {
		uint8_t dig = 0;
		if (len1 >= 0)
			dig += QInt::CharToInt(dec1[len1--]);
		if (len2 >= 0)
			dig += QInt::CharToInt(dec2[len2--]);
		dig += save;
		save = false;
		if (dig >= 10) {
			dig %= 10;
			save = true;
		}
		res.push_back(IntToChar(dig));
	}
	return res;
}
//Operators-------------------------------------------------------------------------------------------------------------------
bool QInt::lastBit() {
	return this->Bits[1] & int64_t(1);
}

QInt& QInt::operator++() {
	bool save = true;// Ex: 1 + 1 = 10, save = 1, 1 + 0 = 1 save 0

	for (int i = 127; i >= 0 && save; --i) {
		uint8_t dig = (*this)[i] + save;
		save = false;
		if (dig > 1) {
			save = true;
			dig = dig % 2;
		}
		this->setBit(i, dig);
	}

	return *this;
}

QInt& QInt::operator--() {
	bool borrow = true;

	for (int i = 127; i >= 0 && borrow; --i) {
		int8_t dig = (*this)[i] - borrow;
		borrow = false;
		if (dig < 0) {
			borrow = true;
			dig = -dig;
		}
		this->setBit(i, dig);
	}

	return *this;
}

QInt QInt::operator++(int x) {
	QInt tmp = *this;
	++* this;
	return tmp;
}

QInt QInt::operator--(int x) {
	QInt tmp = *this;
	--* this;
	return tmp;
}

//Bit Wise operator-----------------------------------------------------------------------------------------------------------
QInt QInt::operator~()const {
	QInt ans = *this;
	/*for (int i = 0; i < 128; ++i)
		tmp.setBit(i, !tmp[i]);*/

	ans.Bits[0] = ~(this->Bits[0]);
	ans.Bits[1] = ~(this->Bits[1]);
	return ans;
}

//-------------Datpt's part----------------------------------------------------
QInt QInt::operator+(const QInt& num) {// Normal
	QInt ans;
	bool save = 0;// Ex: 1 + 1 = 10, save = 1, 1 + 0 = 1 save 0

	for (int i = 127; i >= 0; --i) { 
		if (this->bitAt(i) == 1 && num.bitAt(i) == 1) {// bit = 1
			if (save)
				ans.setBit(i, 1);
			else
				ans.setBit(i, 0);
			save = 1;
		}
		else if (this->bitAt(i) == 0 && num.bitAt(i) == 0) {
			if (save)
				ans.setBit(i, 1);
			else
				ans.setBit(i, 0);
			save = 0;
		}
		else {// 1 - 0 or 0 - 1
			if (save) {
				ans.setBit(i, 0);
			}
			else {
				ans.setBit(i, 1);
			}
			//no need to modify 'save' in this case 
		}
	}
	//if (save == 1)
		//throw "Error: overflow";


	return ans;
}

QInt QInt::operator-(const QInt& num) {// Normal
	return *this + (num.Negative());
}

QInt QInt::operator*(const QInt& num) {// Hard
	QInt ans;
	for (int i = 127; i > 0; --i) {
		int shift = 127 - i;
		if (num.bitAt(i) == 1) {
			QInt tmp = (*this << shift);
			ans = (ans + tmp);
		}
	}
	return ans;
}

QInt QInt::operator/(const QInt& num) {// Extra Supper Hard
	return *this;
}
//-----------------------------------------------------------------

QInt QInt::ROL() {// Ez
	QInt res = *this;

	bool save = res.bitAt(0);
	for (int i = 0; i < 127; ++i) {
		res.setBit(i, res.bitAt(i + 1));
	}

	res.setBit(127, save);

	return res;
}

QInt QInt::ROR() {// Ez
	QInt res = *this;

	bool save = this->bitAt(127);

	for (int i = 127; i > 0; --i) {
		res.setBit(i, res.bitAt(i - 1));
	}

	res.setBit(0, save);

	return res;
}

QInt QInt::operator&(const QInt& num)const {
	QInt ans;
	/*for (int i = 127; i >= 0; --i) {
		ans.setBit(i, (this->bitAt(i) & num.bitAt(i)));
	}*/

	ans.Bits[0] = this->Bits[0] & num.Bits[0];
	ans.Bits[1] = this->Bits[1] & num.Bits[1];
	return ans;
}

QInt QInt::operator|(const QInt& num)const {
	QInt ans;
	ans.Bits[0] = this->Bits[0] | num.Bits[0];
	ans.Bits[1] = this->Bits[1] | num.Bits[1];
	return ans;
}

QInt QInt::operator^(const QInt& num)const {
	QInt ans;
	/*for (int i = 127; i >= 0; --i) {
		ans.setBit(i, (this->bitAt(i) ^ num.bitAt(i)));
	}*/

	ans.Bits[0] = this->Bits[0] ^ num.Bits[0];
	ans.Bits[1] = this->Bits[1] ^ num.Bits[1];
	return ans;
}

//-----------------------------------------------------------------
QInt QInt::operator<<(int bits)const {// Normal
	QInt ans = *this;
	while (bits > 0) {
		ans.moveLeft();
		--bits;
	}
	return ans;
}
QInt QInt::operator>>(int bits)const {// Ez
	QInt ans = *this;
	while (bits > 0) {
		ans.moveRight();
		--bits;
	}
	return ans;
}

void QInt::moveLeft() {
	for (int i = 0; i < 127; ++i)
		this->setBit(i, (*this)[i + 1]);
	this->setBit(127, 0);
}
void QInt::moveRight() {
	//dịch số học 
	/*bool save = this->bitAt(0);
	for (int i = 0; i < 127; ++i) {
		this->setBit(i + 1, this->bitAt(i));
	}
	this->setBit(0, save);
	*/
	bool save = this->bitAt(0);
	for (int i = 127; i > 0; --i)
		this->setBit(i, (*this)[i - 1]);
	this->setBit(0, save);
}