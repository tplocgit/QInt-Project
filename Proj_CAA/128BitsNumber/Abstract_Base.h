#pragma once
#include"pch.h"

class Abstract_Base{
public:// Set max min value as string here
	
private:
	int64_t* Bits;
public:// Calculating operator
	Abstract_Base* operator+(const Abstract_Base& num);
	Abstract_Base* operator-(const Abstract_Base& num);
	Abstract_Base* operator*(const Abstract_Base& num);
	Abstract_Base* operator/(const Abstract_Base& num);
public:// Bitwise operator
	Abstract_Base* operator&(const Abstract_Base& num)const;
	Abstract_Base* operator|(const Abstract_Base& num)const;
	Abstract_Base* operator^(const Abstract_Base& num)const;
	Abstract_Base* operator~();
public:// Shift operator
	Abstract_Base* operator<<(int bits);
	Abstract_Base* operator>>(int bits);
public:// Ro operator
	Abstract_Base* ROL();
	Abstract_Base* ROR();
public:// Convert method, if a num of base A convert to base A just copy it and return
	virtual Abstract_Base* toDec() = 0;
	virtual Abstract_Base* toBin() = 0;
	virtual Abstract_Base* toHex() = 0;
public:// Some support method
	void setBit(char index, bool value);
	Abstract_Base* Negative(const Abstract_Base& num) ;
	string BitsToString();
	virtual string toString() = 0;
public:
	Abstract_Base();
	Abstract_Base(const Abstract_Base& num);
	virtual ~Abstract_Base();
};

