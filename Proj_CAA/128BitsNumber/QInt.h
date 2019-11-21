#pragma once
#include "pch.h"
#include "Type.h"

//QInt
class QInt {
private:
	int64_t Bits[2];
public:// Calculating operator
	QInt operator+(const QInt& num);// Normal
	QInt operator-(const QInt& num);// Normal
	QInt operator*(const QInt& num);// Hard
	QInt operator/(const QInt& num);// Extra Supper Hard
public:// Others operator
	QInt& operator++();
	QInt& operator--();
	QInt operator++(int x);// Fixed
	QInt operator--(int x);// Fixed
public:// Bitwise operator, All Ez
	QInt operator&(const QInt& num)const;
	QInt operator|(const QInt& num)const;
	QInt operator^(const QInt& num)const;
	QInt operator~()const;
public:// Shift operator
	QInt operator<<(int bits)const;// Normal
	QInt operator>>(int bits)const;// Ez
private:
	void moveLeft();
	void moveRight();
public:// Rolling operator
	QInt ROL();// Ez
	QInt ROR();// Ez
public:// Convert method
	string Dec();// Extra Supper Hard
	string Bin();// Modified, DKM EZ VKL
	string Hex();// Ez
public:// Some support method
	string BitsFrom(uint8_t startPos, uint8_t endPos);// New
	bool operator[](int index)const;// New
	void setBit(uint8_t index, bool value);// Set value for bit of index
	QInt ComplementOfOne()const;// Modified
	QInt Negative()const;// Return a two's complement number of its
	bool bitAt(uint8_t index)const;// Modified, Get bit at index
	bool lastBit();// Return last bit
	static char FourBitsToHex(string bits);// Converts 4 bits to Hex value
	static uint8_t CharToInt(char input);// Convert one char to int value 8 bit, 0 <= value <= 9
	static unsigned char IntToChar(uint8_t input);// 
	static string DecDiv(string val, uint8_t divided);
	static string HexToFourBits(unsigned char hex);
	static uint8_t TwoPower(uint8_t n);// 2^n up to 2^8
	static string AddTwoDec(string dec1, string dec2);
	static string DeleteAllZeroAtHead(string str);
	static string TwoPowerToSrting(uint8_t n);
	static string SumTwoStringNumber(string num1, string num2);
	static string SubTwoStringNumber(string num1, string num2);
	static string MulTwoStringNumber(string num1, string num2);
	static string MulStringWithNumber(string num , uint8_t muler);
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
	~QInt();
};
