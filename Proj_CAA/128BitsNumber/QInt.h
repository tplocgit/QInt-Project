#pragma once
#include "Calculator.h"
#include "pch.h"
//QInt
class QInt {
private:
	int64_t* Bits;
public:// Calculating operator
	QInt operator+(const QInt& num);// Normal
	QInt operator-(const QInt& num);// Normal
	QInt operator*(const QInt& num);// Hard
	QInt operator/(const QInt& num);// Extra Supper Hard
public:// Others operator
	QInt& operator++();
	QInt& operator--();
	QInt operator++(int x);
	QInt operator--(int x);
public:// Bitwise operator, All Ez
	QInt operator&(const QInt& num)const;
	QInt operator|(const QInt& num)const;
	QInt operator^(const QInt& num)const;
	QInt operator~();
public:// Shift operator
	QInt operator<<(int bits);// Normal
	QInt operator>>(int bits);// Ez
private:
	
public:// Rolling operator
	QInt ROL();// Ez
	QInt ROR();// Ez
public:// Convert method
	string Dec();// Extra Supper Hard
	string Bin();// DKM EZ VKL
	string Hex();// Ez
public:// Some support method
	void setBit(uint8_t index, bool value);// Set value for bit of index
	QInt ComplementOfOne();
	QInt Negative()const;// Return a two's complement number of its
	bool bitAt(uint8_t index)const;// Get bit at index
	bool lastBit();// Return last bit
	static char FourBitsToHex(string bits);// Converts 4 bits to Hex value
	static uint8_t CharToInt(unsigned char input);// Convert one char to int value 8 bit, 0 <= value <= 9
	static unsigned char IntToChar(uint8_t input);// 
	static string DecDiv(string val, uint8_t divided);
	static string HexToFourBits(unsigned char hex);
	static uint8_t TwoPower(uint8_t n);// 2^n up to 2^8
	static string AddTwoDec(string dec1, string dec2);
public:// Read file
	static string DecToBin(string dec);// Hard
	static string HexToBin(string hex);// Ez
public:
	QInt(BASE inputType, string value);// For file reading
	QInt(string bits);
	// Big three
	QInt(const QInt& obj);
	QInt operator=(const QInt& obj);
	QInt();
	virtual ~QInt();
};
