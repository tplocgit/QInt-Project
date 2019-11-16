#pragma once
#include"pch.h"
typedef unsigned char uint8_t;// unsigned int 8 bit 0 -> 255


class Base_2 {
private:
	int64_t* Bits;
public:// Calculating operator
	Base_2 operator+(const Base_2& num);
	Base_2 operator-(const Base_2& num);
	Base_2 operator*(const Base_2& num);
	Base_2 operator/(const Base_2& num);
public:// Others operator
	Base_2& operator++();
	Base_2& operator--();
	Base_2 operator++(int x);
	Base_2 operator--(int x);
public:// Bitwise operator
	Base_2 operator&(const Base_2& num)const;
	Base_2 operator|(const Base_2& num)const;
	Base_2 operator^(const Base_2& num)const;
	Base_2 operator~();
public:// Shift operator
	Base_2 operator<<(int bits);
	Base_2 operator>>(int bits);
public:// Ro operator
	Base_2 ROL();
	Base_2 ROR();
public:// Convert method
	string toDec();
	string toBin();
	string toHex();
public:// Some support method
	void setBit(uint8_t index, bool value);// Set value for bit of index
	Base_2 ComplementOfOne();
	Base_2 Negative();// Return a two's complement number of its
	string BitsToString();// Return Bist as string
	virtual string toString();
	bool bitAt(uint8_t index);// Get bit at index
	bool lastBit();// Return last bit
	uint8_t FourBitsToHex(string bits);// Converts 4 bits to Hex value
public:
	Base_2(uint16_t inputType, string value);// For file reading
	
	// Big three
	Base_2 operator=(const Base_2& obj);
	Base_2();
	virtual ~Base_2();
};

uint8_t powOfTwo(uint8_t n);// 2^n up to 2^8