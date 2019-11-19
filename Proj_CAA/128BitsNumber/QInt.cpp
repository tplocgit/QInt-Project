#include "pch.h"
#include "QInt.h"

//Big Three & construct--------------------------------------------------------------------------------------------------------
QInt::QInt(string bits) {
	this->Bits = new int64_t[2];
	for (size_t i = 0; i < bits.length(); ++i)
		this->setBit(uint8_t(i), CharToInt(bits[i]));
}

QInt QInt::operator=(const QInt& num) {
	// Dellocate avaiable memory to avoid leaked
	if (this->Bits != nullptr)
		delete[] this->Bits;
	// Allocate new bits
	this->Bits = new int64_t[2];

	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];

	return *this;
}

QInt::QInt() {
	// Allocate two numbers of 64 bits to get 128 bits
	this->Bits = new int64_t[2];
	// Set 0 for 128 bit
	this->Bits[0] = 0;
	this->Bits[1] = 0;
}

QInt::QInt(const QInt& num) {
	// Dellocate avaiable memory to avoid leaked
	if (this->Bits != nullptr)
		delete[] this->Bits;
	// Allocate new bits
	this->Bits = new int64_t[2];

	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];
}

QInt::~QInt() {
	delete[] this->Bits;
}

QInt::QInt(BASE inputType, string value) {

	if (inputType == BINARY) { // Binary	
		QInt(value);
	}
	else if (inputType == DECIMAL) { // Dec	
		string bits = DecToBin(value);
		QInt::QInt(bits);
	}
	else if (inputType == HEXADECIMAL) {//Hex
		string bits = HexToBin(value);
		QInt::QInt(bits);
	}
	else throw "Error: Invalid input Type!";
}

// Support method-------------------------------------------------------------------------------------------------------------
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
	if (0 <= int(index) && int(index) <= 63) {// The first element - Bits[0] contains bits from 0 -> 63
		if (bitVal)// Bit = 1
			this->Bits[0] = this->Bits[0] | (int64_t(bitVal) << int64_t(63 - index));
		else {// Bit = 0
			int64_t a = int64_t(1) << int64_t(63 - index);
			this->Bits[0] = this->Bits[0] & (a ^ int64_t(-1));
		}
	}
	else if (64 <= int(index) && int(index) <= 127) {// The last element - Bist[1] contains bits from 64 -> 127 
		if (bitVal)// Bit = 1
			this->Bits[1] = this->Bits[1] | (int64_t(bitVal) << int64_t(63 - (int64_t(index) - 64)));
		else {// Bit = 0
			int64_t a = int64_t(1) << (63 - (index - 64));
			this->Bits[1] = this->Bits[1] & (a ^ int64_t(-1));
		}
	}
	else
		throw "Error: Invalid index";
}

bool QInt::bitAt(uint8_t index) const {
	if (0 <= int(index) && int(index) <= 63)// The first element contains bits from 1 -> 63
		return (this->Bits[0] << (63 - index)) & int64_t(1);
	else if (64 <= int(index) && int(index) <= 127)// The last element contains bits from 64 -> 127 
		return (this->Bits[1] << (63 - (index - 64))) & int64_t(1);
	else
		throw "Error: Invalid index";
}

QInt QInt::ComplementOfOne() {
	QInt tmp = *this;
	if (!this->bitAt(0)) // Fist bit = 0
		tmp = ~*this;// tmp = NOT(*this)
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
		uint8_t digit = 10 * save + QInt::CharToInt(*it);
		if (digit / divided > 0) {
			save = digit % divided;
			digit = digit / divided;
			res.push_back(QInt::IntToChar(digit));
		}
	}
	auto it = res.begin();
	while (*it == '0' && !res.empty()) {
		++it;
		res = res.substr(1, res.length() - 1);
	}
	if (res == "" || res == "-")
		res = "0";
	return res;
}
//Convert---------------------------------------------------------------------------------------------------------------------
string QInt::DecToBin(string dec) {
	string res;
	res.reserve();
	string::iterator it = dec.end() - 1;
	int i = 127;
	while (dec != "0") {
		bool bit = QInt::CharToInt(*it) % 2;
		res.push_back(IntToChar(bit));
		dec = QInt::DecDiv(dec, 2);
	}
	reverse(res.begin(), res.end());
	if (dec[0] = '-') {
		QInt tmp(res);
		res = tmp.Negative().Bin();
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
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 64; ++j)
			writer << ((this->Bits[i] >> j)& int64_t(1));
	return writer.str();
}

