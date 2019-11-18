#pragma once
#include"pch.h"
//QInt
class Base_2 {
private:
	int64_t* Bits;
public:// Calculating operator
	Base_2 operator+(const Base_2& num);// Normal
	Base_2 operator-(const Base_2& num);// Normal
	Base_2 operator*(const Base_2& num);// Hard
	Base_2 operator/(const Base_2& num);// Extra Supper Hard
public:// Others operator
	Base_2& operator++();
	Base_2& operator--();
	Base_2 operator++(int x);
	Base_2 operator--(int x);
public:// Bitwise operator, All Ez
	Base_2 operator&(const Base_2& num)const;
	Base_2 operator|(const Base_2& num)const;
	Base_2 operator^(const Base_2& num)const;
	Base_2 operator~();
public:// Shift operator
	Base_2 operator<<(int bits);// Normal
	Base_2 operator>>(int bits);// Ez
public:// Ro operator
	Base_2 ROL();// Ez
	Base_2 ROR();// Ez
public:// Convert method
	string Dec();// Extra Supper Hard
	string Bin();// DKM EZ VKL
	string Hex();// Ez
public:// Some support method
	void setBit(uint8_t index, bool value);// Set value for bit of index
	Base_2 ComplementOfOne();
	Base_2 Negative();// Return a two's complement number of its
	bool bitAt(uint8_t index);// Get bit at index
	bool lastBit();// Return last bit
	static char FourBitsToHex(string bits);// Converts 4 bits to Hex value
	static uint8_t CharToInt(unsigned char input);// Convert one char to int value 8 bit, 0 <= value <= 9
	static unsigned char IntToChar(uint8_t input);// 
	static string DecDiv(string val, uint8_t divided);
	static string HexToFourBits(unsigned char hex);
	static uint8_t TwoPower(uint8_t n);// 2^n up to 2^8
public:// Read file
	static string DecToBin(string dec);// Hard
	static string HexToBin(string hex);// Ez
public:
	Base_2(uint8_t inputType, string value);// For file reading
	Base_2(string bits);
	// Big three
	Base_2 operator=(const Base_2& obj);
	Base_2();
	virtual ~Base_2();
};