#pragma once
#include"pch.h"
typedef unsigned char uint8_t;// unsigned int 8 bit 0 -> 255


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
	string toDec();// Extra Supper Hard
	string toBin();// DKM EZ VKL
	string toHex();// Ez
public:// Some support method
	void setBit(uint8_t index, bool value);// Set value for bit of index
	Base_2 ComplementOfOne();
	Base_2 Negative();// Return a two's complement number of its
	string BitsToString();// Return Bist as string
	virtual string toString();
	bool bitAt(uint8_t index);// Get bit at index
	bool lastBit();// Return last bit
	uint8_t FourBitsToHex(string bits);// Converts 4 bits to Hex value
	uint8_t CharToInt(unsigned char input);// Convert one char to int value 8 bit
public:// Read file
	string DecToBin(string dec);
	string HexToBin(string dec);// Ez
public:
	Base_2(uint16_t inputType, string value);// For file reading
	Base_2(string bits);// Ez
	// Big three
	Base_2 operator=(const Base_2& obj);
	Base_2();
	virtual ~Base_2();
};

uint8_t TwoPowerBy(uint8_t n);// 2^n up to 2^8