string QInt::Hex() {
	string bits = this->Bin();
	stringstream writer;
	for (int i = 0; i < 128; i += 4) {
		string FourBits = bits.substr(i - 1, 4);// get sub string at i - 1 with length = 4
		writer << this->FourBitsToHex(FourBits);// convert 4 bits of sub string to hex value
	}
	return writer.str();
}
//--------------------------------------------------------------------

uint8_t QInt::CharToInt(unsigned char input) {
	if (input - '0' < 0 || input - '0' > 9)
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
		uint8_t value = 0;
		for (size_t i = 0; i < bits.length(); ++i) {
			if (bits[i] != '0' && bits[i] != '1')
				throw "Error: Invalid data";
			value += (QInt::CharToInt(bits[i])) * QInt::TwoPower(uint8_t(bits.length() - i - size_t(1)));
		}
		if (value >= 16)
			throw "Error: Overflow!";
		if (value >= 10 && value <= 15) {
			return value + ' ' - 1;// ASCII, character start at 41 with A, ' ' is 32, 10 + 32 - 1 = 41 = A, 11 + 32 - 1 = 42 = B
		}
		return value;
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

QInt& QInt::operator--() {
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
QInt QInt::operator~() {
	QInt tmp = *this;
	for (int i = 0; i < 128; ++i)
		tmp.setBit(i, !tmp.bitAt(i));
	return tmp;
}

//-------------Datpt's part----------------------------------------------------
QInt QInt::operator+(const QInt& num) {// Normal
	QInt ans;
	bool save = 0;// Ex: 1 + 1 = 10, save = 1, 1 + 0 = 1 save 0

	for (int i = 127; i >= 0; --i) {
		if (ans.bitAt(i) == 1 && num.bitAt(i) == 1) {// bit = 1
			if (save)
				ans.setBit(i, 1);
			else
				ans.setBit(i, 0);
			save = 1;
		}
		else if (ans.bitAt(i) == 0 && num.bitAt(i) == 0) {
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
	QInt ans = *this;
	int count = 0;
	for (int i = 127; i > 0; --i) {
		if (num.bitAt(i) == 1)
			ans = ans + (num << count);
		++count;
	}
	return ans;
}

//-----------------------------------------------------------------

QInt QInt::ROL() {// Ez
	bool save = this->bitAt(0);
	for (int i = 0; i < 127; ++i) {
		this->setBit(i, this->bitAt(i + 1));
	}
	this->setBit(127, save);
	return *this;
}

QInt QInt::ROR() {// Ez
	bool save = this->bitAt(127);

	for (int i = 127; i > 0; --i) {
		this->setBit(i, this->bitAt(i - 1));
	}
	this->setBit(0, save);
	return *this;
}

//-----------------------------------------------------------------
/*
QInt QInt::operator&(const QInt& num)const {

}

QInt QInt::operator|(const QInt& num)const {

}

QInt QInt::operator^(const QInt& num)const {

}
*/
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
	for (int i = 0; i < 127; ++i) {
		this->setBit(i, this->bitAt(i + 1));
	}
	this->setBit(127, 0);
}
void QInt::moveRight() {
	//dịch số học 
	bool save = this->bitAt(0);
	for (int i = 127; i > 0; --i) {
		this->setBit(i, this->bitAt(i - 1));
	}
	this->setBit(0, save);
}