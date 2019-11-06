#include "pch.h"
#include "NumBase.h"


NumBase::NumBase(){
	// Allocate two numbers of 64 bits to get 128 bits
	this->Bits = new int64_t[2];
	// Set 0 for 128 bit
	this->Bits[0] = 0;
	this->Bits[1] = 0;
}

NumBase::NumBase(const NumBase& num) {
	// Dellocate avaiable memory to avoid leaked
	if (this->Bits != nullptr)
		delete[] this->Bits;
	// Allocate new bits
	this->Bits = new int64_t[2];

	// Copy bits
	this->Bits[0] = num.Bits[0];
	this->Bits[1] = num.Bits[1];

}

NumBase::~NumBase(){
	delete[] this->Bits;
}
